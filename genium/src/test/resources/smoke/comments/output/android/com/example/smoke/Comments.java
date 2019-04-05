/*
 *
 * Automatically generated. Do not modify. Your changes will be lost.
 */
package com.example.smoke;
import android.support.annotation.NonNull;
import com.example.NativeBase;
/**
 * <p>This is some very useful interface.</p>
 *
 */
public class Comments extends NativeBase {
    /**
     * <p>This is some very useful constant.</p>
     *
     */
    public static final boolean VERY_USEFUL = true;
    /**
     * <p>This is some very useful enum.</p>
     *
     */
    public enum SomeEnum {
        /**
         * <p>Not quite useful</p>
         *
         */
        USELESS(0),
        /**
         * <p>Somewhat useful</p>
         *
         */
        USEFUL(1);
        public final int value;
        SomeEnum(final int value) {
            this.value = value;
        }
    }
    public static class SomeEnumException extends Exception {
        SomeEnumException(final Comments.SomeEnum error) {
            super(Integer.toString(error.value));
            this.error = error;
        }
        public final Comments.SomeEnum error;
    }
    /**
     * <p>This is some very useful struct.</p>
     *
     */
    public static class SomeStruct {
        /**
         * <p>How useful this struct is</p>
         *
         */
        public boolean someField;
        public SomeStruct() {
            this(false);
        }
        public SomeStruct(boolean someField) {
            this.someField = someField;
        }
    }
    /**
     * For internal use only.
     * @exclude
     */
    protected Comments(final long nativeHandle) {
        super(nativeHandle, new Disposer() {
            @Override
            public void disposeNative(long handle) {
                disposeNativeHandle(handle);
            }
        });
    }
    private static native void disposeNativeHandle(long nativeHandle);
    /**
     * <p>This is some very useful method that measures the usefulness of its input.</p>
     *
     * @param input <p>Very useful input parameter</p>
     *
     * @return Usefulness of the input
     * @throws Comments.SomeEnumException
     */
    public native boolean someMethodWithAllComments(final String input) throws Comments.SomeEnumException;
    /**
     * <p>This is some very useful method that measures the usefulness of its input.</p>
     *
     * @param input <p>Very useful input parameter</p>
     *
     */
    public native boolean someMethodWithInputComments(final String input);
    /**
     * <p>This is some very useful method that measures the usefulness of its input.</p>
     *
     * @return Usefulness of the input
     */
    public native boolean someMethodWithOutputComments(final String input);
    /**
     * <p>This is some very useful method that measures the usefulness of its input.</p>
     *
     */
    public native boolean someMethodWithNoComments(final String input);
    /**
     * <p>This is some very useful method that does not measure the usefulness of its input.</p>
     *
     * @param input <p>Very useful input parameter</p>
     *
     */
    public native void someMethodWithoutReturnTypeWithAllComments(final String input);
    /**
     * <p>This is some very useful method that does not measure the usefulness of its input.</p>
     *
     */
    public native void someMethodWithoutReturnTypeWithNoComments(final String input);
    /**
     * <p>This is some very useful method that measures the usefulness of something.</p>
     *
     * @return Usefulness of the input
     */
    public native boolean someMethodWithoutInputParametersWithAllComments();
    /**
     * <p>This is some very useful method that measures the usefulness of something.</p>
     *
     */
    public native boolean someMethodWithoutInputParametersWithNoComments();
    public native void someMethodWithNothing();
    /**
     * <p>This is some very useful method that does nothing.</p>
     *
     */
    public native void someMethodWithoutReturnTypeOrInputParameters();
    /**
     * <p>This is some very useful instance method.</p>
     *
     * @param input <p>This is some very useful instance method parameter.</p>
     *
     * @return This is some very useful instance method result.
     */
    @NonNull
    public native CommentsInstantiable instanceMethod(@NonNull final CommentsInstantiable input);
    /**
     * <p>Gets some very useful attribute.</p>
     *
     */
    public native boolean isSomeAttribute();
    /**
     * Sets some very useful attribute.
     */
    public native void setSomeAttribute(final boolean value);
    /**
     * <p>Gets some very useful attribute.</p>
     *
     */
    @NonNull
    public native CommentsInstantiable getInstanceAttribute();
    /**
     * Sets some very useful attribute.
     */
    public native void setInstanceAttribute(@NonNull final CommentsInstantiable value);
}