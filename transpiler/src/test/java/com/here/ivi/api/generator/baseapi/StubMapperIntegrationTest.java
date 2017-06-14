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

package com.here.ivi.api.generator.baseapi;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import com.here.ivi.api.generator.utils.LoadModelHelper;
import com.here.ivi.api.loader.baseapi.BaseApiSpecAccessorFactory;
import com.here.ivi.api.model.FrancaModel;
import com.here.ivi.api.model.Interface;
import com.here.ivi.api.model.cppmodel.CppClass;
import com.here.ivi.api.model.cppmodel.CppMethod;
import com.here.ivi.api.model.cppmodel.CppNamespace;
import java.io.IOException;
import java.net.URISyntaxException;
import java.util.Iterator;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

@RunWith(JUnit4.class)
public class StubMapperIntegrationTest {

  @Test
  public void generateStubForMethodsWithoutErrorCode() throws URISyntaxException, IOException {
    FrancaModel<?, ?> model =
        LoadModelHelper.readInFrancaModel(
            "baseapi/fidl/test/MethodsWithoutError.fidl", new BaseApiSpecAccessorFactory());
    Interface<?> iface = LoadModelHelper.extractNthInterfaceFromModel(model, 0);
    StubMapper stubGenerator = createStubGeneratorForTest();

    CppNamespace actualContent = stubGenerator.mapFrancaModelToCppModel(iface);

    assertEquals(actualContent.name, "test");
    assertEquals(actualContent.members.size(), 1);
    assertTrue(actualContent.members.get(0) instanceof CppClass);
    assertTrue(actualContent.members.get(0) instanceof CppClass);
    CppClass actualClass = (CppClass) actualContent.members.get(0);
    assertEquals(actualClass.methods.size(), 3);

    Iterator<CppMethod> iterator = actualClass.methods.iterator();
    CppMethod method = iterator.next();
    assertEquals(method.name, "methodNoOutParams");
    assertEquals(method.inParameters.size(), 1);
    assertEquals(method.inParameters.get(0).type.name, "std::string");
    assertEquals(method.inParameters.get(0).name, "input");
    assertEquals(method.returnType.name, "void");

    method = iterator.next();
    assertEquals(method.name, "methodOneOutParam");
    assertEquals(method.inParameters.size(), 1);
    assertEquals(method.inParameters.get(0).type.name, "std::string");
    assertEquals(method.inParameters.get(0).name, "input");
    assertEquals(method.returnType.name, "std::string");

    method = iterator.next();
    assertEquals(method.name, "methodTwoOutParams");
    assertEquals(method.inParameters.size(), 1);
    assertEquals(method.inParameters.get(0).type.name, "std::string");
    assertEquals(method.inParameters.get(0).name, "input");
    assertEquals(method.returnType.name, "MethodTwoOutParamsResult");
  }

  private StubMapper createStubGeneratorForTest() throws IOException {
    BaseApiNameRules nameRules = new BaseApiNameRules();
    return new StubMapper(nameRules);
  }
}
