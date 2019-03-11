/*
 * Copyright (C) 2016-2018 HERE Europe B.V.
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

package com.here.genium.model.swift;

public final class SwiftDictionary extends SwiftType {

  public final String cPrefix;
  public final SwiftType keyType;
  public final SwiftType valueType;

  @lombok.Builder(builderClassName = "Builder")
  private SwiftDictionary(
      final String name,
      final SwiftVisibility visibility,
      final String publicName,
      final String cPrefix,
      final SwiftType keyType,
      final SwiftType valueType) {
    super(
        name,
        visibility,
        TypeCategory.DICTIONARY,
        "[" + keyType.publicName + ": " + valueType.publicName + "]",
        publicName,
        false);
    this.cPrefix = cPrefix;
    this.keyType = keyType;
    this.valueType = valueType;
  }

  public static Builder builder(final String name) {
    return new Builder().name(name);
  }
}
