//
//  Contanst.h
//  GoPlaySDK
//
//  Created by furyvn on 6/6/16.
//  Copyright © 2016 furyvn. All rights reserved.
//

#import <Foundation/Foundation.h>
/*!
 * @brief : Contanst define all contanst value for SDK
 */

@interface Contanst : NSObject
{
    NSString* root;
    NSString* version;
    NSString* app_playtoken_id;
    NSString* customer_service;
    NSString* tracking_mobite;
    NSString* supersonic_game;
    NSString* adxmi_game;
    NSString* movista_game;
    NSString* mobite_game;
    int id_number;

}

@property(nonatomic,retain) NSString* GAME_ID;
@property(nonatomic,retain) NSString* ROOT;
@property(nonatomic,retain) NSString* VERSION;
@property(nonatomic,retain) NSString* SUPERSONIC_GAME;
@property(nonatomic,retain) NSString* ADXMI_GAME;
@property(nonatomic,retain) NSString* MOBVISTA_GAME;
@property(nonatomic,retain) NSString* MOBITE_GAME;
@property(nonatomic,retain) NSString* APP_PLAYTOKEN_ID;
@property(nonatomic,retain) NSString* LINK_FORGOT_PASS;
@property(nonatomic,retain) NSString* LOGIN;
@property(nonatomic,retain) NSString* LOGIN_OAUTH;
@property(nonatomic,retain) NSString* BIND_OAUTH;
@property(nonatomic,retain) NSString* UNBIND_OAUTH;
@property(nonatomic,retain) NSString* CHECK_OAUTH_BINDING;
@property(nonatomic,retain) NSString* SEND_PHONE_NUMBER;
@property(nonatomic,retain) NSString* REGISTER;
@property(nonatomic,retain) NSString* VERIFY_CODE;
@property(nonatomic,retain) NSString* PLAYTOKEN_LIST_GAME;
@property(nonatomic,retain) NSString* DOWNLOAD;
@property(nonatomic,retain) NSString* POINT_PLAYTOKEN;
@property(nonatomic,retain) NSString* EXCHANGE_PLAYTOKEN;
@property(nonatomic,retain) NSString* POINT_CC;
@property(nonatomic,retain) NSString* EXCHANGE_CC;
@property(nonatomic,retain) NSString* REFERRAL_HISTORY;
@property(nonatomic,retain) NSString* GET_POINT;
@property(nonatomic,retain) NSString* CHECK_VENVICI_MEMBER;
@property(nonatomic,retain) NSString* LIST_COUNTRY;
@property(nonatomic,retain) NSString* CHECK_VERIFY;
@property(nonatomic,retain) NSString* DOWNLOAD_HISTORY;
@property(nonatomic,retain) NSString* REWARD_HISTORY;
@property(nonatomic,retain) NSString* ALL_HISTORY;
@property(nonatomic,retain) NSString* FEEDBACK;
@property(nonatomic,retain) NSString* WALLET_RATE;
@property(nonatomic,retain) NSString* GET_COUNTRY;
@property(nonatomic,retain) NSString* VALID_COUNTRIES;
@property(nonatomic,retain) NSString* CUSTOMER_SERVICE;
@property(nonatomic,retain) NSString* TRACKING_MOBITE;
@property(nonatomic,retain) NSString* DEVICE_ID;
@property(nonatomic,retain) NSString* APP_ID;
@property(nonatomic,retain) NSString* GET_DEVICE_ID;
@property(nonatomic,retain) NSString* SET_DEVICE_ID;
@property(nonatomic,retain) NSString* ACCOUNT_PROFILE;
@property(nonatomic,retain) NSString* ACCOUNT_PROFILE_EDIT;

-(NSString*) getRootUrl;
-(NSString*) getVersion;
-(NSString*) getSupersonicGame;
-(NSString*) getAdxmiGame;
-(NSString*) getMovistaGame;
-(NSString*) mobiteGame;
-(NSString*) getAppPlaytokenID;
-(NSString*) getCustomerService;
-(NSString*) getTrackingMobile;
-(int) getVersionNumber;
+(id) shareInstance;

/*!
 * @discussion Merge two NSDictionary
 * @param sourceDict An NSDictionary define source dictionary
 * @param targetDict An NSDictionary define source dictionary
 * @return merge dictionary.
 */
-(NSDictionary*) mergeDictionaryWithSource : (NSDictionary*) sourceDict andTarget:(NSDictionary*) targetDict;

@end