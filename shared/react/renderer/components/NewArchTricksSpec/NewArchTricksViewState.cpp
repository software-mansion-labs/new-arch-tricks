#include <react/renderer/components/NewArchTricksSpec/NewArchTricksViewState.h>

namespace facebook::react {

float NewArchTricksViewState::getStatusBarWidth() const {
  return statusBarWidth_;
}

float NewArchTricksViewState::getStatusBarHeight() const {
  return statusBarHeight_;
}

}
