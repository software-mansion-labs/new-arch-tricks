#pragma once

#include <react/renderer/uimanager/UIManager.h>
#include <react/renderer/uimanager/UIManagerCommitHook.h>

using namespace facebook::react;

namespace newarchtricks {

class NewArchTricksCommitHook : public UIManagerCommitHook {
public:
  NewArchTricksCommitHook(const std::shared_ptr<UIManager> &uiManager);

  ~NewArchTricksCommitHook() noexcept override;

  void commitHookWasRegistered(UIManager const &) noexcept override {}

  void commitHookWasUnregistered(UIManager const &) noexcept override {}

  RootShadowNode::Unshared shadowTreeWillCommit(
      ShadowTree const &shadowTree,
      RootShadowNode::Shared const &oldRootShadowNode,
      RootShadowNode::Unshared const &newRootShadowNode)
    noexcept override;
    
private:
  std::shared_ptr<UIManager> uiManager_;
};

}
