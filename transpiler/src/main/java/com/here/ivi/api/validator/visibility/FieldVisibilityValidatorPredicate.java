/*
 * Copyright (c) 2016-2018 HERE Europe B.V.
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

package com.here.ivi.api.validator.visibility;

import java.util.Collection;
import java.util.Collections;
import org.franca.core.franca.FField;
import org.franca.core.franca.FModelElement;

/**
 * Visibility predicate for fields. Conditions checked against:
 *
 * <ul>
 *   <li>A "public" field should not have an "internal" type.
 *   <li>An "internal" field should not have an "internal" type from a foreign package.
 * </ul>
 */
public final class FieldVisibilityValidatorPredicate extends VisibilityValidatorPredicate<FField> {

  private static final String ERROR_MESSAGE_FORMAT =
      "Public field '%s' cannot have an internal type '%s'.";
  private static final String PACKAGE_ERROR_MESSAGE_FORMAT =
      "Internal field '%s' cannot have an internal type '%s' from a different package.";

  @Override
  public Class<FField> getElementClass() {
    return FField.class;
  }

  @Override
  protected Collection<FModelElement> getChildElements(final FField francaField) {
    return Collections.singletonList(francaField.getType().getDerived());
  }

  @Override
  protected String getVisibilityErrorMessageFormat() {
    return ERROR_MESSAGE_FORMAT;
  }

  @Override
  protected String getPackageErrorMessageFormat() {
    return PACKAGE_ERROR_MESSAGE_FORMAT;
  }
}
