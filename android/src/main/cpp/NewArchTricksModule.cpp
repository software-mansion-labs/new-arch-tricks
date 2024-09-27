#include <react/fabric/Binding.h>
#include <react/renderer/scheduler/Scheduler.h>

#include "NewArchTricksModule.h"

namespace newarchtricks {

using namespace facebook;
using namespace react;

NewArchTricksModule::NewArchTricksModule(jni::alias_ref<NewArchTricksModule::javaobject> jThis)
  : javaPart_(jni::make_global(jThis)) {

}

NewArchTricksModule::~NewArchTricksModule() {}

void NewArchTricksModule::registerNatives() {
  registerHybrid(
      {makeNativeMethod("initHybrid", NewArchTricksModule::initHybrid),
       makeNativeMethod("createCommitHook", NewArchTricksModule::createCommitHook)});
}

void NewArchTricksModule::createCommitHook(jni::alias_ref<facebook::react::JFabricUIManager::javaobject> fabricUIManager) {
  const auto &uiManager =
          fabricUIManager->getBinding()->getScheduler()->getUIManager();
  commitHook_ = std::make_shared<NewArchTricksCommitHook>(uiManager);
}

jni::local_ref<NewArchTricksModule::jhybriddata> NewArchTricksModule::initHybrid(jni::alias_ref<jhybridobject> jThis) {
  return makeCxxInstance(jThis);
}

} // namespace livemarkdown
