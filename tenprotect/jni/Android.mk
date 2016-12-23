LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:=tp

LOCAL_SRC_FILES:= tp.c

LOCAL_CFLAGS := -fvisibility=hidden

LOCAL_LDLIBS:= -llog

LOCAL_LDFLAGS:= -Wl,--version-script=$(LOCAL_PATH)/tp_version_scripts.txt

include $(BUILD_SHARED_LIBRARY)