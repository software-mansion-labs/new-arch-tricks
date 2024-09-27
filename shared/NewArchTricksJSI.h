#include "NewArchTricksCommitHook.h"

namespace newarchtricks {

class NewArchTricksJSI {
public:
  static void install(
    facebook::jsi::Runtime &runtime,
    std::shared_ptr<NewArchTricksCommitHook> &commitHook
  );
};

} // namespace newarchtricks
