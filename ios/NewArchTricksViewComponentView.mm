#import "NewArchTricksViewComponentView.h"

// without this header the provider won't be found by RN
#import <React/RCTFabricComponentsPlugins.h>

// import custom header so we can use our own component descriptor
#import <NewArchTricks/NewArchTricksViewComponentDescriptor.h>
#import <react/renderer/components/NewArchTricksSpec/EventEmitters.h>
#import <react/renderer/components/NewArchTricksSpec/Props.h>
#import <react/renderer/components/NewArchTricksSpec/RCTComponentViewHelpers.h>

using namespace facebook::react;

@interface NewArchTricksViewComponentView () <RCTNewArchTricksViewViewProtocol>
@end

@implementation NewArchTricksViewComponentView {
  UIView *_customView;
}

// Needed because of this: https://github.com/facebook/react-native/pull/37274
+ (void)load
{
  [super load];
}

- (instancetype)initWithFrame:(CGRect)frame
{
  if (self = [super initWithFrame:frame]) {
    static const auto defaultProps = std::make_shared<const NewArchTricksViewProps>();
    _props = defaultProps;
    _customView = [[UIView alloc] initWithFrame:self.bounds];

    self.contentView = _customView;
  }

  return self;
}

- hexStringToColor:(NSString *)stringToConvert
{
  NSString *noHashString = [stringToConvert stringByReplacingOccurrencesOfString:@"#" withString:@""];
  NSScanner *stringScanner = [NSScanner scannerWithString:noHashString];

  unsigned hex;
  if (![stringScanner scanHexInt:&hex]) return nil;
  int r = (hex >> 16) & 0xFF;
  int g = (hex >> 8) & 0xFF;
  int b = (hex) & 0xFF;

  return [UIColor colorWithRed:r / 255.0f green:g / 255.0f blue:b / 255.0f alpha:1.0f];
}

#pragma mark - RCTComponentViewProtocol

+ (ComponentDescriptorProvider)componentDescriptorProvider
{
  return concreteComponentDescriptorProvider<NewArchTricksViewComponentDescriptor>();
}

- (void)updateProps:(const Props::Shared &)props oldProps:(const Props::Shared &)oldProps
{
  const auto &newProps = *std::static_pointer_cast<const NewArchTricksViewProps>(props);
    
  [_customView setBackgroundColor:[self hexStringToColor:[NSString stringWithUTF8String:newProps.color.c_str()]]];

  [super updateProps:props oldProps:oldProps];
}
@end

Class<RCTComponentViewProtocol> NewArchTricksViewCls(void)
{
  return NewArchTricksViewComponentView.class;
}
