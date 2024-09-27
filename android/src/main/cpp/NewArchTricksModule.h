#pragma once

#include <ReactCommon/BindingsInstallerHolder.h>
#include <react/fabric/JFabricUIManager.h>
#include <fbjni/fbjni.h>
#include <NewArchTricksCommitHook.h>

#include <string>

namespace newarchtricks {

using namespace facebook;
using namespace facebook::jni;

class NewArchTricksModule : public jni::HybridClass<NewArchTricksModule> {
 public:
  static auto constexpr kJavaDescriptor =
      "Lcom/newarchtricks/NewArchTricksModule;";
  static jni::local_ref<jhybriddata> initHybrid(jni::alias_ref<jhybridobject> jThis);
  static void registerNatives();

  ~NewArchTricksModule();

 private:
  friend HybridBase;
  jni::global_ref<NewArchTricksModule::javaobject> javaPart_;
  std::shared_ptr<NewArchTricksCommitHook> commitHook_;

  explicit NewArchTricksModule(jni::alias_ref<NewArchTricksModule::javaobject> jThis);

  void createCommitHook(
      jni::alias_ref<facebook::react::JFabricUIManager::javaobject> fabricUIManager);

  jni::local_ref<BindingsInstallerHolder::javaobject> getBindingsInstallerCxx();
};

} // namespace newarchtricks
