#pragma once
#include "Export.h"
#include "OpaqueHandle.h"
#include "dart_api_dl.h"
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_deconfuse__String_Confuser(FfiOpaqueHandle _self, int32_t _isolate_id, FfiOpaqueHandle value, FfiOpaqueHandle confuser);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_fuse__ListOf_String_Indexer(int32_t _isolate_id, FfiOpaqueHandle items, FfiOpaqueHandle callback);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Producer_call(FfiOpaqueHandle _self, int32_t _isolate_id);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Confuser_call__String(FfiOpaqueHandle _self, int32_t _isolate_id, FfiOpaqueHandle p0);
_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_Consumer_call__String(FfiOpaqueHandle _self, int32_t _isolate_id, FfiOpaqueHandle p0);
_GLUECODIUM_FFI_EXPORT int32_t library_smoke_Lambdas_Indexer_call__String_Float(FfiOpaqueHandle _self, int32_t _isolate_id, FfiOpaqueHandle p0, float p1);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_NullableConfuser_call__String_(FfiOpaqueHandle _self, int32_t _isolate_id, FfiOpaqueHandle p0);
_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_register_finalizer(FfiOpaqueHandle ffi_handle, int32_t isolate_id, Dart_Handle dart_handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_copy_handle(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_release_handle(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_Producer_register_finalizer(FfiOpaqueHandle ffi_handle, int32_t isolate_id, Dart_Handle dart_handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Producer_copy_handle(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_Producer_release_handle(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Producer_create_handle_nullable(FfiOpaqueHandle value);
_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_Producer_release_handle_nullable(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Producer_get_value_nullable(FfiOpaqueHandle handle);_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_Confuser_register_finalizer(FfiOpaqueHandle ffi_handle, int32_t isolate_id, Dart_Handle dart_handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Confuser_copy_handle(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_Confuser_release_handle(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Confuser_create_handle_nullable(FfiOpaqueHandle value);
_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_Confuser_release_handle_nullable(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Confuser_get_value_nullable(FfiOpaqueHandle handle);_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_Consumer_register_finalizer(FfiOpaqueHandle ffi_handle, int32_t isolate_id, Dart_Handle dart_handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Consumer_copy_handle(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_Consumer_release_handle(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Consumer_create_handle_nullable(FfiOpaqueHandle value);
_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_Consumer_release_handle_nullable(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Consumer_get_value_nullable(FfiOpaqueHandle handle);_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_Indexer_register_finalizer(FfiOpaqueHandle ffi_handle, int32_t isolate_id, Dart_Handle dart_handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Indexer_copy_handle(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_Indexer_release_handle(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Indexer_create_handle_nullable(FfiOpaqueHandle value);
_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_Indexer_release_handle_nullable(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Indexer_get_value_nullable(FfiOpaqueHandle handle);_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_NullableConfuser_register_finalizer(FfiOpaqueHandle ffi_handle, int32_t isolate_id, Dart_Handle dart_handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_NullableConfuser_copy_handle(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_NullableConfuser_release_handle(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_NullableConfuser_create_handle_nullable(FfiOpaqueHandle value);
_GLUECODIUM_FFI_EXPORT void library_smoke_Lambdas_NullableConfuser_release_handle_nullable(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_NullableConfuser_get_value_nullable(FfiOpaqueHandle handle);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Producer_create_proxy(uint64_t token, int32_t isolate_id, Dart_Handle dart_handle, FfiOpaqueHandle f0);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Confuser_create_proxy(uint64_t token, int32_t isolate_id, Dart_Handle dart_handle, FfiOpaqueHandle f0);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Consumer_create_proxy(uint64_t token, int32_t isolate_id, Dart_Handle dart_handle, FfiOpaqueHandle f0);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_Indexer_create_proxy(uint64_t token, int32_t isolate_id, Dart_Handle dart_handle, FfiOpaqueHandle f0);
_GLUECODIUM_FFI_EXPORT FfiOpaqueHandle library_smoke_Lambdas_NullableConfuser_create_proxy(uint64_t token, int32_t isolate_id, Dart_Handle dart_handle, FfiOpaqueHandle f0);
#ifdef __cplusplus
}
#endif
