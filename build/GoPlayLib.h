//
//  GoPlayLib.h
//  GoPlayLib
//
//  Created by furyvn on 6/15/16.
//  Copyright © 2016 furyvn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AdSupport/AdSupport.h>
#import <UIKit/UIKit.h>
#import "TrackAndAd.h"
#import "InternetService.h"
#import "Contanst.h"

/*!
 * @brief : GoPlay SDK base from NSObject define all api need for Unity
 */
@interface GoPlayLib : NSObject<KochavaTrackerClientDelegate, KochavaiAdAttributionDelegate>
{
    NSString* device_id;
    NSString* app_id;
    NSString* game_id;
    NSString* kochava_app_id;
    Contanst* contanst;
    BOOL debug;
    
    KochavaTracker* kochavaTrackerInstance;
}

//MARK: GoPlay Config
-(NSString*) getGameID;
-(void) setGameID : (NSString*) gameID;
-(NSString*) getDeviceIDByGoPlaySDK;
-(void) setDebug: (BOOL) isDebug;
-(NSString*) getKochavaAppID;

//MARK: Playtoken API
/*!
 * @brief Check internet connection
 * @return false if no internet else return true.
 */
-(BOOL) checkDeviceInternetConnection;

/*!
 * @brief Logs a user in via their GToken username and password. The account must already exist.
 * @param user An NSDictionary define user information. The example information is : @c@{@"username":@"abc",@"password":@"123",@"game_id":@"game_id"};
 * @param complete An block that will call when data return
 * @param error An block that will call when some error fire
 * @return void.
 * @verion iOS 8.0+
 */
-(void) loginGoPlaySDKWithUser:(NSDictionary*) user complete:(void(^)(NSDictionary* dic)) complete error:(void(^)(NSDictionary* dic)) error;


/*!
 * @brief Log in via a third-party OAuth provider, e.g. Facebook. 
 Note that this API will not implicitly register the user if an account does not already exist, but return an error message instead.
 * @param user An NSDictionary define user information
 * @param complete An block that will call when data return
 * @param error An block that will call when some error fire
 * @return void.
 * @code user = @{@"service":@"",@"token":@"",@"game_id":@""};
 */
-(void) loginOauthGoPlaySDKWithUser:(NSDictionary*) user complete:(void(^)(NSDictionary* dic)) complete error:(void(^)(NSDictionary* dic)) error;

/*!
 * @brief Adds an OAuth login to an existing account. One account may have multiple OAuth logins.
 * @param user An NSDictionary define user information
 * @param complete An block that will call when data return
 * @param error An block that will call when some error fire
 * @return void.
 * @code user = @{@"session":@"", @"game_id":@"", @"service":@"", @"token":@""};
 */
-(void) connectOauthByGoPlaySDKWithData:(NSDictionary*) data complete:(void(^)(NSDictionary* dic)) complete error:(void(^)(NSDictionary* dic)) error;


/*!
 * @brief Disconnect an OAuth login from an existing account.
 * @param data An NSDictionary define user information
 * @param complete An block that will call when data return
 * @param error An block that will call when some error fire
 * @return void.
 * @code data = @{@"session":@"", @"game_id":@"", @"service":@"", @"token":@""};
 */
-(void) disconnectOauthByGoPlaySDKWithData:(NSDictionary*) data complete:(void(^)(NSDictionary* dic)) complete error:(void(^)(NSDictionary* dic)) error;


/*!
 * @brief Query if the OAuth login (access token) was added to the given account (session).
 * @param data An NSDictionary define user information
 * @param complete An block that will call when data return
 * @param error An block that will call when some error fire
 * @return void.
 * @code data = @{@"session":@"", @"game_id":@"", @"service":@"", @"token":@""};
 * @endcode
 */
-(void) checkOauthConnectionByGoPlaySDKWithData:(NSDictionary*) data complete:(void(^)(NSDictionary* dic)) complete error:(void(^)(NSDictionary* dic)) error;


/*!
 * @brief Returns profile of logged-in user. May be used to check whether a session token is still valid.
 * @param data An NSDictionary define user information
 * @param complete An block that will call when data return
 * @param error An block that will call when some error fire
 * @return void.
 * @code data = @{@"session":@"", @"game_id":@""};
 */
-(void) getAccountProfileByGoPlaySDKWithData:(NSDictionary*) data complete:(void(^)(NSDictionary* dic)) complete error:(void(^)(NSDictionary* dic)) error;


/*!
 * @brief Updates profile of logged-in user. Parameters may be omitted, and those fields will be unchanged.
 * @param data An NSDictionary define user information
 * @param complete An block that will call when data return
 * @param error An block that will call when some error fire
 * @return void.
 * @code data = @{@"session":@"", @"game_id":@"", @"email":@"", @"nickname":@"", @"gender":@""};
 */
-(void) getAccountProfileEditByGoPlaySDKWithData:(NSDictionary*) data complete:(void(^)(NSDictionary* dic)) complete error:(void(^)(NSDictionary* dic)) error;


/*!
 * @brief Grant a user who logged via GToken to access chat system.
 * @param data An NSDictionary define user information
 * @param complete An block that will call when data return
 * @param error An block that will call when some error fire
 * @return void.
 * @code data = @{@"session":@"", @"game_id":@""};
 */
-(void) getGrantChatTokenByGoPlaySDKWithData:(NSDictionary*) data complete:(void(^)(NSDictionary* dic)) complete error:(void(^)(NSDictionary* dic)) error;


/*!
 * @brief Get Friend List
 * @param data An NSDictionary define user information
 * @param complete An block that will call when data return
 * @param error An block that will call when some error fire
 * @return void.
 * @code data = @{@"session":@"", @"game_id":@"", @"include_profile":@"", @"status":@""};
 */
-(void) getFriendListByGoPlaySDKWithData:(NSDictionary*) data complete:(void(^)(NSDictionary* dic)) complete error:(void(^)(NSDictionary* dic)) error;


/*!
 * @brief register user by GoPlay API
 * @param user An NSDictionary define user information
 * @param complete An block that will call when data return
 * @param error An block that will call when some error fire
 * @return void.
 * @code user = @{@"username":@"",@"password":@"",@"email":@"",@"nickname":@"",@"gender":@"",@"game_id":@"",@"referral_code":@"",@"ip_address":@"",@"country_code":@"",@"country_name":@""};
 */
-(void) registerGoPlaySDKWithUser:(NSDictionary*) user complete:(void(^)(NSDictionary* dic)) complete error:(void(^)(NSDictionary* dic)) error;


/*!
 * @brief set device id by GoPlay API. An NSDictionary define device information @{@"idv":@"abc",@"device_id":@"123",@"app_id":@"com.gtoken.gwallet",@"user_id":@"123",@"platform":@"iOS 8"}
 * @param complete An block that will call when data return
 * @param error An block that will call when some error fire
 * @return void.
 */
-(void) setDeviceIDGoPlaySDKByIDV:(void(^)(NSDictionary* dic)) complete error:(void(^)(NSDictionary* dic)) error;


/*!
 * @brief get device id by GoPlay API. An NSDictionary define device information @{@"idv":@"abc",@"device_id":@"123",@"app_id":@"com.gtoken.gwallet",@"user_id":@"123",@"platform":@"iOS 8"}
 * @param complete An block that will call when data return
 * @param error An block that will call when some error fire
 * @return void.
 */
-(void) getDeviceIDGoPlaySDKByIDV:(void(^)(NSDictionary* dic)) complete error:(void(^)(NSDictionary* dic)) error;


/*!
 * @brief get app id by GoPlay API. An NSDictionary define device information @{@"idv":@"abc",@"device_id":@"123",@"app_id":@"com.gtoken.gwallet",@"user_id":@"123",@"platform":@"iOS 8"}
 * @param complete An block that will call when data return
 * @param error An block that will call when some error fire
 * @return void.
 */
-(void) getAppIDGoPlaySDK:(void(^)(NSDictionary* dic)) complete error:(void(^)(NSDictionary* dic)) error;

//MARK: Tracking SDK
@property(nonatomic,retain) NSString* kochavaReceiveData;
/*!
 * @brief Create new kochava tracker with currency
 * @param currency An NSString to be used to define currency
 * @return void.
 */
-(void) initTracker:(NSString*) currency;

-(void) startSessionTracking;

-(void) endSessionTracking;


/*!
 * @brief tracking for login event by kochava
 * @param username An NSString to be used to define username
 * @return void.
 */
-(void) loginTracking:(NSString*) username;


/*!
 * @brief tracking for registration event by kochava
 * @param username An NSString to be used to define username
 * @param countryCode An NSString to be used to define country code. Ex : en, us, au
 * @return void.
 */
-(void) registrationTracking:(NSString*) username andCountryCode:(NSString*) countryCode;


/*!
 * @brief tracking for Tutorial Complete event by kochava
 * @param username An NSString to be used to define username
 * @param minsDuration An int to be used to define minutes that use to complete tutorial.
 * @return void.
 */
-(void) tutorialCompleteTracking:(NSString*) username andMinsDuration:(int) minsDuration;


/*!
 * @brief tracking for Game Paused event by kochava
 * @param username An NSString to be used to define username
 * @param screenName An NSString to be used to define creen name
 * @return void.
 */
-(void) pauseGameTracking:(NSString*) username andScreenName:(NSString*) screenName;


/*!
 * @brief tracking for Level Complete event by kochava
 * @param username An NSString to be used to define username
 * @param levelName An NSString to be used to define level name
 * @param levelNumber An int to be used to define level number
 * @return void.
 */
-(void) levelCompleteTracking:(NSString*) username andLevelName:(NSString*) levelName andLevelNumber:(int) levelNumber;


/*!
 * @brief tracking for Achievement Complete event by kochava
 * @param username An NSString to be used to define username
 * @param achievementName An NSString to be used to define Achievement Name
 * @param achievementReward An NSString to be used to define Achievement Reward
 * @return void.
 */
-(void) achievementCompleteTracking:(NSString*) username andAchievementName:(NSString*) achievementName andAchievementReward:(NSString*) achievementReward;


/*!
 * @brief tracking for Time Played event by kochava
 * @param username An NSString to be used to define username
 * @param minsPlayed An int to be used to define minutes that user playe game
 * @return void.
 */
-(void) timePlayedTracking:(NSString*) username andMinsPlayed:(int) minsPlayed;


/*!
 * @brief tracking for Purchase event by kochava
 * @param username An NSString to be used to define username
 * @param transaction_id An NSString to be used to define transaction id
 * @param exchange_option_type An NSString to be used to define exchange option type
 * @param exchange_option_identifier An NSString to be used to define exchange option identifier
 * @param goplay_token_value An NSString to be used to define goplay token value
 * @param quantity An int to be used to define quantity
 * @param is_free An int to be used to define is_free
 * @return void.
 */
-(void) purchaseTracking:(NSString*) username andTransactionID:(NSString*) transaction_id andExchangeOptionType:(NSString*) exchange_option_type andExchangeOptionIdentifier:(NSString*) exchange_option_identifier andGoplayTokenValue:(NSString*) goplay_token_value andQuantity:(int) quantity andIsFree:(BOOL) is_free;


/*!
 * @brief set delegate kochava
 * @param delegate An id to be used to define delegate
 * @return void.
 */
-(void) setKochavaDelegate:(id) delegate;


/*!
 * @brief log receive data from Kochava
 * @return void.
 */
-(void) logReceiveData;


/*!
 * @brief disable console log from Kochava
 * @return void.
 */
-(void) disableKovachaLog;


/*!
 * @brief calback for write log to server
 * @return void.
 */
-(void) wirteLogToServerWithEventname:(NSString*) eventname;

+(id) shareInstance;


@end
