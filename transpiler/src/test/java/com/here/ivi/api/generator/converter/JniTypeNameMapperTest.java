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

package com.here.ivi.api.generator.converter;

import static org.junit.Assert.assertEquals;

import com.here.ivi.api.generator.jni.JniTypeNameMapper;
import com.here.ivi.api.model.javamodel.*;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

@RunWith(JUnit4.class)
public final class JniTypeNameMapperTest {

  @Test
  public void convertVoidType() {
    // Arrange
    JavaType javaPrimitiveType = JavaPrimitiveType.VOID;

    // Act
    String result = JniTypeNameMapper.map(javaPrimitiveType);

    // Assert
    assertEquals("void", result);
  }

  @Test
  public void convertBooleanType() {
    // Arrange
    JavaType javaBool = JavaPrimitiveType.BOOL;

    // Act
    String result = JniTypeNameMapper.map(javaBool);

    // Assert
    assertEquals(("j" + javaBool.name), result);
  }

  @Test
  public void convertByteType() {
    // Arrange
    JavaType javaByte = JavaPrimitiveType.BYTE;

    // Act
    String result = JniTypeNameMapper.map(javaByte);

    // Assert
    assertEquals(("j" + javaByte.name), result);
  }

  @Test
  public void convertCharType() {
    // Arrange
    JavaType javaChar = JavaPrimitiveType.CHAR;

    // Act
    String result = JniTypeNameMapper.map(javaChar);

    // Assert
    assertEquals(("j" + javaChar.name), result);
  }

  @Test
  public void convertDoubleType() {
    // Arrange
    JavaType javaDouble = JavaPrimitiveType.DOUBLE;

    // Act
    String result = JniTypeNameMapper.map(javaDouble);

    // Assert
    assertEquals(("j" + javaDouble.name), result);
  }

  @Test
  public void convertFloatType() {
    // Arrange
    JavaType javaFloat = JavaPrimitiveType.FLOAT;

    // Act
    String result = JniTypeNameMapper.map(javaFloat);

    // Assert
    assertEquals(("j" + javaFloat.name), result);
  }

  @Test
  public void convertIntType() {
    // Arrange
    JavaType javaInt = JavaPrimitiveType.INT;

    // Act
    String result = JniTypeNameMapper.map(javaInt);

    // Assert
    assertEquals(("j" + javaInt.name), result);
  }

  @Test
  public void convertLongType() {
    // Arrange
    JavaType javaLong = JavaPrimitiveType.LONG;

    // Act
    String result = JniTypeNameMapper.map(javaLong);

    // Assert
    assertEquals(("j" + javaLong.name), result);
  }

  @Test
  public void convertShortType() {
    // Arrange
    JavaType javaShort = JavaPrimitiveType.SHORT;

    // Act
    String result = JniTypeNameMapper.map(javaShort);

    // Assert
    assertEquals(("j" + javaShort.name), result);
  }

  @Test
  public void convertClassType() {
    // Arrange
    JavaType javaClass = new JavaReferenceType(JavaReferenceType.Type.CLASS);

    // Act
    String result = JniTypeNameMapper.map(javaClass);

    // Assert
    assertEquals("jclass", result);
  }

  @Test
  public void convertStringType() {
    // Arrange
    JavaType javaString = new JavaReferenceType(JavaReferenceType.Type.STRING);

    // Act
    String result = JniTypeNameMapper.map(javaString);

    // Assert
    assertEquals("jstring", result);
  }

  @Test
  public void convertByteArrayType() {
    // Arrange
    JavaType javaString = new JavaArrayType(JavaArrayType.Type.BYTE_ARRAY);

    // Act
    String result = JniTypeNameMapper.map(javaString);

    // Assert
    assertEquals("jbyteArray", result);
  }

  @Test
  public void convertCharArrayType() {
    // Arrange
    JavaType javaString = new JavaArrayType(JavaArrayType.Type.CHAR_ARRAY);

    // Act
    String result = JniTypeNameMapper.map(javaString);

    // Assert
    assertEquals("jcharArray", result);
  }

  @Test
  public void convertShortArrayType() {
    // Arrange
    JavaType javaString = new JavaArrayType(JavaArrayType.Type.SHORT_ARRAY);

    // Act
    String result = JniTypeNameMapper.map(javaString);

    // Assert
    assertEquals("jshortArray", result);
  }

  @Test
  public void convertIntArrayType() {
    // Arrange
    JavaType javaString = new JavaArrayType(JavaArrayType.Type.INT_ARRAY);

    // Act
    String result = JniTypeNameMapper.map(javaString);

    // Assert
    assertEquals("jintArray", result);
  }

  @Test
  public void convertLongArrayType() {
    // Arrange
    JavaType javaString = new JavaArrayType(JavaArrayType.Type.LONG_ARRAY);

    // Act
    String result = JniTypeNameMapper.map(javaString);

    // Assert
    assertEquals("jlongArray", result);
  }

  @Test
  public void convertFloatArrayType() {
    // Arrange
    JavaType javaString = new JavaArrayType(JavaArrayType.Type.FLOAT_ARRAY);

    // Act
    String result = JniTypeNameMapper.map(javaString);

    // Assert
    assertEquals("jfloatArray", result);
  }

  @Test
  public void convertDoubleArrayType() {
    // Arrange
    JavaType javaString = new JavaArrayType(JavaArrayType.Type.DOUBLE_ARRAY);

    // Act
    String result = JniTypeNameMapper.map(javaString);

    // Assert
    assertEquals("jdoubleArray", result);
  }

  @Test
  public void convertThrowableType() {
    // Arrange
    JavaType javaString = new JavaReferenceType(JavaReferenceType.Type.THROWABLE);

    // Act
    String result = JniTypeNameMapper.map(javaString);

    // Assert
    assertEquals("jthrowable", result);
  }

  @Test
  public void convertCustomType() {
    // Arrange
    JavaType javaCustom = new JavaCustomType("MyFancyType");

    // Act
    String result = JniTypeNameMapper.map(javaCustom);

    // Assert
    assertEquals("jobject", result);
  }
}
