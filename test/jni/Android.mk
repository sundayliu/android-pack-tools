LOCAL_PATH:=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:=test1
LOCAL_SRC_FILES:=test1.c
LOCAL_ARM_MODE:=thumb

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_MODULE:=test2
LOCAL_SRC_FILES:=test2.c
LOCAL_ARM_MODE:=thumb
include $(BUILD_SHARED_LIBRARY)