#pragma once

#include <react/renderer/components/NewArchTricksSpec/EventEmitters.h>
#include <react/renderer/components/NewArchTricksSpec/Props.h>
#include <react/renderer/components/view/ConcreteViewShadowNode.h>
#include <react/renderer/components/NewArchTricksSpec/NewArchTricksViewState.h>
#include <jsi/jsi.h>

namespace facebook::react {

JSI_EXPORT extern const char NewArchTricksViewComponentName[];

/*
 * `ShadowNode` for <NewArchTricksView> component.
 */
class NewArchTricksViewShadowNode final : public ConcreteViewShadowNode<
    NewArchTricksViewComponentName,
    NewArchTricksViewProps,
    NewArchTricksViewEventEmitter,
    NewArchTricksViewState> {
  public:

  using ConcreteViewShadowNode::ConcreteViewShadowNode;
};

} // namespace facebook::react
