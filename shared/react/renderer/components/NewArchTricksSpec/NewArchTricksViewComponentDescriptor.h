#pragma once

#include <react/debug/react_native_assert.h>
#include <react/renderer/components/NewArchTricksSpec/Props.h>
#include <react/renderer/core/ConcreteComponentDescriptor.h>
#include <react/renderer/components/NewArchTricksSpec/NewArchTricksViewShadowNode.h>

namespace facebook {
namespace react {

class NewArchTricksViewComponentDescriptor final
    : public ConcreteComponentDescriptor<NewArchTricksViewShadowNode> {
 public:
  using ConcreteComponentDescriptor::ConcreteComponentDescriptor;

  void adopt(ShadowNode &shadowNode) const override {
    react_native_assert(dynamic_cast<NewArchTricksViewShadowNode *>(&shadowNode));

    const auto newArchTricksViewShadowNode = dynamic_cast<NewArchTricksViewShadowNode *>(&shadowNode);
    const auto state = newArchTricksViewShadowNode->getStateData();
    
    newArchTricksViewShadowNode->setSize({state.getStatusBarWidth(), state.getStatusBarHeight()});
      
    ConcreteComponentDescriptor::adopt(shadowNode);
  }
};

} // namespace react
} // namespace facebook
