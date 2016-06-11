//
//  ACTunnelingConfigProtocol.h
//  AppConnectLibrary
//
//  Copyright (c) 2012-2016 MobileIron. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *kHeaderKeyKey;
extern NSString *kHeaderValueKey;

extern NSString *kDomainRegexPatternKey;
extern NSString *kPortKey;
extern NSString *kServiceKey;
extern NSString *kSentryIDKey;

extern NSString *kSentryCertKey;
extern NSString *kExternalHostnameKey;
extern NSString *kExternalPortKey;
extern NSString *kProtocolVersionKey;

// ACTunnelingConfigProtocol consists of the "getters" for the properties needed by Help@Work

@protocol ACTunnelingConfigProtocol <NSObject>
@required
- (NSArray *)headerLines;
- (NSData *)clientCert;
- (NSString *)clientCertPasssword;
- (NSArray *)rules;
- (NSDictionary *)sentries;
@end
