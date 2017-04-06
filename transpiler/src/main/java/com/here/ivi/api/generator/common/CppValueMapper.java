package com.here.ivi.api.generator.common;

import com.here.ivi.api.generator.common.templates.CppConstantTemplate;
import com.here.ivi.api.model.DefinedBy;
import com.here.ivi.api.model.cppmodel.*;
import com.here.ivi.api.model.cppmodel.CppValue;
import org.franca.core.franca.*;

import java.math.BigInteger;
import java.util.logging.Logger;

// TODO this whole thing should be more abstract, needed for more than one language
// First do the logic mapping to JavaTypes that support validation and other things
// Then translate into target language
public class CppValueMapper {

    static Logger logger = java.util.logging.Logger.getLogger(CppValueMapper.class.getName());

    public static CppValue map(CppType type, FInitializerExpression rhs) {
        if (rhs instanceof FCompoundInitializer) {
            return map(type, (FCompoundInitializer)rhs);
        }
        if (rhs instanceof FQualifiedElementRef) {
            return map(type, (FQualifiedElementRef)rhs);
        }

        return map(rhs);
    }

    public static CppValue map(FInitializerExpression rhs) {
        if (rhs instanceof FBooleanConstant) {
            return map((FBooleanConstant)rhs);
        } else if (rhs instanceof FIntegerConstant) {
            return map((FIntegerConstant)rhs);
        } else if (rhs instanceof FStringConstant) {
            return map((FStringConstant)rhs);
        } else if (rhs instanceof FFloatConstant) {
            return map((FFloatConstant)rhs);
        } else if (rhs instanceof FDoubleConstant) {
            return map((FDoubleConstant)rhs);
        } else if (rhs instanceof FUnaryOperation) {
            return map((FUnaryOperation)rhs);
        }

        return new CppValue();
    }

    private static CppValue map(FUnaryOperation rhs) {
        CppValue base = map(rhs.getOperand());
        // luckily all the operators look the same as in cpp, still 90% do not make much sense
        return new CppValue(rhs.getOp().getLiteral() + base.name);
    }

    public static CppValue map(FBooleanConstant bc) {
        final String value = bc.isVal() ? "true" : "false";
        return new CppValue(value);
    }

    public static CppValue map(FStringConstant sc) {
        final String value = sc.getVal();
        return new CppValue('"' + value + '"');
    }

    public static CppValue map(FIntegerConstant ic) {
        final BigInteger value = ic.getVal();
        return new CppValue(String.valueOf(value));
    }

    public static CppValue map(FFloatConstant fc) {
        final Float value = fc.getVal();
        return new CppValue(String.valueOf(value) + 'f');
    }

    public static CppValue map(FDoubleConstant dc) {
        final Double value = dc.getVal();
        return new CppValue(String.valueOf(value));
    }

    public static CppValue map(CppType type, FCompoundInitializer ci) {
        // FIXME having a template in here is not-so-nice, this should be some CppType
        return new CppValue(CppConstantTemplate.generate(type, ci).toString());
    }

    // TODO move to shared Helper with CppTypeMapper
    static final private String BUILTIN_MODEL = "navigation.BuiltIn";
    static final private String FLOAT_MAX_CONSTANT = "MaxFloat";
    static final private String FLOAT_NAN_CONSTANT = "NaNFloat";
    static final private String DOUBLE_NAN_CONSTANT = "NaNDouble";


    public static CppValue map(CppType type, FQualifiedElementRef dc) {

        if (dc.getElement() == null) {
            // TODO improve error output as seen in TypeMapper
            logger.severe("Failed resolving value reference");
            return new CppValue();
        }

        DefinedBy referenceDefiner = DefinedBy.getDefinedBy(dc.getElement());
        String name = dc.getElement().getName();
        String result = name;

        // check for built-in types
        if (BUILTIN_MODEL.equals(referenceDefiner.toString())) {
            switch (name){
                case FLOAT_MAX_CONSTANT:
                    result = "std::numeric_limits< float >::max( )";
                    break;
                case FLOAT_NAN_CONSTANT:
                    result = "std::numeric_limits< float >::quiet_NaN( )";
                    break;
                case DOUBLE_NAN_CONSTANT:
                    result = "std::numeric_limits< double >::quiet_NaN( )";
                    break;
            }
        //non built-in types (atm just default constructor of complex type)
        }else{
            if (type.info == CppElements.TypeInfo.Complex && CppValue.DefaultValueString.equals(name)) {
              return CppValue.DefaultValue;
            }
        }
        // TODO handle includes and namespaces here as well
        // just use the name of the type, missing ns resolution & includes
        return new CppValue(result);
    }
}
