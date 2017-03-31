package com.here.ivi.api.model;

import org.eclipse.emf.ecore.EObject;
import org.franca.core.franca.FModel;
import org.franca.core.franca.FTypeCollection;

/**
 * This class stores the information where a type was defined
 * It is used for resolving namespaces
 */
public class DefinedBy {
    public DefinedBy(FTypeCollection type, FModel model) {
        this.type = type;
        this.model = model;
    }

    /**
     * Gets the  model and interface that defined the given franca object
     * @param obj The franca object
     * @return The model and interface that defined the given object
     */
    public static DefinedBy getDefinedBy(EObject obj) {
        // search for parent type collection
        FTypeCollection tc = findDefiningTypeCollection(obj);

        if (tc == null || !(tc.eContainer() instanceof FModel)) {
            throw new RuntimeException("Could not resolve root of EObject. Invalid franca definition. " + obj);
        }

        FModel model = (FModel)tc.eContainer();
        return new DefinedBy(tc, model);
    }

    /** Returns the base name, eg. MyInterface */
    public String getBaseName() {
        return type.getName();
    }

    /** Returns the full package name, eg. com.here.navigation.guidance */
    public String getPackageName() {
        return model.getName();
    }

    /** Returns the split packages */
    public String[] getPackages() {
        return FrancaModel.splitPackage(getPackageName());
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        DefinedBy definedBy = (DefinedBy) o;

        if (!getBaseName().equals(definedBy.getBaseName())) {
            return false;
        }
        return getPackageName().equals(definedBy.getPackageName());
    }

    @Override
    public int hashCode() {
        int result = getPackageName().hashCode();
        result = 31 * result + getBaseName().hashCode();
        return result;
    }

    @Override
    public String toString() {
        return getPackageName() + "." + getBaseName();
    }

    /**
     * Find the TypeCollection that contains this type by moving up the hierarchy recursively
     *
     * @param obj The franca object
     * @return The type collection that contains this type
     */
    private static FTypeCollection findDefiningTypeCollection(EObject obj) {
        if (obj instanceof FTypeCollection) {
            return (FTypeCollection)obj; // FInterface is a FTypeCollection as well
        }

        EObject parent = obj.eContainer();

        if ((parent == obj) || (parent == null)) {
            return null;
        }

        return findDefiningTypeCollection(parent);
    }

    public final FTypeCollection type; // A FInterface is a FTypeCollection as well
    public final FModel model;
}
