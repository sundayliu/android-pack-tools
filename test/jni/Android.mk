LOCAL_PATH:=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:=test1
LOCAL_SRC_FILES:=test1.c

include $(BUILD_EXECUTABLE)