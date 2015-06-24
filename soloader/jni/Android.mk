LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE:=soloader
LOCAL_SRC_FILES:=soloader.c
include $(BUILD_EXECUTABLE)