//
//  TuNetworkOperation.h
//  TuSDK
//
//  Created by Mugunth Kumar (@mugunthkumar) on 11/11/11.
//  Copyright (C) 2011-2020 by Steinlogic Consulting and Training Pte Ltd

//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//
//  Modified by Clear Hu on 15/2/3.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TuSDKPulseCore/TuNetworkEngine.h>
// 1 minute
#define kTuSDKNetworkKitDefaultCacheDuration 60

// 1 day (HEAD requests with eTag are sent only after expiry of this.
// Not that these are not RFC compliant, but needed for performance tuning)
#define kTuSDKNetworkKitDefaultImageHeadRequestDuration 3600*24*1 

// 1 day
#define kTuSDKNetworkKitDefaultImageCacheDuration 3600*24*7

// if your server takes longer than 30 seconds to provide real data,
// you should hire a better server developer.
// on iOS (or any mobile device), 30 seconds is already considered high.

#define kTuSDKNetworkKitDefaultRequestTimeOutInSeconds 30

@class TuNetworkOperation;

typedef enum {
    TuSDKNetworkOperationStateReady = 1,
    TuSDKNetworkOperationStateExecuting = 2,
    TuSDKNetworkOperationStateFinished = 3
} TuSDKNetworkOperationState;

typedef void (^LSQNKVoidBlock)(void);
typedef void (^LSQNKIDBlock)(void);
typedef void (^LSQNKResponseBlock)(TuNetworkOperation* completedOperation);

typedef void (^LSQNKErrorBlock)(NSError* error);

typedef void (^LSQNKAuthBlock)(NSURLAuthenticationChallenge* challenge);

typedef NSString* (^LSQNKEncodingBlock) (NSDictionary* postDataDict);

typedef enum {

    LSQNKPostDataEncodingTypeURL = 0, // default
    LSQNKPostDataEncodingTypeJSON,
    LSQNKPostDataEncodingTypePlist,
    LSQNKPostDataEncodingTypeCustom
} LSQNKPostDataEncodingType;
/*!
 @header TuNetworkOperation.h
 @abstract   Represents a single unique network operation.
 */

/*!
 *  @class MKNetworkOperation
 *  @abstract Represents a single unique network operation.
 *
 *  @discussion
 *	You normally create an instance of this class using the methods exposed by MKNetworkEngine
 *  Created operations are enqueued into the shared queue on MKNetworkEngine
 *  MKNetworkOperation encapsulates both request and response
 *  Printing a MKNetworkOperation prints out a cURL command that can be copied and pasted directly on terminal
 *  Freezable operations are serialized when network connectivity is lost and performed when connection is restored
 */
@interface TuNetworkOperation : NSOperation <NSURLConnectionDataDelegate> {
    
@private
    int _state;
    BOOL _freezable;
    LSQNKPostDataEncodingType _postDataEncoding;
}

/**
 *  default 60 (1 minute)
 */
@property (nonatomic) NSUInteger cacheDuration;

/**
 *  1 day (HEAD requests with eTag are sent only after expiry of this. 
 *  Not that these are not RFC compliant, but needed for performance tuning)
 */
@property (nonatomic) NSUInteger imageHeadRequestDuration;

/**
 *  1 day
 */
@property (nonatomic) NSUInteger imageCacheDuration;

/**
 *  if your server takes longer than 30 seconds to provide real data,
 *  you should hire a better server developer.
 *  on iOS (or any mobile device), 30 seconds is already considered high.
 */
@property (nonatomic) NSUInteger requestTimeout;

/*!
 *  @abstract Request URL Property
 *  @property url
 *
 *  @discussion
 *	Returns the operation's URL
 *  This property is readonly cannot be updated.
 *  To create an operation with a specific URL, use the operationWithURLString:params:httpMethod:
 */
@property (nonatomic, copy, readonly) NSString *url;

/*!
 *  @abstract The internal request object
 *  @property readonlyRequest
 *
 *  @discussion
 *	Returns the operation's actual request object
 *  This property is readonly cannot be modified.
 *  To create an operation with a new request, use the operationWithURLString:params:httpMethod:
 */
@property (nonatomic, strong, readonly) NSURLRequest *readonlyRequest;

/*!
 *  @abstract The internal HTTP Response Object
 *  @property readonlyResponse
 *
 *  @discussion
 *	Returns the operation's actual response object
 *  This property is readonly cannot be updated.
 */
@property (nonatomic, strong, readonly) NSHTTPURLResponse *readonlyResponse;

/*!
 *  @abstract The internal HTTP Post data values
 *  @property readonlyPostDictionary
 *
 *  @discussion
 *	Returns the operation's post data dictionary
 *  This property is readonly cannot be updated.
 *  Rather, updating this post dictionary doesn't have any effect on the MKNetworkOperation.
 *  Use the addHeaders method to add post data parameters to the operation.
 *
 *  @seealso
 *   addHeaders:
 */
@property (nonatomic, copy, readonly) NSDictionary *readonlyPostDictionary;

/*!
 *  @abstract The internal request object's method type
 *  @property HTTPMethod
 *
 *  @discussion
 *	Returns the operation's method type
 *  This property is readonly cannot be modified.
 *  To create an operation with a new method type, use the operationWithURLString:params:httpMethod:
 */
@property (nonatomic, copy, readonly) NSString *HTTPMethod;

/*!
 *  @abstract The internal response object's status code
 *  @property HTTPStatusCode
 *
 *  @discussion
 *	Returns the operation's response's status code.
 *  Returns 0 when the operation has not yet started and the response is not available.
 *  This property is readonly cannot be modified.
 */
@property (nonatomic, assign, readonly) NSInteger HTTPStatusCode;

/*!
 *  @abstract Post Data Encoding Type Property
 *  @property postDataEncoding
 *
 *  @discussion
 *  Specifies which type of encoding should be used to encode post data.
 *  LSQNKPostDataEncodingTypeURL is the default which defaults to application/x-www-form-urlencoded
 *  LSQNKPostDataEncodingTypeJSON uses JSON encoding.
 *  JSON Encoding is supported only in iOS 5 or Mac OS X 10.7 and above.
 *  On older operating systems, JSON Encoding reverts back to URL Encoding
 *  You can use the postDataEncodingHandler to provide a custom postDataEncoding
 *  For example, JSON encoding using a third party library.
 *
 *  @seealso
 *  setCustomPostDataEncodingHandler:forType:
 *
 */
@property (nonatomic, assign) LSQNKPostDataEncodingType postDataEncoding;

/*!
 *  @abstract Set a customized Post Data Encoding Handler for a given HTTP Content Type
 *
 *  @discussion
 *  If you need customized post data encoding support, provide a block method here.
 *  This block method will be invoked only when your HTTP Method is POST or PUT
 *  For default URL encoding or JSON encoding, use the property postDataEncoding
 *  If you change the postData format, it's your responsiblity to provide a correct Content-Type.
 *
 *  @seealso
 *  postDataEncoding
 */
-(void) setCustomPostDataEncodingHandler:(LSQNKEncodingBlock) postDataEncodingHandler forType:(NSString*) contentType;

/*!
 *  @abstract String Encoding Property
 *  @property stringEncoding
 *
 *  @discussion
 *  Specifies which type of encoding should be used to encode URL strings
 */
@property (nonatomic, assign) NSStringEncoding stringEncoding;

/*!
 *  @abstract Freezable request
 *  @property freezable
 *
 *  @discussion
 *	Freezable operations are serialized when the network goes down and restored when the connectivity is up again.
 *  Only POST, PUT and DELETE operations are freezable.
 *  In short, any operation that changes the state of the server are freezable, creating a tweet, checking into a new location etc., Operations like fetching a list of tweets (think readonly GET operations) are not freezable.
 *  MKNetworkKit doesn't freeze (readonly) GET operations even if they are marked as freezable
 */
@property (nonatomic, assign) BOOL freezable;

/*!
 *  @abstract Error object
 *  @property error
 *
 *  @discussion
 *	If the network operation results in an error, this will hold the response error, otherwise it will be nil
 */
@property (nonatomic, readonly, strong) NSError *error;

/*!
 *  @abstract Boolean variable that states whether the operation's response should be cached despite coming from a secured source
 *  @property shouldCacheEvenIfProtocolIsHTTPS
 *
 *  @discussion
 *	If you set this property to YES, the operation's data will be cached even if the source is secure (HTTPS)
 *  The default value is NO. MKNetworkKit will not cache responses from secure servers
 */
@property (nonatomic, assign) BOOL shouldCacheResponseEvenIfProtocolIsHTTPS;

/*!
 *  @abstract Boolean variable that states whether the operation's response should be cached
 *  @property shouldNotCacheResponse
 *
 *  @discussion
 *	If you set this property to YES, the operation's data will not be cached even if the engine's useCache is enabled
 *  The default value is NO. MKNetworkKit will cache responses based on the engine setting.
 *  This property should be used sparingly if your backend isn't written adhering to HTTP 1.1 caching standards
 */
@property (nonatomic, assign) BOOL shouldNotCacheResponse;

/*!
 *  @abstract Boolean variable that states whether the operation should continue if the certificate is invalid.
 *  @property shouldContinueWithInvalidCertificate
 *
 *  @discussion
 *	If you set this property to YES, the operation will continue as if the certificate was valid (if you use Server Trust Auth)
 *  The default value is NO. MKNetworkKit will not run an operation with a server that is not trusted.
 */
@property (nonatomic, assign) BOOL shouldContinueWithInvalidCertificate;

/*!
 *  @abstract Boolean variable that states whether the request should automatically include an Accept-Language header.
 *  @property shouldSendAcceptLanguageHeader
 *
 *  @discussion
 *	If set to YES, then MKNetworkKit will generate an Accept-Language header using [NSLocale preferredLanguages] + "en-us".
 *  This is set by MKNetworkEngine when it creates the MKNetworkOperation instance, so it gets its default from there.
 */
@property (nonatomic, assign) BOOL shouldSendAcceptLanguageHeader;

/*!
 *  @abstract Cache headers of the response
 *  @property cacheHeaders
 *
 *  @discussion
 *	If the network operation is a GET, this dictionary will be populated with relevant cache related headers
 *	MKNetworkKit assumes a 7 day cache for images and 1 minute cache for all requests with no-cache set
 *	This property is internal to MKNetworkKit. Modifying this is not recommended and will result in unexpected behaviour
 */
@property (strong, nonatomic) NSMutableDictionary *cacheHeaders;

/*!
 *  @abstract Authentication methods
 *
 *  @discussion
 *	If your request needs to be authenticated, set your username and password using this method.
 */
-(void) setUsername:(NSString*) name password:(NSString*) password;

/*!
 *  @abstract Authentication methods
 *
 *  @discussion
 *	If your request needs to be authenticated using HTTP Basic, use this method to set your username and password.
 *  Calling this method with basicAuth:NO is same as calling setUserName:password:
 *  @seealso
 *  setUserName:password:
 */
-(void) setUsername:(NSString*) username password:(NSString*) password basicAuth:(BOOL) bYesOrNo;

/*!
 *  @abstract Authentication methods (Client Certificate)
 *  @property clientCertificate
 *
 *  @discussion
 *	If your request needs to be authenticated using a client certificate, set the certificate path here
 */
@property (copy, nonatomic) NSString *clientCertificate;

/*!
 *  @abstract Authentication methods (Password for the Client Certificate)
 *  @property clientCertificatePassword
 *
 *  @discussion
 *	If your client certificate is encrypted with a password, specify it here
 */
@property (copy, nonatomic) NSString *clientCertificatePassword;

/*!
 *  @abstract Custom authentication handler
 *  @property authHandler
 *
 *  @discussion
 *	If your request needs to be authenticated using a custom method (like a Web page/HTML Form), add a block method here
 *  and process the NSURLAuthenticationChallenge
 */
@property (nonatomic, copy) LSQNKAuthBlock authHandler;

/*!
 *  @abstract Handler that you implement to monitor reachability changes
 *  @property operationStateChangedHandler
 *
 *  @discussion
 *	The framework calls this handler whenever the operation state changes
 */
@property (copy, nonatomic) void (^operationStateChangedHandler)(TuSDKNetworkOperationState newState);

/*!
 *  @abstract controls persistence of authentication credentials
 *  @property credentialPersistence
 *
 *  @discussion
 *  The default value is set to NSURLCredentialPersistenceForSession, change it to NSURLCredentialPersistenceNone to avoid caching issues (isse #35)
 */
@property (nonatomic, assign) NSURLCredentialPersistence credentialPersistence;
#if TARGET_OS_IPHONE

/*!
 *  @abstract notification that has to be shown when an error occurs and the app is in background
 *  @property localNotification
 *
 *  @discussion
 *  The default value nil. No notification is shown when an error occurs.
 *  To show a notification when the app is in background and the network operation running in background fails,
 *  set this parameter to a UILocalNotification object
 */
@property (nonatomic, strong) UILocalNotification *localNotification;

/*!
 *  @abstract Shows a local notification when an error occurs
 *  @property shouldShowLocalNotificationOnError
 *
 *  @discussion
 *  The default value NO. No notification is shown when an error occurs.
 *  When set to YES, MKNetworkKit shows the NSError localizedDescription text as a notification when the app is in background and the network operation ended in error.
 *  To customize the local notification text, use the property localNotification
 
 *  @seealso
 *  localNotification
 */
@property (nonatomic, assign) BOOL shouldShowLocalNotificationOnError;
#endif

/*!
 *  @abstract Add additional POST/GET parameters to your request
 *
 *  @discussion
 *	If you ever need to set additional params after creating your operation, you this method.
 *  You normally set default parameters to the params parameter when you create a operation.
 *  On specific cases where you need to add a new parameter for a call, you can use this
 */
-(void) addParams:(NSDictionary*) paramsDictionary;

/*!
 *  @abstract Add additional header
 *
 *  @discussion Add a single additional header.  See addHeaders for a full discussion.
 */
-(void) addHeader:(NSString*)key withValue:(NSString*)value;

/*!
 *  @abstract Add additional header parameters
 *
 *  @discussion
 *	If you ever need to set additional headers after creating your operation, you this method.
 *  You normally set default headers to the engine and they get added to every request you create.
 *  On specific cases where you need to set a new header parameter for just a single API call, you can use this
 */
-(void) addHeaders:(NSDictionary*) headersDictionary;

/*!
 *  @abstract Set a header, overwriting any value already set.
 *
 *  @discussion addHeader will append the value to any header already set.  If you want to overwrite
 *  that value, then use setHeader instead.
 */
-(void) setHeader:(NSString*)key withValue:(NSString*)value;

/*!
 *  @abstract Sets the authorization header after prefixing it with a given auth type
 *
 *  @discussion
 *	If you need to set the HTTP Authorization header, you can use this convinience method.
 *  This method internally calls addHeaders:
 *  The authType parameter is a string that you can prefix to your auth token to tell your server what kind of authentication scheme you want to use. HTTP Basic Authentication uses the string "Basic" for authType
 *  To use HTTP Basic Authentication, consider using the method setUsername:password:basicAuth: instead.
 *
 *  Example
 *  [op setAuthorizationHeaderValue:@"abracadabra" forAuthType:@"Token"] will set the header value to
 *  "Authorization: Token abracadabra"
 *
 *  @seealso
 *  setUsername:password:basicAuth:
 *  addHeaders:
 */
-(void) setAuthorizationHeaderValue:(NSString*) token forAuthType:(NSString*) authType;

/*!
 *  @abstract Attaches a file to the request
 *
 *  @discussion
 *	This method lets you attach a file to the request
 *  The method has a side effect. It changes the HTTPMethod to "POST" regardless of what it was before.
 *  It also changes the post format to multipart/form-data
 *  The mime-type is assumed to be application/octet-stream
 */
-(void) addFile:(NSString*) filePath forKey:(NSString*) key;

/*!
 *  @abstract Attaches a file to the request and allows you to specify a mime-type
 *
 *  @discussion
 *	This method lets you attach a file to the request
 *  The method has a side effect. It changes the HTTPMethod to "POST" regardless of what it was before.
 *  It also changes the post format to multipart/form-data
 */
-(void) addFile:(NSString*) filePath forKey:(NSString*) key mimeType:(NSString*) mimeType;

/*!
 *  @abstract Attaches a resource to the request from a NSData pointer
 *
 *  @discussion
 *	This method lets you attach a NSData object to the request. The behaviour is exactly similar to addFile:forKey:
 *  The method has a side effect. It changes the HTTPMethod to "POST" regardless of what it was before.
 *  It also changes the post format to multipart/form-data
 *  The mime-type is assumed to be application/octet-stream
 */
-(void) addData:(NSData*) data forKey:(NSString*) key;

/*!
 *  @abstract Attaches a resource to the request from a NSData pointer and allows you to specify a mime-type
 *
 *  @discussion
 *	This method lets you attach a NSData object to the request. The behaviour is exactly similar to addFile:forKey:mimeType:
 *  The method has a side effect. It changes the HTTPMethod to "POST" regardless of what it was before.
 *  It also changes the post format to multipart/form-data
 */
-(void) addData:(NSData*) data forKey:(NSString*) key mimeType:(NSString*) mimeType fileName:(NSString*) fileName;

/*!
 *  @abstract Block Handler for completion and error
 *
 *  @discussion
 *	This method sets your completion and error blocks. If your operation's response data was previously called,
 *  the completion block will be called almost immediately with the cached response. You can check if the completion
 *  handler was invoked with a cached data or with real data by calling the isCachedResponse method.
 *  This method is deprecated in favour of addCompletionHandler:errorHandler: that returns the completedOperation in the error block as well.
 *  While I will still continue to support this method, I'll remove it completely in a future release.
 *
 *  @seealso
 *  isCachedResponse
 *  addCompletionHandler:errorHandler:
 */
-(void) onCompletion:(LSQNKResponseBlock) response onError:(LSQNKErrorBlock) error DEPRECATED_ATTRIBUTE;

/*!
 *  @abstract adds a block Handler for completion and error
 *
 *  @discussion
 *	This method sets your completion and error blocks. If your operation's response data was previously called,
 *  the completion block will be called almost immediately with the cached response. You can check if the completion
 *  handler was invoked with a cached data or with real data by calling the isCachedResponse method.
 *
 *  @seealso
 *  onCompletion:onError:
 */
-(void) addCompletionHandler:(LSQNKResponseBlock) response errorHandler:(TuNKResponseErrorBlock) error;

/*!
 *  @abstract Block Handler for tracking 304 not modified state
 *
 *  @discussion
 *	This method will be called if the server sends a 304 HTTP status for your request.
 *
 */
-(void) onNotModified:(LSQNKVoidBlock) notModifiedBlock;

/*!
 *  @abstract Block Handler for tracking upload progress
 *
 *  @discussion
 *	This method can be used to update your progress bars when an upload is in progress.
 *  The value range of the progress is 0 to 1.
 *
 */
-(void) onUploadProgressChanged:(LSQNKProgressBlock) uploadProgressBlock;

/*!
 *  @abstract Block Handler for tracking download progress
 *
 *  @discussion
 *	This method can be used to update your progress bars when a download is in progress.
 *  The value range of the progress is 0 to 1.
 *
 */
-(void) onDownloadProgressChanged:(LSQNKProgressBlock) downloadProgressBlock;

/*!
 *  @abstract Uploads a resource from a stream
 *
 *  @discussion
 *	This method can be used to upload a resource for a post body directly from a stream.
 *
 */
-(void) setUploadStream:(NSInputStream*) inputStream;

/*!
 *  @abstract Downloads a resource directly to a file or any output stream
 *
 *  @discussion
 *	This method can be used to download a resource directly to a stream (It's normally a file in most cases).
 *  Calling this method multiple times adds new streams to the same operation.
 *  A stream cannot be removed after it is added.
 *
 */
-(void) addDownloadStream:(NSOutputStream*) outputStream;

/*!
 *  @abstract Helper method to check if the response is from cache
 *
 *  @discussion
 *	This method should be used to check if your response is cached.
 *  When you enable caching on MKNetworkEngine, your completionHandler will be called with cached data first and then
 *  with real data, later after fetching. In your handler, you can call this method to check if it is from cache or not
 *
 */
-(BOOL) isCachedResponse;

/*!
 *  @abstract Helper method to retrieve the contents
 *
 *  @discussion
 *	This method is used for accessing the downloaded data. If the operation is still in progress, the method returns nil instead of partial data. To access partial data, use a downloadStream.
 *
 *  @seealso
 *  addDownloadStream:
 */
-(NSData*) responseData;

/*!
 *  @abstract Helper method to retrieve the contents as a NSString
 *
 *  @discussion
 *	This method is used for accessing the downloaded data. If the operation is still in progress, the method returns nil instead of partial data. To access partial data, use a downloadStream. The method also converts the responseData to a NSString using the stringEncoding specified in the operation
 *
 *  @seealso
 *  addDownloadStream:
 *  stringEncoding
 */
-(NSString*)responseString;

/*!
 *  @abstract Helper method to print the request as a cURL command
 *
 *  @discussion
 *	This method is used for displaying the request you created as a cURL command
 *
 */
-(NSString*) curlCommandLineString;

/*!
 *  @abstract Helper method to retrieve the contents as a NSString encoded using a specific string encoding
 *
 *  @discussion
 *	This method is used for accessing the downloaded data. If the operation is still in progress, the method returns nil instead of partial data. To access partial data, use a downloadStream. The method also converts the responseData to a NSString using the stringEncoding specified in the parameter
 *
 *  @seealso
 *  addDownloadStream:
 *  stringEncoding
 */
-(NSString*) responseStringWithEncoding:(NSStringEncoding) encoding;

/*!
 *  @abstract Helper method to retrieve the contents as a UIImage
 *
 *  @discussion
 *	This method is used for accessing the downloaded data as a UIImage. If the operation is still in progress, the method returns nil instead of a partial image. To access partial data, use a downloadStream. If the response is not a valid image, this method returns nil. This method doesn't obey the response mime type property. If the server response with a proper image data but set the mime type incorrectly, this method will still be able access the response as an image.
 *
 *  @seealso
 *  addDownloadStream:
 */
#if TARGET_OS_IPHONE
-(UIImage*) responseImage;
-(void) decompressedResponseImageOfSize:(CGSize) size completionHandler:(void (^)(UIImage *decompressedImage)) imageDecompressionHandler;
#elif TARGET_OS_MAC
-(NSImage*) responseImage;
-(NSXMLDocument*) responseXML;
#endif

/*!
 *  @abstract Helper method to retrieve the contents as a NSDictionary or NSArray depending on the JSON contents
 *
 *  @discussion
 *	This method is used for accessing the downloaded data as a NSDictionary or an NSArray. If the operation is still in progress, the method returns nil. If the response is not a valid JSON, this method returns nil.
 *
 *  @seealso
 *  responseJSONWithCompletionHandler:
 
 *  @availability
 *  iOS 5 and above or Mac OS 10.7 and above
 */
-(id) responseJSON;

/*!
 *  @abstract Helper method to retrieve the contents as a NSDictionary or NSArray depending on the JSON contents in the background
 *
 *  @discussion
 *	This method is used for accessing the downloaded data as a NSDictionary or an NSArray. If the operation is still in progress, the method returns nil. If the response is not a valid JSON, this method returns nil. The difference between this and responseJSON is that, this method decodes JSON in the background.
 *
 *  @see also
 *  responseJSON
 *  responseJSONWithOptions:completionHandler:
 *
 *  @availability
 *  iOS 5 and above or Mac OS 10.7 and above
 */
-(void) responseJSONWithCompletionHandler:(void (^)(id jsonObject)) jsonDecompressionHandler;

/*!
 *  @abstract Helper method to retrieve the contents as a NSDictionary or NSArray depending on the JSON contents in the background
 *
 *  @discussion
 *	This method is used for accessing the downloaded data as a NSDictionary or an NSArray. If the operation is still in progress, the method returns nil. If the response is not a valid JSON, this method returns nil. The difference between this and responseJSON is that, this method decodes JSON in the background and allows passing JSON reading options like parsing JSON fragments.
 *
 *  @see also
 *  responseJSON
 *  responseJSONWithCompletionHandler:
 *
 *  @availability
 *  iOS 5 and above or Mac OS 10.7 and above
 */
-(void) responseJSONWithOptions:(NSJSONReadingOptions) options completionHandler:(void (^)(id jsonObject)) jsonDecompressionHandler;

/*!
 *  @abstract Overridable custom method where you can add your custom business logic error handling
 *
 *  @discussion
 *	This optional method can be overridden to do custom error handling. Be sure to call [super operationSucceeded] at the last.
 *  For example, a valid HTTP response (200) like "Item not found in database" might have a custom business error code
 *  You can override this method and called [super failWithError:customError]; to notify that HTTP call was successful but the method
 *  ended as a failed call
 *
 */
-(void) operationSucceeded;

/*!
 *  @abstract Overridable custom method where you can add your custom business logic error handling
 *
 *  @discussion
 *	This optional method can be overridden to do custom error handling. Be sure to call [super operationSucceeded] at the last.
 *  For example, a invalid HTTP response (401) like "Unauthorized" might be a valid case in your app.
 *  You can override this method and called [super operationSucceeded]; to notify that HTTP call failed but the method
 *  ended as a success call. For example, Facebook login failed, but to your business implementation, it's not a problem as you
 *  are going to try alternative login mechanisms.
 *
 */
-(void) operationFailedWithError:(NSError*) error;

/*!
 *  @abstract Copy this MKNetworkOperation, with the intention of retrying the call.
 *
 *  @discussion This means that the request parameters and callbacks are all preserved, but anything related
 *  to an ongoing request is discarded, so that a new request with the same configuration can be made.
 */
-(instancetype) copyForRetry;

// internal methods called by MKNetworkEngine only.
// Don't touch
-(BOOL) isCacheable;
-(void) setCachedData:(NSData*) cachedData;
-(void) setCacheHandler:(LSQNKResponseBlock) cacheHandler;
-(void) updateHandlersFromOperation:(TuNetworkOperation*) operation;
-(void) updateOperationBasedOnPreviousHeaders:(NSMutableDictionary*) headers;
-(NSString*) uniqueIdentifier;

- (instancetype)initWithURLString:(NSString *)aURLString
                           params:(NSDictionary *)params
                       httpMethod:(NSString *)method;
@end
