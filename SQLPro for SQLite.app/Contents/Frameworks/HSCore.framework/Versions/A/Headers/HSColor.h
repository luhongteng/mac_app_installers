//
//  HSColor.h
//  HSCore
//
//  Created by Kyle Hankinson on 2017-01-10.
//  Copyright © 2017 Hankinsoft Development, Inc. All rights reserved.
//

@import Foundation;

#if TARGET_OS_IPHONE
@import UIKit;
#elif TARGET_OS_MAC
@import AppKit;
#endif

#ifndef HSColor_h
#define HSColor_h

#if TARGET_OS_IPHONE
#define HSColor UIColor
#define HSFont  UIFont
#else
#define HSColor NSColor
#define HSFont  NSFont
#endif

#endif /* HSColor_h */

@interface HSColor(ColorNamed)

+ (HSColor*) colorNamed: (NSString*) colorName
          fallbackColor: (HSColor*) fallbackColor;

@end
