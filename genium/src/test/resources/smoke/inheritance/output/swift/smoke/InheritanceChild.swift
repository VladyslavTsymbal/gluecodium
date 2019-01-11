//
//
// Automatically generated. Do not modify. Your changes will be lost.
import Foundation
internal func getRef(_ ref: InheritanceChild?, owning: Bool = true) -> RefHolder {
    guard let reference = ref else {
        return RefHolder(0)
    }
    if let instanceReference = reference as? NativeBase {
        let handle_copy = smoke_InheritanceChild_copy_handle(instanceReference.c_handle)
        return owning
            ? RefHolder(ref: handle_copy, release: smoke_InheritanceChild_release_handle)
            : RefHolder(handle_copy)
    }
    var functions = smoke_InheritanceChild_FunctionTable()
    functions.swift_pointer = Unmanaged<AnyObject>.passRetained(reference).toOpaque()
    functions.release = {swift_class_pointer in
        if let swift_class = swift_class_pointer {
            Unmanaged<AnyObject>.fromOpaque(swift_class).release()
        }
    }
    functions.smoke_InheritanceRoot_rootMethod = {(swift_class_pointer) in
        let swift_class = Unmanaged<AnyObject>.fromOpaque(swift_class_pointer!).takeUnretainedValue() as! InheritanceChild
        swift_class.rootMethod()
    }
    functions.smoke_InheritanceChild_childMethod = {(swift_class_pointer) in
        let swift_class = Unmanaged<AnyObject>.fromOpaque(swift_class_pointer!).takeUnretainedValue() as! InheritanceChild
        swift_class.childMethod()
    }
    functions.smoke_InheritanceRoot_rootAttribute_get = {(swift_class_pointer) in
        let swift_class = Unmanaged<AnyObject>.fromOpaque(swift_class_pointer!).takeUnretainedValue() as! InheritanceChild
        return swift_class.rootAttribute.convertToCType()
    }
    functions.smoke_InheritanceRoot_rootAttribute_set = {(swift_class_pointer, newValue) in
        let swift_class = Unmanaged<AnyObject>.fromOpaque(swift_class_pointer!).takeUnretainedValue() as! InheritanceChild
        defer {
            std_string_release_handle(newValue)
        }
        swift_class.rootAttribute = String(data: Data(bytes: std_string_data_get(newValue),
                                                count: Int(std_string_size_get(newValue))), encoding: .utf8)!
    }
    let proxy = smoke_InheritanceChild_create_proxy(functions)
    return owning ? RefHolder(ref: proxy, release: smoke_InheritanceChild_release_handle) : RefHolder(proxy)
}
public protocol InheritanceChild : InheritanceRoot {
    var rootAttribute: String { get set }
    func rootMethod() -> Void
    func childMethod() -> Void
}
internal class _InheritanceChild: InheritanceChild {
    var rootAttribute: String {
        get {
            return moveFromCType(smoke_InheritanceRoot_rootAttribute_get(c_instance))
        }
        set {
            return smoke_InheritanceRoot_rootAttribute_set(c_instance, newValue)
        }
    }
    let c_instance : _baseRef
    init(cInheritanceChild: _baseRef) {
        guard cInheritanceChild != 0 else {
            fatalError("Nullptr value is not supported for initializers")
        }
        c_instance = cInheritanceChild
    }
    deinit {
        smoke_InheritanceChild_release_handle(c_instance)
    }
    public func rootMethod() -> Void {
        return smoke_InheritanceRoot_rootMethod(c_instance)
    }
    public func childMethod() -> Void {
        return smoke_InheritanceChild_childMethod(c_instance)
    }
}
extension _InheritanceChild: NativeBase {
    var c_handle: _baseRef { return c_instance }
}