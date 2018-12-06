//
//  Defer.h
//  HSCore
//
//  Created by Kyle Hankinson on 2017-12-19.
//  Copyright © 2017 Hankinsoft Development, Inc. All rights reserved.
//

#ifndef Defer_h
#define Defer_h

// Similar to defer in Swift
// See https://pspdfkit.com/blog/2017/even-swiftier-objective-c/

#define pspdf_defer_block_name_with_prefix(prefix, suffix) prefix ## suffix
#define pspdf_defer_block_name(suffix) pspdf_defer_block_name_with_prefix(pspdf_defer_, suffix)
#define pspdf_defer __strong void(^pspdf_defer_block_name(__LINE__))(void) __attribute__((cleanup(pspdf_defer_cleanup_block), unused)) = ^
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
static void pspdf_defer_cleanup_block(__strong void(^*block)(void)) {
    (*block)();
}
#pragma clang diagnostic pop

#if DEBUG
#define PSPDF_KEYPATH(object, property) ((void)(NO && ((void)object.property, NO)), @ #property)
#else
#define PSPDF_KEYPATH(object, property) @ #property
#endif

#define DISPATCH_ONCE(block) { \
static dispatch_once_t pred = 0; \
dispatch_once(&pred, ^{ \
  block(); \
}); \
} \

#define mustOverride() {\
NSString * logString = [NSString stringWithFormat:@"%@ must be overridden in a subclass/category", NSStringFromSelector(_cmd)];\
NSLog(@"%@", logString);\
@throw [NSException exceptionWithName:NSInvalidArgumentException reason: logString userInfo:nil]; \
}

#endif /* Defer_h */
