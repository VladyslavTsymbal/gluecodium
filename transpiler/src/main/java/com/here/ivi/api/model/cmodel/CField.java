/*
 * Copyright (C) 2017 HERE Global B.V. and its affiliate(s). All rights reserved.
 *
 * This software, including documentation, is protected by copyright controlled by
 * HERE Global B.V. All rights are reserved. Copying, including reproducing, storing,
 * adapting or translating, any or all of this material requires the prior written
 * consent of HERE Global B.V. This material also contains confidential information,
 * which may not be disclosed to others without prior written consent of HERE Global B.V.
 *
 */

package com.here.ivi.api.model.cmodel;

import com.here.ivi.api.generator.cbridge.CppTypeInfo;

/** Field of a com.here.ivi.api.model.cmodel.CStruct */
public class CField extends CElement {
  public final CppTypeInfo type;

  public CField(String name, CppTypeInfo cppTypeInfo) {
    super(name);
    type = cppTypeInfo;
  }

  @Override
  public String toString() {
    return type.functionReturnType.declareBegin()
        + " "
        + name
        + type.functionReturnType.declareEnd();
  }
}
