//
//
// Automatically generated. Do not modify. Your changes will be lost.
import Foundation
internal struct InternalStruct {
    public var stringField: String
    public init(stringField: String) {
        self.stringField = stringField
    }
    internal init(cHandle: _baseRef) {
        stringField = moveFromCType(smoke_PublicTypeCollection_InternalStruct_stringField_get(cHandle))
    }
    internal func convertToCType() -> _baseRef {
        let c_stringField = moveToCType(stringField)
        return smoke_PublicTypeCollection_InternalStruct_create_handle(c_stringField.ref)
    }
}
internal func copyFromCType(_ handle: _baseRef) -> InternalStruct {
    return InternalStruct(cHandle: handle)
}
internal func moveFromCType(_ handle: _baseRef) -> InternalStruct {
    defer {
        smoke_PublicTypeCollection_InternalStruct_release_handle(handle)
    }
    return copyFromCType(handle)
}
internal func copyToCType(_ swiftType: InternalStruct) -> RefHolder {
    return RefHolder(swiftType.convertToCType())
}
internal func moveToCType(_ swiftType: InternalStruct) -> RefHolder {
    return RefHolder(ref: copyToCType(swiftType).ref, release: smoke_PublicTypeCollection_InternalStruct_release_handle)
}