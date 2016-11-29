package com.wochacha.learnjni.utils;

/**
 * Created by guanghui_wan on 2016/11/29.
 */

public class JNIUtils {

    static {
        System.loadLibrary("hello");
    }

//    public static native String get3DESKey(Context context);
//
//    public static native String get3DESVi(Context context);

    public static native String helloFromJNI();

    public static native int Add(int i, int y);

}
