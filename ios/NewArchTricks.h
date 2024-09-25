
#ifdef RCT_NEW_ARCH_ENABLED
#import "RNNewArchTricksSpec.h"

@interface NewArchTricks : NSObject <NativeNewArchTricksSpec>
#else
#import <React/RCTBridgeModule.h>

@interface NewArchTricks : NSObject <RCTBridgeModule>
#endif

@end
