/*
 * Copyright (C) 2016-2019 HERE Europe B.V.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 * License-Filename: LICENSE
 */

package com.here.genium.model.lime

class LimeMethod(
    path: LimePath,
    visibility: LimeVisibility = LimeVisibility.PUBLIC,
    comment: String = "",
    attributes: LimeAttributes? = null,
    val returnType: LimeReturnType = LimeReturnType.VOID,
    val parameters: List<LimeParameter> = emptyList(),
    private val exceptionRef: LimeTypeRef? = null,
    val isStatic: Boolean = false,
    val isConstructor: Boolean = false
) : LimeNamedElement(path, visibility, comment, attributes) {
    val exception: LimeException?
        get() = exceptionRef?.type as? LimeException
}
