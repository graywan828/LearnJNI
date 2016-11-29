//
// Created by guanghui_wan on 2016/11/29.
//

#include "hello.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * 方法名称规定 : Java_完整包名类名_方法名()
 * JNIEnv 指针
 *
 * 参数介绍 :
 * env : 代表Java环境, 通过这个环境可以调用Java中的方法
 * thiz : 代表调用JNI方法的对象, 即Activity对象
 */

jstring JNICALL Java_com_wochacha_learnjni_utils_helloFromJNI(JNIEnv *env,jclass arg){

    /*
     * 调用 android-ndk-r9c\platforms\android-8\arch-arm\usr\include 中jni.h中的方法
     * jni.h 中定义的方法  jstring (*NewStringUTF)(JNIEnv*, const char*);
     */
        return (*env)->NewStringUTF(env,"hello jni");
}

jint JNICALL Java_com_wochacha_learnjni_utils_Add(JNIEnv *env, jclass arg, jint a, jint b){
    return a + b;
}

#ifdef __cplusplus
}
#endif


