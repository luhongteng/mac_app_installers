//
//  SQLProSSHTunnelHelper.h
//
//  Created by Kyle Hankinson on 2017-11-14.
//  Copyright © 2017 Hankinsoft Development, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

// Do not change these values. They are used to save information to
// our users keychain.
#define SSHTunnelErrorDomain                    @"com.hankinsoft.sqlpro.sshtunnel"
#define SSHTunnelHostDataKey                    (SSHTunnelErrorDomain @".hostdatakey")
#define SSHTunnelFingerprintKey                 (SSHTunnelErrorDomain @".fingerprintkey")
#define SSHTunnelUnknownFingerprintErrorCode    (1024)

#define SSHKnownHostsKey                        @"com.hankinsoft.sqlpro.sshtunnel.knownhosts"

@class SQLProSSHTunnelHelper;

@protocol HSSTunnelFingerprintDelegate

- (NSData*) SSHTunnel: (SQLProSSHTunnelHelper*) tunnelHelper
           keyForHost: (NSString*) host
                 port: (NSUInteger) port;

@end

@protocol HSSTunnelDelegate <NSObject>

- (NSString*) SSHTunnel: (SQLProSSHTunnelHelper*) tunnelHelper
        requestPasswordForUser: (NSString*) username;

- (NSURL*)   SSHTunnel: (SQLProSSHTunnelHelper*) tunnelHelper
      requestSecureURL: (NSString*) filePath;

- (NSArray*) SSHTunnel: (SQLProSSHTunnelHelper*) tunnelHelper
        requestPrompts: (NSArray*) prompts;

- (NSURL*)   SSHTunnel: (SQLProSSHTunnelHelper*) tunnelHelper
requestPublicKeyAccess: (NSURL*) url;

@end

typedef NSString* (^HSSSHTunnelRequestPasswordBlock) (void);
typedef NSArray* (^HSSSHTunnelRequestPromptsBlock) (NSArray * prompts);

@interface SQLProSSHTunnelHelper : NSObject

+ (void) setFingerprintDelegate: (id<HSSTunnelFingerprintDelegate>) fingerprintDelegate;

- (BOOL) connect;
- (void) disconnect;

@property(nonatomic,weak)   id representedObject;

@property(nonatomic,copy)   NSString * sshHostName;
@property(nonatomic,copy)   NSString * sshPassword;
@property(nonatomic,assign) BOOL     sshRememberPassword;
@property(nonatomic,copy)   NSString * sshUsername;

@property(nonatomic,assign) NSUInteger sshPort;

@property(nonatomic,copy)   NSString * forwardToHost;
@property(nonatomic,assign) NSUInteger forwardToPort;

@property(nonatomic,copy)   NSString * sshPrivateKeyPath;
@property(nonatomic,copy)   NSString * sshPrivateKeyPassword;

@property(nonatomic,weak) id<HSSTunnelDelegate> tunnelDelegate;

// Note: Should only be used for debugging purpose
@property(nonatomic,assign) BOOL sshIgnoreHostKey;

- (NSUInteger) localPort;
- (NSError*) error;

@end

