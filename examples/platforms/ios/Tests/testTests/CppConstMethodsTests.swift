// -------------------------------------------------------------------------------------------------
// Copyright (C) 2016-2020 HERE Europe B.V.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0
// License-Filename: LICENSE
//
// -------------------------------------------------------------------------------------------------

import XCTest
import hello

class CppConstMethodsTests: XCTestCase {

    class CppConstCallback: CppConstInterface {
        public func getFoo() -> String { return "FOO" }
    }

    func testCppConstMethodOnClass() {
        let result = CppConstClass().getFoo()

        XCTAssertEqual("foo", result)
    }

    func testCppConstMethodOnInterface() {
        let result = CppConstInterfaceFactory.createCppConstInterface().getFoo()

        XCTAssertEqual("foo", result)
    }

    func testCppConstMethodOnInterfaceInCpp() {
        let result = CppConstInterfaceFactory.callGetFoo(callback: CppConstCallback())

        XCTAssertEqual("FOO", result)
    }

    static var allTests = [
        ("testCppConstMethodOnClass", testCppConstMethodOnClass),
        ("testCppConstMethodOnInterface", testCppConstMethodOnInterface),
        ("testCppConstMethodOnInterfaceInCpp", testCppConstMethodOnInterfaceInCpp)
    ]
}
