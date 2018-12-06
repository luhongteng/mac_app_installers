//
//  SQLProSSHTunnel.h
//  SQLProSSHTunnel
//
//  Created by Kyle Hankinson on 2017-11-14.
//  Copyright © 2017 Hankinsoft Development, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
@import UIKit;
#endif
#if !TARGET_OS_IPHONE && TARGET_OS_MAC
@import AppKit;
#endif

//! Project version number for SQLProSSHTunnel.
FOUNDATION_EXPORT double SQLProSSHTunnelVersionNumber;

//! Project version string for SQLProSSHTunnel.
FOUNDATION_EXPORT const unsigned char SQLProSSHTunnelVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SQLProSSHTunnel/PublicHeader.h>
#import "SQLProSSHTunnelHelper.h"
