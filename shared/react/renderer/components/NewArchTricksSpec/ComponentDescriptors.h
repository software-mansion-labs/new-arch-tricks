#pragma once

#include <react/renderer/components/NewArchTricksSpec/ShadowNodes.h>
#include <react/renderer/core/ConcreteComponentDescriptor.h>
#include <react/renderer/componentregistry/ComponentDescriptorProviderRegistry.h>

#include <react/renderer/components/NewArchTricksSpec/NewArchTricksViewComponentDescriptor.h>

namespace facebook::react {

void NewArchTricksSpec_registerComponentDescriptorsFromCodegen(
  std::shared_ptr<const ComponentDescriptorProviderRegistry> registry);

} // namespace facebook::react
