#import <React/RCTViewManager.h>

@interface NewArchTricksViewManager : RCTViewManager
@end

@implementation NewArchTricksViewManager

RCT_EXPORT_MODULE(NewArchTricksView)
RCT_EXPORT_VIEW_PROPERTY(color, NSString)

@end
