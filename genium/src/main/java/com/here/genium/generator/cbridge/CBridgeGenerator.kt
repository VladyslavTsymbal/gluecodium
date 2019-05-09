/*
 * Copyright (C) 2016-2019 HERE Europe B.V.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 * License-Filename: LICENSE
 */

package com.here.genium.generator.cbridge

import com.google.common.annotations.VisibleForTesting
import com.here.genium.generator.cbridge.CBridgeNameRules.CBRIDGE_PUBLIC
import com.here.genium.generator.cbridge.CBridgeNameRules.INCLUDE_DIR
import com.here.genium.generator.cbridge.CBridgeNameRules.SRC_DIR
import com.here.genium.generator.common.GeneratedFile
import com.here.genium.generator.common.modelbuilder.LimeTreeWalker
import com.here.genium.generator.common.templates.TemplateEngine
import com.here.genium.generator.cpp.CppIncludeResolver
import com.here.genium.generator.cpp.CppModelBuilder
import com.here.genium.generator.cpp.CppNameResolver
import com.here.genium.generator.cpp.CppTypeMapper
import com.here.genium.generator.swift.SwiftModelBuilder
import com.here.genium.generator.swift.SwiftNameResolver
import com.here.genium.generator.swift.SwiftTypeMapper
import com.here.genium.model.cbridge.CBridgeIncludeResolver
import com.here.genium.model.cbridge.CInterface
import com.here.genium.model.common.Include
import com.here.genium.model.lime.LimeContainer
import com.here.genium.model.lime.LimeElement
import com.here.genium.model.lime.LimeSignatureResolver
import com.here.genium.platform.common.GeneratorSuite
import java.nio.file.Paths

class CBridgeGenerator(
    private val limeReferenceMap: Map<String, LimeElement>,
    private val cppIncludeResolver: CppIncludeResolver,
    private val includeResolver: CBridgeIncludeResolver,
    private val cppNameResolver: CppNameResolver,
    private val internalNamespace: List<String>
) {
    private val signatureResolver = LimeSignatureResolver(limeReferenceMap)
    private val nameResolver = SwiftNameResolver(limeReferenceMap)
    private val swiftTypeMapper = SwiftTypeMapper(nameResolver)

    val arrayGenerator = CArrayGenerator(internalNamespace)

    fun generate(limeContainer: LimeContainer): List<GeneratedFile> {
        val cModel = buildCBridgeModel(limeContainer)
        return listOf(
            GeneratedFile(
                generateHeaderContent(cModel),
                includeResolver.getHeaderFileNameWithPath(limeContainer)
            ),
            GeneratedFile(
                generateImplementationContent(cModel),
                includeResolver.getImplementationFileNameWithPath(limeContainer)
            )
        ).filterNot { it.content.isEmpty() }
    }

    fun generateHelpers() =
        listOf(
            generateHelperContent("BaseHandleImpl", CBridgeNameRules.BASE_HANDLE_IMPL_FILE),
            generateHelperContent(
                "StringHandle", Paths.get(CBRIDGE_PUBLIC, SRC_DIR, "StringHandle.cpp").toString()),
            generateHelperContent(
                "ByteArrayHandle",
                Paths.get(CBRIDGE_PUBLIC, SRC_DIR, "ByteArrayHandle.cpp").toString()
            ),
            generateHelperContent(
                "DateHandle",
                Paths.get(CBRIDGE_PUBLIC, SRC_DIR, "DateHandle.cpp").toString()
            ),
            generateHelperContent(
                "BuiltinHandle",
                Paths.get(CBRIDGE_PUBLIC, SRC_DIR, "BuildintHandle.cpp").toString()
            )
        )

    private fun generateHelperContent(template: String, path: String): GeneratedFile {
        val content = TemplateEngine.render(
            "cbridge/$template",
            mapOf("internalNamespace" to internalNamespace)
        )
        return GeneratedFile(content, path)
    }

    private fun buildCBridgeModel(limeContainer: LimeContainer): CInterface {
        val cppTypeMapper = CppTypeMapper(cppNameResolver, cppIncludeResolver, internalNamespace)
        val cppBuilder = CppModelBuilder(cppTypeMapper, cppNameResolver)
        val swiftBuilder =
            SwiftModelBuilder(limeReferenceMap, signatureResolver, nameResolver, swiftTypeMapper)
        val typeMapper = CBridgeTypeMapper(
            cppIncludeResolver,
            cppNameResolver,
            includeResolver,
            cppTypeMapper.enumHashType.name
        )

        val modelBuilder = CBridgeModelBuilder(
            limeReferenceMap,
            includeResolver,
            cppIncludeResolver,
            cppBuilder,
            swiftBuilder,
            typeMapper,
            internalNamespace
        )
        val treeWalker = LimeTreeWalker(listOf(cppBuilder, swiftBuilder, modelBuilder))

        treeWalker.walkTree(limeContainer)
        val cModel = modelBuilder.getFinalResult(CInterface::class.java)

        removeRedundantIncludes(limeContainer, cModel)
        arrayGenerator.collect(modelBuilder.arraysCollector)

        return cModel
    }

    private fun removeRedundantIncludes(limeContainer: LimeContainer, cModel: CInterface) {
        cModel.headerIncludes.remove(
            Include.createInternalInclude(
                includeResolver.getHeaderFileNameWithPath(limeContainer)
            )
        )
        cModel.implementationIncludes.removeAll(cModel.headerIncludes)
        cModel.privateHeaderIncludes.removeAll(cModel.headerIncludes)
    }

    companion object {
        val STATIC_FILES = listOf(
            GeneratorSuite.copyTarget(CBridgeNameRules.BASE_HANDLE_FILE, ""),
            GeneratorSuite.copyTarget(CBridgeNameRules.STRING_HANDLE_FILE, ""),
            GeneratorSuite.copyTarget(CBridgeNameRules.DATE_HANDLE_FILE, ""),
            GeneratorSuite.copyTarget(CBridgeNameRules.EXPORT_FILE, ""),
            GeneratorSuite.copyTarget(
                Paths.get(CBRIDGE_PUBLIC, INCLUDE_DIR, "BuiltinHandle.h").toString(), ""
            ),
            GeneratorSuite.copyTarget(
                Paths.get(CBRIDGE_PUBLIC, INCLUDE_DIR, "ByteArrayHandle.h").toString(), ""
            ),
            GeneratorSuite.copyTarget(CBridgeComponents.PROXY_CACHE_FILENAME, "")
        )

        @VisibleForTesting
        fun generateHeaderContent(model: CInterface) =
            TemplateEngine.render("cbridge/Header", model)

        @VisibleForTesting
        fun generateImplementationContent(model: CInterface) =
            TemplateEngine.render("cbridge/Implementation", model)
    }
}