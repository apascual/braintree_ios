#if __has_include("BraintreeCore.h")
#import "BraintreeCore.h"
#else
#import <BraintreeCore/BraintreeCore.h>
#endif
#import "BTAmericanExpressRewardsBalance.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString * const BTAmericanExpressErrorDomain;
typedef NS_ENUM(NSInteger, BTAmericanExpressErrorType) {
    BTAmericanExpressErrorTypeUnknown = 0,
};

@interface BTAmericanExpressClient : NSObject

/**
 @brief Creates an American Express client.

 @param apiClient An API client
*/
- (instancetype)initWithAPIClient:(BTAPIClient *)apiClient NS_DESIGNATED_INITIALIZER;


- (instancetype)init __attribute__((unavailable("Please use initWithAPIClient:")));

/**
 @brief Gets the rewards balance associated with a Braintree nonce. Only for American Express cards.
 
 @param nonce A nonce representing a card that will be used to look up the rewards balance
 @param currencyIsoCode The currencyIsoCode to use. Example: 'USD'
 @param completionBlock A completion block that is invoked when the request has completed. If the request succeeds,
 `rewardsBalance` will contain information about the rewards balance and `error` will be `nil` (see exceptions in note);
 if it fails, `rewardsBalance` will be `nil` and `error` will describe the failure.
 @note If the nonce is associated with an ineligible card or a card with insufficient points, the rewardsBalance will contain this information as `errorMessage` and `errorCode`.
 */
- (void)getRewardsBalanceForNonce:(NSString *)nonce currencyIsoCode:(NSString *)currencyIsoCode completion:(void (^)(BTAmericanExpressRewardsBalance * _Nullable rewardsBalance, NSError * _Nullable error))completionBlock NS_AVAILABLE_IOS(8_0);

@end

NS_ASSUME_NONNULL_END
