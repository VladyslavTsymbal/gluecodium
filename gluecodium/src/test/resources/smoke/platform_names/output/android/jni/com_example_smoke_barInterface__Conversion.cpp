/*

 *
 */

#include "com_example_smoke_barInterface__Conversion.h"
#include "CppProxyBase.h"
#include "FieldAccessMethods.h"
#include "JniClassCache.h"
#include "JniThrowNewException.h"
#include "JniWrapperCache.h"
#include <new>

namespace gluecodium
{
namespace jni
{

REGISTER_JNI_CLASS_CACHE("com/example/smoke/barInterface", com_example_smoke_barInterface, ::smoke::fooInterface)



std::shared_ptr<::smoke::fooInterface> convert_from_jni(JNIEnv* _env, const JniReference<jobject>& _jobj, std::shared_ptr<::smoke::fooInterface>*)
{
    std::shared_ptr<::smoke::fooInterface> _nresult{};
    auto& nativeBaseClass = get_cached_native_base_class();
    if (_env->IsInstanceOf(_jobj.get(), nativeBaseClass.get()))
    {
        if (_jobj != nullptr)
        {
            auto long_ptr = get_field_value(
                _env,
                _jobj,
                "nativeHandle",
                (int64_t*)nullptr);
            _nresult = *reinterpret_cast<std::shared_ptr<::smoke::fooInterface>*>(long_ptr);
        }
    }
    else
    {
        createCppProxy(_env, _jobj, _nresult);
    }
    return _nresult;
}

JniReference<jobject>
convert_to_jni(JNIEnv* _jenv, const std::shared_ptr<::smoke::fooInterface>& _ninput)
{
    if ( !_ninput )
    {
        return {};
    }

    auto jResult = ::gluecodium::jni::CppProxyBase::getJavaObject(_jenv, _ninput.get());
    if (jResult) return jResult;

    jResult = ::gluecodium::jni::JniWrapperCache::get_cached_wrapper(_jenv, _ninput);
    if (jResult) return jResult;

    auto &javaClass = CachedJavaClass<::smoke::fooInterface>::java_class;
    auto pInstanceSharedPointer = new (::std::nothrow) std::shared_ptr<::smoke::fooInterface>(_ninput);
    if ( pInstanceSharedPointer == nullptr )
    {
        throw_new_out_of_memory_exception(_jenv);
    }
    jResult = ::gluecodium::jni::create_instance_object(
        _jenv, javaClass, reinterpret_cast<jlong>( pInstanceSharedPointer ) );
    ::gluecodium::jni::JniWrapperCache::cache_wrapper(_jenv, _ninput, jResult);

    return jResult;
}

}
}
