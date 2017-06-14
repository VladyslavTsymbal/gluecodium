/*
 * Copyright (C) 2017 HERE Global B.V. and its affiliate(s). All rights reserved.
 *
 * This software, including documentation, is protected by copyright controlled by
 * HERE Global B.V. All rights are reserved. Copying, including reproducing, storing,
 * adapting or translating, any or all of this material requires the prior written
 * consent of HERE Global B.V. This material also contains confidential information,
 * which may not be disclosed to others without prior written consent of HERE Global B.V.
 *
 */

package com.here.ivi.api.generator.swift

// TODO use own objective-c comment parser
import static extension com.here.ivi.api.generator.baseapi.StubCommentParser.parse
import static extension com.here.ivi.api.generator.swift.templates.SwiftFileTemplate.generate
import static extension com.here.ivi.api.generator.swift.SwiftTypeMapper.mappedType
import static extension com.here.ivi.api.generator.swift.SwiftTypeMapper.mappedReturnValue
import com.here.ivi.api.generator.common.GeneratedFile
import com.here.ivi.api.generator.common.GeneratorSuite
import com.here.ivi.api.model.swift.SwiftClass
import com.here.ivi.api.model.swift.SwiftMethod
import com.here.ivi.api.model.swift.SwiftMethodParameter
import static java.util.stream.Collectors.toList;
import com.here.ivi.api.model.Interface
import java.util.List
import navigation.BaseApiSpec
import org.franca.core.franca.FMethod

class SwiftGenerator {

    extension SwiftNameRules nameRules
    SwiftIncludeResolver includeResolver
    GeneratorSuite generatorSuite

    new(GeneratorSuite suite, SwiftNameRules rules, SwiftIncludeResolver resolver) {
        nameRules = rules
        includeResolver = resolver
        generatorSuite = suite
    }

    def List<GeneratedFile> generate(Interface<BaseApiSpec.InterfacePropertyAccessor> iface) {
        return #[new GeneratedFile(iface.buildSwiftModel.generate, iface.getFileName)]
    }

    protected def buildSwiftModel(Interface<?> iface) {
        val propertyAccessor = iface.getPropertyAccessor
        val clazz = iface.getFrancaInterface
        return new SwiftClass(clazz.getClassName) => [
            comment = clazz.parse.getMainBodyText() ?: ""
            methods = clazz.getMethods.stream.map([constructMethod(propertyAccessor)]).collect(toList)
        ]
    }

    private def constructMethod(FMethod method, extension BaseApiSpec.InterfacePropertyAccessor propertyAccessor) {
        val parameters = method.getInArgs.stream
            .map([param | new SwiftMethodParameter(param.getParameterName, param.mappedType)])
            .collect(toList)
        return new SwiftMethod(method.getMethodName, parameters) => [
            returnType = method.mappedReturnValue
            comment = method.parse.getMainBodyText ?: ""
            isStatic = method.getStatic
        ]
    }
}
