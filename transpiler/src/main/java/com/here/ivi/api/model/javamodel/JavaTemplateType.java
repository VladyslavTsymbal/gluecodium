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

package com.here.ivi.api.model.javamodel;

import java.util.*;
import java.util.stream.Collectors;

public final class JavaTemplateType extends JavaCustomType {
  public final TemplateClass templateClass;
  public final List<JavaType> templateParameters;

  public enum TemplateClass {
    LIST(
        "List",
        new JavaImport("List", new JavaPackage(Arrays.asList("java", "util"))),
        Arrays.asList("java", "util"));

    public final String name;
    public final JavaImport javaImport;
    public final List<String> packageNames;

    TemplateClass(String name, JavaImport javaImport, List<String> packageNames) {
      this.name = name;
      this.javaImport = javaImport;
      this.packageNames = packageNames;
    }
  }

  private JavaTemplateType(
      String name, TemplateClass templateClass, List<JavaType> templateParameters) {
    super(
        name,
        Arrays.asList(templateClass.name),
        templateClass.packageNames,
        Collections.emptySet());

    this.templateClass = templateClass;
    this.templateParameters = templateParameters;
  }

  public static JavaTemplateType create(TemplateClass templateClass, JavaType... parameters) {
    List<JavaType> templateParameters = Arrays.asList(parameters);
    String name =
        templateClass.name
            + "<"
            + templateParameters
                .stream()
                .map(parameter -> parameter.name)
                .collect(Collectors.joining(", "))
            + ">";

    JavaTemplateType templateType = new JavaTemplateType(name, templateClass, templateParameters);

    templateType.imports.add(templateClass.javaImport);
    templateParameters.forEach(parameter -> templateType.imports.addAll(parameter.imports));

    return templateType;
  }
}
