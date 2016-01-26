//
//  WebRequestController.h
//  WatchSugar
//
//  Created by Adam A. Wolf on 1/12/16.
//  Copyright © 2016 Flairify. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WebRequestController.h"

@class WatchWebRequestController;
@class AuthenticationController;

@protocol WatchWebRequestControllerDelegate <NSObject>

- (void)webRequestControllerDidFetchNewBloodSugarData:(WatchWebRequestController *)webRequestController;

@end

@interface WatchWebRequestController : NSObject

@property (nonatomic, weak) id<WatchWebRequestControllerDelegate> delegate;

@property (nonatomic, strong) AuthenticationController *authenticationController;

@property (nonatomic, strong) NSDictionary *latestBloodSugarData;

@property (nonatomic, strong) NSDate *lastFetchAttempt;

- (void)performFetch;
- (void)performFetchAndWait;

@end