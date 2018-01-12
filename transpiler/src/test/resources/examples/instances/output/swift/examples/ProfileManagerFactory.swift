//
// Copyright (C) 2017 HERE Global B.V. and/or its affiliated companies. All rights reserved.
//
// This software, including documentation, is protected by copyright controlled by
// HERE Global B.V. All rights are reserved. Copying, including reproducing, storing,
// adapting or translating, any or all of this material requires the prior written
// consent of HERE Global B.V. This material also contains confidential information,
// which may not be disclosed to others without prior written consent of HERE Global B.V.
//
// Automatically generated. Do not modify. Your changes will be lost.

import Foundation

internal func getRef(_ ref: ProfileManagerFactory) -> RefHolder {
    return RefHolder(ref.c_instance)
}
public class ProfileManagerFactory {
    let c_instance : _baseRef
    public init?(cProfileManagerFactory: _baseRef) {
        c_instance = cProfileManagerFactory
    }
    deinit {
        examples_ProfileManagerFactory_release(c_instance)
    }

    public static func createProfileManager() -> ProfileManager? {
        let cResult = examples_ProfileManagerFactory_createProfileManager()
        precondition(cResult.private_pointer != nil, "Out of memory")

        return ProfileManager(cProfileManager: cResult)
    }

    public static func createProfileManagerInterface() -> ProfileManagerInterface? {
        let cResult = examples_ProfileManagerFactory_createProfileManagerInterface()
        precondition(cResult.private_pointer != nil, "Out of memory")

        if let swift_pointer = examples_ProfileManagerInterface_get_swift_object_from_cache(cResult),
                let reconstructed = Unmanaged<AnyObject>.fromOpaque(swift_pointer).takeUnretainedValue() as? ProfileManagerInterface {
            return reconstructed
        }
        return _ProfileManagerInterface(cProfileManagerInterface: cResult)
    }

}
