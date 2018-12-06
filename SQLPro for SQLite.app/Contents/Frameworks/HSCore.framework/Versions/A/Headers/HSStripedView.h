//
//  HSStripedView.h
//  HSCore
//
//  Created by Kyle Hankinson on 2018-01-31.
//  Copyright © 2018 Hankinsoft Development, Inc. All rights reserved.
//

#if TARGET_OS_IPHONE
@import UIKit;
#elif TARGET_OS_MAC
@import Foundation;
#endif

#if TARGET_OS_IPHONE
@interface HSStripedView : UIView
#elif TARGET_OS_MAC
IB_DESIGNABLE
@interface HSStripedView : NSView
#endif

@property(nonatomic,assign) CGFloat leftOffset;
@property(nonatomic,assign) IBInspectable CGFloat lineThickness;
@property(nonatomic,assign) IBInspectable CGFloat lineGap;

@end
