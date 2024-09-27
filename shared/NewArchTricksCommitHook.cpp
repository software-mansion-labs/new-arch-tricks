#include "NewArchTricksCommitHook.h"

using namespace facebook::react;

namespace newarchtricks {

NewArchTricksCommitHook::NewArchTricksCommitHook(const std::shared_ptr<UIManager> &uiManager) : uiManager_(uiManager) {
  uiManager_->registerCommitHook(*this);
}

NewArchTricksCommitHook::~NewArchTricksCommitHook() noexcept {
  uiManager_->unregisterCommitHook(*this);
}

RootShadowNode::Unshared NewArchTricksCommitHook::shadowTreeWillCommit(
    ShadowTree const &,
    RootShadowNode::Shared const &,
    RootShadowNode::Unshared const &newRootShadowNode) noexcept {
  auto rootNode = newRootShadowNode->ShadowNode::clone(ShadowNodeFragment{});
  
  return std::static_pointer_cast<RootShadowNode>(rootNode);
}

}
