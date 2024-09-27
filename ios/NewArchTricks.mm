#import "NewArchTricks.h"

#import <React/RCTBridge+Private.h>
#import <React/RCTBridge.h>
#import <React/RCTBridgeModule.h>
#import <React/RCTScheduler.h>
#import <React/RCTSurfacePresenter.h>
#import <React/RCTSurfacePresenterStub.h>
#import <React/RCTUtils.h>
#import <ReactCommon/CallInvoker.h>
#import <ReactCommon/RCTTurboModule.h>
#import <ReactCommon/RCTTurboModuleWithJSIBindings.h>
#import <NewArchTricks/NewArchTricksCommitHook.h>
#import <NewArchTricks/NewArchTricksJSI.h>

#import <react/renderer/uimanager/primitives.h>

@interface NewArchTricks () <RCTTurboModuleWithJSIBindings>
@end

@implementation NewArchTricks {
 __weak RCTSurfacePresenter* _surfacePresenter;
 std::shared_ptr<newarchtricks::NewArchTricksCommitHook> commitHook_;
}

RCT_EXPORT_MODULE()

- (NSNumber *)multiply:(double)a b:(double)b
{
    return [[NSNumber alloc] initWithDouble:a * b];
}

- (void)install
{
 commitHook_ = std::make_shared<newarchtricks::NewArchTricksCommitHook>(_surfacePresenter.scheduler.uiManager);
}

- (void)installJSIBindingsWithRuntime:(facebook::jsi::Runtime &)runtime
{
  newarchtricks::NewArchTricksJSI::install(runtime, commitHook_);
}

- (void)setSurfacePresenter:(id<RCTSurfacePresenterStub>)surfacePresenter
{
 _surfacePresenter = surfacePresenter;
}

- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:(const facebook::react::ObjCTurboModule::InitParams &)params
{
  return std::make_shared<facebook::react::NativeNewArchTricksModuleSpecJSI>(params);
}

@end
