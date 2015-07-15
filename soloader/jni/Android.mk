LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE:=soloader
#LOCAL_SRC_FILES:=soloader.c
LOCAL_SRC_FILES:=soloader1.c
include $(BUILD_EXECUTABLE)