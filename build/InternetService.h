//
//  InternetService.h
//  GoPlaySDK
//
//  Created by furyvn on 6/6/16.
//  Copyright © 2016 furyvn. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 * @brief : InternetService base from NSURLSession for request data from internet
 */
@interface InternetService : NSURLSession<NSURLSessionDataDelegate>

@property(nonatomic, retain) NSURLSessionDataTask* connection;
@property(nonatomic, retain) NSURLSession* session;
@property(nonatomic, retain) NSData* sendData;
@property(nonatomic, retain) NSMutableDictionary* errorDict;
@property(nonatomic, copy) void (^complete)(NSDictionary* dic);
@property(nonatomic, copy) void (^error)(NSDictionary* dic);
@property(nonatomic, readonly) id<NSURLSessionDataDelegate> delegate;

+(id) shareInstance;

/*!
 * @discussion Request data from internet. supported for POST and GET
 * @param url An NSURL define url api
 * @param method An NSString define method is POST or GET
 * @param data An NSDictionary define data will sent to server
 * @return void.
 */
-(void) requestDataWithURL:(NSURL*) url withMethod:(NSString*) method withData:(NSDictionary*) data;

@end
