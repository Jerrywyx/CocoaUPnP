// CocoaUPnP by A&R Cambridge Ltd, http://www.arcam.co.uk
// Copyright 2015 Arcam. See LICENSE file.

#import <Foundation/Foundation.h>
#import "UPPServiceDescription.h"

@class UPPSessionManager;

/** This class serves as a base class for all UPnP services
 */
@interface UPPBasicService : NSObject

typedef void (^UPPResponseBlock)(NSDictionary *, NSError *);

#pragma mark - Properties

///-----------------------------------------------------------------------------
/// @name Properties
///-----------------------------------------------------------------------------

/**
 The session manager instance to perform the network requests with
 */
@property (strong, nonatomic) UPPSessionManager *sessionManager;

/**
 The service's control point URL
 */
@property (copy, nonatomic) NSURL *controlURL;

/**
 The service's event subscription URL
 */
@property (copy, nonatomic) NSURL *eventSubscriptionURL;

/**
 The service type of the control point
 */
@property (copy, nonatomic) NSString *serviceType;


#pragma mark - Methods

///-----------------------------------------------------------------------------
/// @name Methods
///-----------------------------------------------------------------------------

/**
 A convenience initialiser for creating a new service from a base URL and
 `UPPServiceDescription`

 @param baseURL     The base URL for the service
 @param description The basic service description

 @return A new basic service instance
 */
+ (instancetype)serviceWithBaseURL:(NSURL *)baseURL description:(UPPServiceDescription *)description;

/**
 Send a POST request, with an error pointer

 @param instanceId The instance identifier
 @param action     The UPnP action
 @param parameters UPnP parameters
 @param error      An error pointer which will be populated in the event of the
     call failing
 */
- (void)_sendPostRequestWithInstanceID:(NSString *)instanceId action:(NSString *)action parameters:(NSDictionary *)parameters error:(NSError * __autoreleasing *)error;

/**
 Send a POST request, with a completion block

 @param instanceId The instance identifier
 @param action     The UPnP action
 @param completion A completion block either returning a dictionary response, or
     an error if the call failed
 */
- (void)_sendPostRequestWithInstanceID:(NSString *)instanceId action:(NSString *)action completion:(void (^)(NSDictionary *responseObject, NSError *error))completion;

/**
 Send a POST request, with a completion block

 @param parameters The parameters for the call
 @param action     The UPnP action
 @param completion A completion block either returning a dictionary response, or
     an error if the call failed
 */
- (void)_sendPostRequestWithParameters:(NSDictionary *)parameters action:(NSString *)action completion:(void (^)(NSDictionary *responseObject, NSError *error))completion;
@end
