#include <fbjni/fbjni.h>

#include "NewArchTricksModule.h"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *) {
  return facebook::jni::initialize(vm, [] {
    newarchtricks::NewArchTricksModule::registerNatives();
  });
}
