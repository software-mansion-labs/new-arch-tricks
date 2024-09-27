#include "NewArchTricksCommitHook.h"

using namespace facebook::react;

namespace newarchtricks {

NewArchTricksCommitHook::NewArchTricksCommitHook(const std::shared_ptr<UIManager> &uiManager) : uiManager_(uiManager) {
  uiManager_->registerCommitHook(*this);
}

NewArchTricksCommitHook::~NewArchTricksCommitHook() noexcept {
  uiManager_->unregisterCommitHook(*this);
}

void NewArchTricksCommitHook::registerNode(ShadowNode::Shared node) {
  nodes_[node->getTag()] = node;
}

void NewArchTricksCommitHook::unregisterNode(ShadowNode::Shared node) {
  nodes_.erase(node->getTag());
}

RootShadowNode::Unshared NewArchTricksCommitHook::shadowTreeWillCommit(
    ShadowTree const &,
    RootShadowNode::Shared const &oldRootShadowNode,
    RootShadowNode::Unshared const &newRootShadowNode) noexcept {
  auto rootNode = newRootShadowNode->ShadowNode::clone(ShadowNodeFragment{});

  for (const auto &node : nodes_) {
      const auto newRoot = rootNode->cloneTree(node.second->getFamily(), [](const ShadowNode& oldShadowNode) {
          auto clone = oldShadowNode.clone({.state = oldShadowNode.getState()});
          
          if (const auto layoutableNode = std::dynamic_pointer_cast<YogaLayoutableShadowNode>(clone)) {
              layoutableNode->setSize({.width = 100, .height = 100});
          }
          
          return clone;
      });
      
      if (newRoot) {
          rootNode = newRoot;
      }
  }

  return std::static_pointer_cast<RootShadowNode>(rootNode);
}

}
