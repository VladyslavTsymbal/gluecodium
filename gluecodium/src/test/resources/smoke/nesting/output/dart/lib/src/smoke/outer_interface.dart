import 'package:library/src/_native_base.dart' as __lib;
import 'package:library/src/_token_cache.dart' as __lib;
import 'package:library/src/_type_repository.dart' as __lib;
import 'package:library/src/builtin_types__conversion.dart';
import 'dart:ffi';
import 'package:meta/meta.dart';
import 'package:library/src/_library_context.dart' as __lib;
abstract class OuterInterface {
  OuterInterface();
  factory OuterInterface.fromLambdas({
    @required String Function(String) lambda_foo,
  }) => OuterInterface$Lambdas(
    lambda_foo,
  );
  /// Destroys the underlying native object.
  ///
  /// Call this to free memory when you no longer need this instance.
  /// Note that setting the instance to null will not destroy the underlying native object.
  void release() {}
  String foo(String input);
}
abstract class OuterInterface_InnerClass {
  /// Destroys the underlying native object.
  ///
  /// Call this to free memory when you no longer need this instance.
  /// Note that setting the instance to null will not destroy the underlying native object.
  void release();
  String foo(String input);
}
// OuterInterface_InnerClass "private" section, not exported.
final _smokeOuterinterfaceInnerclassCopyHandle = __lib.catchArgumentError(() => __lib.nativeLibrary.lookupFunction<
    Pointer<Void> Function(Pointer<Void>),
    Pointer<Void> Function(Pointer<Void>)
  >('library_smoke_OuterInterface_InnerClass_copy_handle'));
final _smokeOuterinterfaceInnerclassReleaseHandle = __lib.catchArgumentError(() => __lib.nativeLibrary.lookupFunction<
    Void Function(Pointer<Void>),
    void Function(Pointer<Void>)
  >('library_smoke_OuterInterface_InnerClass_release_handle'));
class OuterInterface_InnerClass$Impl extends __lib.NativeBase implements OuterInterface_InnerClass {
  OuterInterface_InnerClass$Impl(Pointer<Void> handle) : super(handle);
  @override
  void release() {
    if (handle == null) return;
    __lib.uncacheObject(this);
    __lib.ffiUncacheToken(handle, __lib.LibraryContext.isolateId);
    _smokeOuterinterfaceInnerclassReleaseHandle(handle);
    handle = null;
  }
  @override
  String foo(String input) {
    final _fooFfi = __lib.catchArgumentError(() => __lib.nativeLibrary.lookupFunction<Pointer<Void> Function(Pointer<Void>, Int32, Pointer<Void>), Pointer<Void> Function(Pointer<Void>, int, Pointer<Void>)>('library_smoke_OuterInterface_InnerClass_foo__String'));
    final _inputHandle = stringToFfi(input);
    final _handle = this.handle;
    final __resultHandle = _fooFfi(_handle, __lib.LibraryContext.isolateId, _inputHandle);
    stringReleaseFfiHandle(_inputHandle);
    try {
      return stringFromFfi(__resultHandle);
    } finally {
      stringReleaseFfiHandle(__resultHandle);
    }
  }
}
Pointer<Void> smokeOuterinterfaceInnerclassToFfi(OuterInterface_InnerClass value) =>
  _smokeOuterinterfaceInnerclassCopyHandle((value as __lib.NativeBase).handle);
OuterInterface_InnerClass smokeOuterinterfaceInnerclassFromFfi(Pointer<Void> handle) {
  final isolateId = __lib.LibraryContext.isolateId;
  final token = __lib.ffiGetCachedToken(handle, isolateId);
  final instance = __lib.instanceCache[token] as OuterInterface_InnerClass;
  if (instance != null) return instance;
  final _copiedHandle = _smokeOuterinterfaceInnerclassCopyHandle(handle);
  final result = OuterInterface_InnerClass$Impl(_copiedHandle);
  __lib.ffiCacheToken(_copiedHandle, isolateId, __lib.cacheObject(result));
  return result;
}
void smokeOuterinterfaceInnerclassReleaseFfiHandle(Pointer<Void> handle) =>
  _smokeOuterinterfaceInnerclassReleaseHandle(handle);
Pointer<Void> smokeOuterinterfaceInnerclassToFfiNullable(OuterInterface_InnerClass value) =>
  value != null ? smokeOuterinterfaceInnerclassToFfi(value) : Pointer<Void>.fromAddress(0);
OuterInterface_InnerClass smokeOuterinterfaceInnerclassFromFfiNullable(Pointer<Void> handle) =>
  handle.address != 0 ? smokeOuterinterfaceInnerclassFromFfi(handle) : null;
void smokeOuterinterfaceInnerclassReleaseFfiHandleNullable(Pointer<Void> handle) =>
  _smokeOuterinterfaceInnerclassReleaseHandle(handle);
// End of OuterInterface_InnerClass "private" section.
abstract class OuterInterface_InnerInterface {
  OuterInterface_InnerInterface();
  factory OuterInterface_InnerInterface.fromLambdas({
    @required String Function(String) lambda_foo,
  }) => OuterInterface_InnerInterface$Lambdas(
    lambda_foo,
  );
  /// Destroys the underlying native object.
  ///
  /// Call this to free memory when you no longer need this instance.
  /// Note that setting the instance to null will not destroy the underlying native object.
  void release() {}
  String foo(String input);
}
// OuterInterface_InnerInterface "private" section, not exported.
final _smokeOuterinterfaceInnerinterfaceCopyHandle = __lib.catchArgumentError(() => __lib.nativeLibrary.lookupFunction<
    Pointer<Void> Function(Pointer<Void>),
    Pointer<Void> Function(Pointer<Void>)
  >('library_smoke_OuterInterface_InnerInterface_copy_handle'));
final _smokeOuterinterfaceInnerinterfaceReleaseHandle = __lib.catchArgumentError(() => __lib.nativeLibrary.lookupFunction<
    Void Function(Pointer<Void>),
    void Function(Pointer<Void>)
  >('library_smoke_OuterInterface_InnerInterface_release_handle'));
final _smokeOuterinterfaceInnerinterfaceCreateProxy = __lib.catchArgumentError(() => __lib.nativeLibrary.lookupFunction<
    Pointer<Void> Function(Uint64, Int32, Pointer, Pointer),
    Pointer<Void> Function(int, int, Pointer, Pointer)
  >('library_smoke_OuterInterface_InnerInterface_create_proxy'));
final _smokeOuterinterfaceInnerinterfaceGetTypeId = __lib.catchArgumentError(() => __lib.nativeLibrary.lookupFunction<
    Pointer<Void> Function(Pointer<Void>),
    Pointer<Void> Function(Pointer<Void>)
  >('library_smoke_OuterInterface_InnerInterface_get_type_id'));
class OuterInterface_InnerInterface$Lambdas implements OuterInterface_InnerInterface {
  String Function(String) lambda_foo;
  OuterInterface_InnerInterface$Lambdas(
    this.lambda_foo,
  );
  @override
  void release() {}
  @override
  String foo(String input) =>
    lambda_foo(input);
}
class OuterInterface_InnerInterface$Impl extends __lib.NativeBase implements OuterInterface_InnerInterface {
  OuterInterface_InnerInterface$Impl(Pointer<Void> handle) : super(handle);
  @override
  void release() {
    if (handle == null) return;
    __lib.uncacheObject(this);
    __lib.ffiUncacheToken(handle, __lib.LibraryContext.isolateId);
    _smokeOuterinterfaceInnerinterfaceReleaseHandle(handle);
    handle = null;
  }
  @override
  String foo(String input) {
    final _fooFfi = __lib.catchArgumentError(() => __lib.nativeLibrary.lookupFunction<Pointer<Void> Function(Pointer<Void>, Int32, Pointer<Void>), Pointer<Void> Function(Pointer<Void>, int, Pointer<Void>)>('library_smoke_OuterInterface_InnerInterface_foo__String'));
    final _inputHandle = stringToFfi(input);
    final _handle = this.handle;
    final __resultHandle = _fooFfi(_handle, __lib.LibraryContext.isolateId, _inputHandle);
    stringReleaseFfiHandle(_inputHandle);
    try {
      return stringFromFfi(__resultHandle);
    } finally {
      stringReleaseFfiHandle(__resultHandle);
    }
  }
}
int _OuterInterface_InnerInterfacefooStatic(int _token, Pointer<Void> input, Pointer<Pointer<Void>> _result) {
  String _resultObject = null;
  try {
    _resultObject = (__lib.instanceCache[_token] as OuterInterface_InnerInterface).foo(stringFromFfi(input));
    _result.value = stringToFfi(_resultObject);
  } finally {
    stringReleaseFfiHandle(input);
  }
  return 0;
}
Pointer<Void> smokeOuterinterfaceInnerinterfaceToFfi(OuterInterface_InnerInterface value) {
  if (value is __lib.NativeBase) return _smokeOuterinterfaceInnerinterfaceCopyHandle((value as __lib.NativeBase).handle);
  final result = _smokeOuterinterfaceInnerinterfaceCreateProxy(
    __lib.cacheObject(value),
    __lib.LibraryContext.isolateId,
    __lib.uncacheObjectFfi,
    Pointer.fromFunction<Uint8 Function(Uint64, Pointer<Void>, Pointer<Pointer<Void>>)>(_OuterInterface_InnerInterfacefooStatic, __lib.unknownError)
  );
  return result;
}
OuterInterface_InnerInterface smokeOuterinterfaceInnerinterfaceFromFfi(Pointer<Void> handle) {
  final isolateId = __lib.LibraryContext.isolateId;
  final token = __lib.ffiGetCachedToken(handle, isolateId);
  final instance = __lib.instanceCache[token] as OuterInterface_InnerInterface;
  if (instance != null) return instance;
  final _typeIdHandle = _smokeOuterinterfaceInnerinterfaceGetTypeId(handle);
  final factoryConstructor = __lib.typeRepository[stringFromFfi(_typeIdHandle)];
  stringReleaseFfiHandle(_typeIdHandle);
  final _copiedHandle = _smokeOuterinterfaceInnerinterfaceCopyHandle(handle);
  final result = factoryConstructor != null
    ? factoryConstructor(_copiedHandle)
    : OuterInterface_InnerInterface$Impl(_copiedHandle);
  __lib.ffiCacheToken(_copiedHandle, isolateId, __lib.cacheObject(result));
  return result;
}
void smokeOuterinterfaceInnerinterfaceReleaseFfiHandle(Pointer<Void> handle) =>
  _smokeOuterinterfaceInnerinterfaceReleaseHandle(handle);
Pointer<Void> smokeOuterinterfaceInnerinterfaceToFfiNullable(OuterInterface_InnerInterface value) =>
  value != null ? smokeOuterinterfaceInnerinterfaceToFfi(value) : Pointer<Void>.fromAddress(0);
OuterInterface_InnerInterface smokeOuterinterfaceInnerinterfaceFromFfiNullable(Pointer<Void> handle) =>
  handle.address != 0 ? smokeOuterinterfaceInnerinterfaceFromFfi(handle) : null;
void smokeOuterinterfaceInnerinterfaceReleaseFfiHandleNullable(Pointer<Void> handle) =>
  _smokeOuterinterfaceInnerinterfaceReleaseHandle(handle);
// End of OuterInterface_InnerInterface "private" section.
// OuterInterface "private" section, not exported.
final _smokeOuterinterfaceCopyHandle = __lib.catchArgumentError(() => __lib.nativeLibrary.lookupFunction<
    Pointer<Void> Function(Pointer<Void>),
    Pointer<Void> Function(Pointer<Void>)
  >('library_smoke_OuterInterface_copy_handle'));
final _smokeOuterinterfaceReleaseHandle = __lib.catchArgumentError(() => __lib.nativeLibrary.lookupFunction<
    Void Function(Pointer<Void>),
    void Function(Pointer<Void>)
  >('library_smoke_OuterInterface_release_handle'));
final _smokeOuterinterfaceCreateProxy = __lib.catchArgumentError(() => __lib.nativeLibrary.lookupFunction<
    Pointer<Void> Function(Uint64, Int32, Pointer, Pointer),
    Pointer<Void> Function(int, int, Pointer, Pointer)
  >('library_smoke_OuterInterface_create_proxy'));
final _smokeOuterinterfaceGetTypeId = __lib.catchArgumentError(() => __lib.nativeLibrary.lookupFunction<
    Pointer<Void> Function(Pointer<Void>),
    Pointer<Void> Function(Pointer<Void>)
  >('library_smoke_OuterInterface_get_type_id'));
class OuterInterface$Lambdas implements OuterInterface {
  String Function(String) lambda_foo;
  OuterInterface$Lambdas(
    this.lambda_foo,
  );
  @override
  void release() {}
  @override
  String foo(String input) =>
    lambda_foo(input);
}
class OuterInterface$Impl extends __lib.NativeBase implements OuterInterface {
  OuterInterface$Impl(Pointer<Void> handle) : super(handle);
  @override
  void release() {
    if (handle == null) return;
    __lib.uncacheObject(this);
    __lib.ffiUncacheToken(handle, __lib.LibraryContext.isolateId);
    _smokeOuterinterfaceReleaseHandle(handle);
    handle = null;
  }
  @override
  String foo(String input) {
    final _fooFfi = __lib.catchArgumentError(() => __lib.nativeLibrary.lookupFunction<Pointer<Void> Function(Pointer<Void>, Int32, Pointer<Void>), Pointer<Void> Function(Pointer<Void>, int, Pointer<Void>)>('library_smoke_OuterInterface_foo__String'));
    final _inputHandle = stringToFfi(input);
    final _handle = this.handle;
    final __resultHandle = _fooFfi(_handle, __lib.LibraryContext.isolateId, _inputHandle);
    stringReleaseFfiHandle(_inputHandle);
    try {
      return stringFromFfi(__resultHandle);
    } finally {
      stringReleaseFfiHandle(__resultHandle);
    }
  }
}
int _OuterInterfacefooStatic(int _token, Pointer<Void> input, Pointer<Pointer<Void>> _result) {
  String _resultObject = null;
  try {
    _resultObject = (__lib.instanceCache[_token] as OuterInterface).foo(stringFromFfi(input));
    _result.value = stringToFfi(_resultObject);
  } finally {
    stringReleaseFfiHandle(input);
  }
  return 0;
}
Pointer<Void> smokeOuterinterfaceToFfi(OuterInterface value) {
  if (value is __lib.NativeBase) return _smokeOuterinterfaceCopyHandle((value as __lib.NativeBase).handle);
  final result = _smokeOuterinterfaceCreateProxy(
    __lib.cacheObject(value),
    __lib.LibraryContext.isolateId,
    __lib.uncacheObjectFfi,
    Pointer.fromFunction<Uint8 Function(Uint64, Pointer<Void>, Pointer<Pointer<Void>>)>(_OuterInterfacefooStatic, __lib.unknownError)
  );
  return result;
}
OuterInterface smokeOuterinterfaceFromFfi(Pointer<Void> handle) {
  final isolateId = __lib.LibraryContext.isolateId;
  final token = __lib.ffiGetCachedToken(handle, isolateId);
  final instance = __lib.instanceCache[token] as OuterInterface;
  if (instance != null) return instance;
  final _typeIdHandle = _smokeOuterinterfaceGetTypeId(handle);
  final factoryConstructor = __lib.typeRepository[stringFromFfi(_typeIdHandle)];
  stringReleaseFfiHandle(_typeIdHandle);
  final _copiedHandle = _smokeOuterinterfaceCopyHandle(handle);
  final result = factoryConstructor != null
    ? factoryConstructor(_copiedHandle)
    : OuterInterface$Impl(_copiedHandle);
  __lib.ffiCacheToken(_copiedHandle, isolateId, __lib.cacheObject(result));
  return result;
}
void smokeOuterinterfaceReleaseFfiHandle(Pointer<Void> handle) =>
  _smokeOuterinterfaceReleaseHandle(handle);
Pointer<Void> smokeOuterinterfaceToFfiNullable(OuterInterface value) =>
  value != null ? smokeOuterinterfaceToFfi(value) : Pointer<Void>.fromAddress(0);
OuterInterface smokeOuterinterfaceFromFfiNullable(Pointer<Void> handle) =>
  handle.address != 0 ? smokeOuterinterfaceFromFfi(handle) : null;
void smokeOuterinterfaceReleaseFfiHandleNullable(Pointer<Void> handle) =>
  _smokeOuterinterfaceReleaseHandle(handle);
// End of OuterInterface "private" section.
