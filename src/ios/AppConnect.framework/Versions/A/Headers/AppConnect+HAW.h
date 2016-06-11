//
//  AppConnect+HAW.h
//  Help@Work
//
//  Created by Paul Surma on 2/1/16.
//  Copyright (c) 2016 MobileIron, Inc. All rights reserved.
//

#import "AppConnect.h"
#import "ACTunnelingConfigProtocol.h"

@interface AppConnect (HelpAtWork)
- (id<ACTunnelingConfigProtocol>)acTunnelingConfigForHelpAtWork;
@end
