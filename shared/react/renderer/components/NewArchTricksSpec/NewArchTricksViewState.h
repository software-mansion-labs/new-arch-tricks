#pragma once

#ifdef ANDROID
#include <folly/dynamic.h>
#endif

namespace facebook::react {

class NewArchTricksViewState {
public:
  NewArchTricksViewState()
    : statusBarWidth_(0), statusBarHeight_(0) {}

  NewArchTricksViewState(float statusBarWidth, float statusBarHeight)
    : statusBarWidth_(statusBarWidth), statusBarHeight_(statusBarHeight) {}

#ifdef ANDROID
  NewArchTricksViewState(NewArchTricksViewState const &previousState, folly::dynamic data)
    : statusBarWidth_((float)data["statusBarWidth"].getDouble()),
    statusBarHeight_((float)data["statusBarHeight"].getDouble()){};
  folly::dynamic getDynamic() const {
    return {};
  };
#endif

  float getStatusBarWidth() const;
  float getStatusBarHeight() const;

private:
  const float statusBarWidth_{};
  const float statusBarHeight_{};
};

} // namespace facebook::react
