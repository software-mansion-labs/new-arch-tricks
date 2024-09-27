#include "NewArchTricksJSI.h"

namespace newarchtricks {

using namespace facebook;

void NewArchTricksJSI::install(
  facebook::jsi::Runtime &runtime,
  std::shared_ptr<NewArchTricksCommitHook> &commitHook
) {
    auto registerFamily = jsi::Function::createFromHostFunction(
        runtime,
        jsi::PropNameID::forAscii(runtime, "__NAT_registerNode"),
        1,
        [&](jsi::Runtime &runtime,
           const jsi::Value &thisValue,
           const jsi::Value *arguments,
           size_t count) -> jsi::Value {
            auto shadowNode = shadowNodeFromValue(runtime, arguments[0]);
            commitHook->registerNode(shadowNode);

            return jsi::Value::undefined();
        });
    runtime.global().setProperty(
                runtime, "__NAT_registerNode", std::move(registerFamily));

    auto unregisterFamily = jsi::Function::createFromHostFunction(
            runtime,
            jsi::PropNameID::forAscii(runtime, "__NAT_unregisterNode"),
            1,
            [&](jsi::Runtime &runtime,
                const jsi::Value &thisValue,
                const jsi::Value *arguments,
                size_t count) -> jsi::Value {
                auto shadowNode = shadowNodeFromValue(runtime, arguments[0]);
                commitHook->unregisterNode(shadowNode);

                return jsi::Value::undefined();
            });
    runtime.global().setProperty(
            runtime, "__NAT_unregisterNode", std::move(unregisterFamily));
}

} // namespace newarchtricks
