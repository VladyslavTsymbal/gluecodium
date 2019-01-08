/*
 *
 * Automatically generated. Do not modify. Your changes will be lost.
 */
#include "smoke/Constructors.h"
#include "com_example_smoke_Constructors.h"
#include "CppProxyBase.h"
#include "FieldAccessMethods.h"
#include "JniBase.h"
#include "JniCppConversionUtils.h"
#include "InstanceConversion.h"
#include "StructConversion.h"
#include "ProxyConversion.h"
#include "EnumConversion.h"
#include "ArrayConversionUtils.h"
#include "JniReference.h"
extern "C" {
jlong
Java_com_example_smoke_Constructors_create__(JNIEnv* _jenv, jobject _jinstance)
{
    auto result = ::smoke::Constructors::create();
    auto nSharedPtr = new (::std::nothrow) ::std::shared_ptr< ::smoke::Constructors >(result);
    if (nSharedPtr == nullptr)
    {
        jclass exceptionClass = _jenv->FindClass("java/lang/RuntimeException" );
        _jenv->ThrowNew(exceptionClass, "Cannot allocate native memory.");
        _jenv->DeleteLocalRef(exceptionClass);
        return 0;
    }
    return reinterpret_cast<jlong>(nSharedPtr);
}
jlong
Java_com_example_smoke_Constructors_create__Lcom_example_smoke_Constructors_2(JNIEnv* _jenv, jobject _jinstance, jobject jother)
{
    ::std::shared_ptr< ::smoke::Constructors > other = genium::jni::convert_from_jni( _jenv, genium::jni::make_local_ref(_jenv, jother), (::std::shared_ptr< ::smoke::Constructors >*)nullptr );
    auto result = ::smoke::Constructors::create(other);
    auto nSharedPtr = new (::std::nothrow) ::std::shared_ptr< ::smoke::Constructors >(result);
    if (nSharedPtr == nullptr)
    {
        jclass exceptionClass = _jenv->FindClass("java/lang/RuntimeException" );
        _jenv->ThrowNew(exceptionClass, "Cannot allocate native memory.");
        _jenv->DeleteLocalRef(exceptionClass);
        return 0;
    }
    return reinterpret_cast<jlong>(nSharedPtr);
}
jlong
Java_com_example_smoke_Constructors_create__Ljava_lang_String_2J(JNIEnv* _jenv, jobject _jinstance, jstring jfoo, jlong jbar)
{
    ::std::string foo = genium::jni::convert_from_jni( _jenv, genium::jni::make_local_ref(_jenv, jfoo), (::std::string*)nullptr );
    uint64_t bar = jbar;
    auto result = ::smoke::Constructors::create(foo,bar);
    auto nSharedPtr = new (::std::nothrow) ::std::shared_ptr< ::smoke::Constructors >(result);
    if (nSharedPtr == nullptr)
    {
        jclass exceptionClass = _jenv->FindClass("java/lang/RuntimeException" );
        _jenv->ThrowNew(exceptionClass, "Cannot allocate native memory.");
        _jenv->DeleteLocalRef(exceptionClass);
        return 0;
    }
    return reinterpret_cast<jlong>(nSharedPtr);
}
jlong
Java_com_example_smoke_Constructors_create__Ljava_lang_String_2(JNIEnv* _jenv, jobject _jinstance, jstring jinput)
{
    ::std::string input = genium::jni::convert_from_jni( _jenv, genium::jni::make_local_ref(_jenv, jinput), (::std::string*)nullptr );
    auto nativeCallResult = ::smoke::Constructors::create(input);
    auto errorCode = nativeCallResult.error();
    if (!nativeCallResult.has_value())
    {
        auto nEnumValue = static_cast<::smoke::Constructors::ErrorEnum>(errorCode.value());
        auto jEnumValue = genium::jni::convert_to_jni(_jenv, nEnumValue);
        auto exceptionClass = genium::jni::find_class(_jenv, "com/example/smoke/Constructors$ErrorEnumException");
        auto theConstructor = _jenv->GetMethodID(exceptionClass.get(), "<init>", "(Lcom/example/smoke/Constructors$ErrorEnum;)V");
        auto exception = genium::jni::new_object(_jenv, exceptionClass, theConstructor, jEnumValue);
        _jenv->Throw(static_cast<jthrowable>(exception.release()));
        return 0;
    }
    auto result = nativeCallResult.safe_value();
    auto nSharedPtr = new (::std::nothrow) ::genium::Return< ::std::shared_ptr< ::smoke::Constructors >, ::std::error_code >(result);
    if (nSharedPtr == nullptr)
    {
        jclass exceptionClass = _jenv->FindClass("java/lang/RuntimeException" );
        _jenv->ThrowNew(exceptionClass, "Cannot allocate native memory.");
        _jenv->DeleteLocalRef(exceptionClass);
        return 0;
    }
    return reinterpret_cast<jlong>(nSharedPtr);
}
void
Java_com_example_smoke_Constructors_disposeNativeHandle(JNIEnv* _jenv, jobject _jinstance, jlong _jpointerRef)
{
    delete reinterpret_cast<std::shared_ptr<::smoke::Constructors>*> (_jpointerRef);
}
}