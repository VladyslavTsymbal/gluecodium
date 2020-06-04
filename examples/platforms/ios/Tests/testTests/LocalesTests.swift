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

class LocalesTests: XCTestCase {

    func testLocaleRoundTrip() {
        let locale = Locale.current

        let result = Locales.localeRoundTrip(input: locale)

        XCTAssertEqual(result.identifier, locale.identifier)
    }

    func testLocaleRoundTripStripTag() {
        let locale = Locale.current

        let result = Locales.localeRoundTripStripTag(input: locale)

        XCTAssertEqual(result.identifier, locale.identifier)
    }

    func testLocaleRoundTripNullable() {
        let locale = Locale.current

        let result = Locales.localeRoundTripNullable(input: locale)

        XCTAssertEqual(result?.identifier, locale.identifier)
    }

    func testLocaleRoundTripNullableNull() {
        let result = Locales.localeRoundTripNullable(input: nil)

        XCTAssertNil(result)
    }

    func testLocalePropertyRoundTrip() {
        let locale = Locale.current

        Locales.localeProperty = locale
        let result = Locales.localeProperty

        XCTAssertEqual(result.identifier, locale.identifier)
    }

    func testLocaleWithMalformedTag() {
        let result = Locales.localeWithMalformedTag

        XCTAssertEqual(result.identifier, "")
    }

    func testLocaleWithMalformedLanguage() {
        let result = Locales.localeWithMalformedLanguage

        XCTAssertEqual(result.identifier, "")
    }

    func testLocaleWithMalformedCountry() {
        let result = Locales.localeWithMalformedCountry

        XCTAssertEqual(result.identifier, "_")
    }

    func testLocaleWithMalformedScript() {
        let result = Locales.localeWithMalformedScript

        XCTAssertEqual(result.identifier, "_")
    }

    static var allTests = [
        ("testLocaleRoundTrip", testLocaleRoundTrip),
        ("testLocaleRoundTripStripTag", testLocaleRoundTripStripTag),
        ("testLocaleRoundTripNullable", testLocaleRoundTripNullable),
        ("testLocaleRoundTripNullableNull", testLocaleRoundTripNullableNull),
        ("testLocalePropertyRoundTrip", testLocalePropertyRoundTrip),
        ("testLocaleWithMalformedTag", testLocaleWithMalformedTag),
        ("testLocaleWithMalformedLanguage", testLocaleWithMalformedLanguage),
        ("testLocaleWithMalformedCountry", testLocaleWithMalformedCountry),
        ("testLocaleWithMalformedScript", testLocaleWithMalformedScript)
    ]
}
