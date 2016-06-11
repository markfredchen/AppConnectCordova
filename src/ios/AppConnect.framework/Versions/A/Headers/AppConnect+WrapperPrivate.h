//
//  AppConnect+WrapperPrivate.h
//  MobileIron-only APIs for use by AppConnect Wrapper and MobileIron apps
//
//  Copyright (c) 2013 MobileIron. All rights reserved.
//

#import "AppConnect.h"
#import <UIKit/UIKit.h>

@interface AppConnect (WrapperPrivate)

// Used by wrapper:
+(void)initPrivateWithDelegate:(id<AppConnectDelegate>)appConnectDelegate version:(NSString *)version swizzledMethods:(NSDictionary*)swizzledMethods;
+(BOOL)isAppScheme:(NSURL *)url;
+(NSSet *)acPasteboardTypePrefixes;
-(void)sendEvent:(UIEvent *)event;
+(void)wrapperLogAtLevel:(ACLogLevel)logLevel message:(NSString *)message;
+(void)wrapperLogAtLevel:(ACLogLevel)logLevel format:(NSString*)format, ...;
+(void)wrapperLogAtLevel:(ACLogLevel)logLevel format:(NSString*)format args:(va_list)args;
// AP-1922: Private API for the wrapper to check if the app has the bus keys. If yes then the wrapper
-(BOOL)isReadyToTerminate;
-(void)willExit;
-(NSDictionary *)getAppInfo;
-(void)postPasscodeExtensionResult:(NSDictionary *)resultsDictionary;
-(BOOL)isCheckInRequested;

// Used by MI apps
-(void)setPrivateReport:(NSDictionary *)privateReport;

// Chromium Library related
-(void)clearCookies;
-(BOOL)isChromiumStackEnabled;
-(void)enableChromiumHTTPStack;

// Used by Cordova Plugin for determine URLs in whitelist
-(BOOL)URLIsAllowed:(NSURL*)url;
// Used by Cordova Plugin since the init happens well after appDidFinishLoading and appDidBecomeActive
-(void)cleanupAfterLateInit;

// OBSOLETE:: This was used by version 1.5.x of the wrapper. Use +initPrivateWithDelegate:version: instead.
+(void)initPrivateWithProxyingAndDelegate:(id<AppConnectDelegate>)appConnectDelegate version:(NSString *)version;
+(void)initPrivateWithDelegate:(id<AppConnectDelegate>)appConnectDelegate version:(NSString *)version;

-(UIPasteboard *)proxyForPasteboard:(UIPasteboard *)pasteboard;
@end

@protocol AppConnectDelegatePrivate <AppConnectDelegate>
@required

// Requests wrapper to authenticate the user.
-(void)authenticateUser;

// Queries the wrapper to check if the app is capable of displaying passcode extension.
-(BOOL)canAppDisplayPasscodeExtension;

// Checks if the passcode extension is currently being displayed.
-(BOOL)isPasscodeExtensionActive;

@end
