TRUNK_DIR := $(MOBILE_PAY_TRUNK)

LOCAL_CFLAGS := -DANDROID_NDK \
                -w
                
LOCAL_C_INCLUDES := \
        $(ANDROID_NDK_ROOT)/build/platforms/android-8/arch-arm/usr/include \
        $(ANDROID_NDK_ROOT)/build/platforms/android-8/arch-arm/usr/include/android \
        up_comm/UPChannel/inc \
        up_comm/UPCrypto/inc \
        up_comm/UPUtil/inc \
        UPUtil_JDK/inc \
        platform


LOCAL_LDLIBS := -ldl -llog