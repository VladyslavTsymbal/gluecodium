/*
 * Copyright (C) 2016-2020 HERE Europe B.V.
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

package com.here.gluecodium.generator.common

import com.here.gluecodium.common.LimeTypeRefsVisitor
import com.here.gluecodium.model.lime.LimeAttributeType
import com.here.gluecodium.model.lime.LimeAttributeValueType.SKIP
import com.here.gluecodium.model.lime.LimeGenericType
import com.here.gluecodium.model.lime.LimeList
import com.here.gluecodium.model.lime.LimeMap
import com.here.gluecodium.model.lime.LimeNamedElement
import com.here.gluecodium.model.lime.LimeSet
import com.here.gluecodium.model.lime.LimeType
import com.here.gluecodium.model.lime.LimeTypeRef

internal class GenericTypesCollector(
    private val sortingKeyMapper: (LimeGenericType) -> String,
    private val platformAttributeType: LimeAttributeType
) : LimeTypeRefsVisitor<List<LimeGenericType>>() {

    fun getAllGenericTypes(allTypes: List<LimeType>) =
        traverseTypes(allTypes).flatten()
            .filterNot { it.attributes.have(platformAttributeType, SKIP) }
            .associateBy(sortingKeyMapper)
            .toSortedMap()
            .values
            .toList()

    override fun visitTypeRef(parentElement: LimeNamedElement, limeTypeRef: LimeTypeRef?): List<LimeGenericType> {
        val limeType = limeTypeRef?.type?.actualType as? LimeGenericType ?: return emptyList()
        return listOf(limeType) + when (limeType) {
            is LimeList -> visitTypeRef(parentElement, limeType.elementType)
            is LimeSet -> visitTypeRef(parentElement, limeType.elementType)
            is LimeMap -> visitTypeRef(parentElement, limeType.keyType) +
                    visitTypeRef(parentElement, limeType.valueType)
            else -> emptyList()
        }
    }
}
