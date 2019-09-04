/*
 *

 */
#include "smoke/StructsWithMethodsInterface.h"
#include "CppProxyBase.h"
#include "FieldAccessMethods.h"
#include "JniBase.h"
#include "JniCppConversionUtils.h"
#include "com_example_smoke_StructsWithMethodsInterface.h"
#include "com_example_smoke_StructsWithMethodsInterface_Vector3.h"
#include "ArrayConversionUtils.h"
#include "EnumConversion.h"
#include "EnumSetConversion.h"
#include "InstanceConversion.h"
#include "StructConversion.h"
#include "ProxyConversion.h"
#include "JniReference.h"
extern "C" {
jdouble
Java_com_example_smoke_StructsWithMethodsInterface_00024Vector3_distanceTo(JNIEnv* _jenv, jobject _jinstance, jobject jother)
{
    ::smoke::StructsWithMethodsInterface::Vector3 other = ::genium::jni::convert_from_jni(_jenv,
            ::genium::jni::make_non_releasing_ref(jother),
            (::smoke::StructsWithMethodsInterface::Vector3*)nullptr);
    auto _ninstance = ::genium::jni::convert_from_jni(_jenv,
        ::genium::jni::make_non_releasing_ref(_jinstance),
        (::smoke::StructsWithMethodsInterface::Vector3*)nullptr);
    auto result = _ninstance.distance_to(other);
    return result;
}
jobject
Java_com_example_smoke_StructsWithMethodsInterface_00024Vector3_add(JNIEnv* _jenv, jobject _jinstance, jobject jother)
{
    ::smoke::StructsWithMethodsInterface::Vector3 other = ::genium::jni::convert_from_jni(_jenv,
            ::genium::jni::make_non_releasing_ref(jother),
            (::smoke::StructsWithMethodsInterface::Vector3*)nullptr);
    auto _ninstance = ::genium::jni::convert_from_jni(_jenv,
        ::genium::jni::make_non_releasing_ref(_jinstance),
        (::smoke::StructsWithMethodsInterface::Vector3*)nullptr);
    auto result = _ninstance.add(other);
    return ::genium::jni::convert_to_jni(_jenv, result).release();
}
jboolean
Java_com_example_smoke_StructsWithMethodsInterface_00024Vector3_validate(JNIEnv* _jenv, jobject _jinstance, jdouble jx, jdouble jy, jdouble jz)
{
    double x = jx;
    double y = jy;
    double z = jz;
    auto result = ::smoke::StructsWithMethodsInterface::Vector3::validate(x,y,z);
    return result;
}
jobject
Java_com_example_smoke_StructsWithMethodsInterface_00024Vector3_create__Ljava_lang_String_2(JNIEnv* _jenv, jobject _jinstance, jstring jinput)
{
    ::std::string input = ::genium::jni::convert_from_jni(_jenv,
            ::genium::jni::make_non_releasing_ref(jinput),
            (::std::string*)nullptr);
    auto result = ::smoke::StructsWithMethodsInterface::Vector3::create(input);
    return ::genium::jni::convert_to_jni(_jenv, result).release();
}
jobject
Java_com_example_smoke_StructsWithMethodsInterface_00024Vector3_create__Lcom_example_smoke_StructsWithMethodsInterface_00024Vector3_2(JNIEnv* _jenv, jobject _jinstance, jobject jother)
{
    ::smoke::StructsWithMethodsInterface::Vector3 other = ::genium::jni::convert_from_jni(_jenv,
            ::genium::jni::make_non_releasing_ref(jother),
            (::smoke::StructsWithMethodsInterface::Vector3*)nullptr);
    auto nativeCallResult = ::smoke::StructsWithMethodsInterface::Vector3::create(other);
    auto errorCode = nativeCallResult.error();
    if (!nativeCallResult.has_value())
    {
        auto nEnumValue = static_cast<::smoke::ValidationError>(errorCode.value());
        auto jEnumValue = ::genium::jni::convert_to_jni(_jenv, nEnumValue);
        auto exceptionClass = ::genium::jni::find_class(_jenv, "com/example/smoke/ValidationErrorException");
        auto theConstructor = _jenv->GetMethodID(exceptionClass.get(), "<init>", "(Lcom/example/smoke/ValidationError;)V");
        auto exception = ::genium::jni::new_object(_jenv, exceptionClass, theConstructor, jEnumValue);
        _jenv->Throw(static_cast<jthrowable>(exception.release()));
        return nullptr;
    }
    auto result = nativeCallResult.unsafe_value();
    return ::genium::jni::convert_to_jni(_jenv, result).release();
}
}