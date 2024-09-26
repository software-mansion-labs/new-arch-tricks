#pragma once

#ifdef ANDROID
#include <folly/dynamic.h>
#endif

namespace facebook::react {

class NewArchTricksViewState {
public:
  NewArchTricksViewState() = default;

#ifdef ANDROID
  NewArchTricksViewState(NewArchTricksViewState const &previousState, folly::dynamic data){};
  folly::dynamic getDynamic() const {
    return {};
  };
#endif
};

} // namespace facebook::react