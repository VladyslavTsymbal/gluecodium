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

package com.here.ivi.api.model.cpp;

import com.here.ivi.api.generator.cpp.CppLibraryIncludes;
import com.here.ivi.api.generator.cpp.CppNameRules;
import com.here.ivi.api.model.common.Include;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public final class CppTemplateTypeRef extends CppComplexTypeRef {

  public final List<CppTypeRef> templateParameters;
  public final TemplateClass templateClass;

  public enum TemplateClass {
    SHARED_POINTER("std", "shared_ptr", CppLibraryIncludes.MEMORY),
    MAP("std", "unordered_map", CppLibraryIncludes.MAP),
    VECTOR("std", "vector", CppLibraryIncludes.VECTOR),
    BASIC_STRING("std", "basic_string", CppLibraryIncludes.STRING),
    RETURN("hf", "Return", CppLibraryIncludes.RETURN);

    public final String namespace;
    public final String name;
    public final Set<Include> includes;

    TemplateClass(final String namespace, final String name, Include... includes) {
      this.namespace = namespace;
      this.name = name;
      this.includes = new LinkedHashSet<>(Arrays.asList(includes));
    }
  }

  private CppTemplateTypeRef(
      final String fullyQualifiedName,
      final TemplateClass templateClass,
      final List<CppTypeRef> templateParameters) {
    super(fullyQualifiedName, null, false);
    this.templateClass = templateClass;
    this.templateParameters = templateParameters;
  }

  public static CppTemplateTypeRef create(
      final TemplateClass templateClass, CppTypeRef... parameters) {
    List<CppTypeRef> templateParameters = Arrays.asList(parameters);
    String parametersString =
        templateParameters.stream().map(param -> param.name).collect(Collectors.joining(", "));
    String fullyQualifiedName =
        CppNameRules.getFullyQualifiedName(
                Collections.singletonList(templateClass.namespace), templateClass.name)
            + "< "
            + parametersString
            + " >";

    CppTemplateTypeRef templateTypeRef =
        new CppTemplateTypeRef(fullyQualifiedName, templateClass, templateParameters);

    // add template parameters includes
    for (CppTypeRef typeRef : templateParameters) {
      templateTypeRef.includes.addAll(typeRef.includes);
    }

    // Add template class includes
    templateTypeRef.includes.addAll(templateClass.includes);

    return templateTypeRef;
  }

  @Override
  public String getShortName() {
    String[] templateParts = name.split("<");
    String[] splitName = templateParts[0].split("::");
    return splitName[splitName.length - 1] + "<" + templateParts[1];
  }

  @Override
  public Stream<? extends CppElement> stream() {
    return templateParameters.stream();
  }
}
