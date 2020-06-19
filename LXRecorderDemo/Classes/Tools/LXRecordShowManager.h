//
//  LXRecordShowManager.h
//  LXRecorderDemo
//
//  Created by MightLee on 2020/6/19.
//

#import <Foundation/Foundation.h>
#import "LXRecordHeaderDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface LXRecordShowManager : NSObject

- (void)updateUIWithRecordState:(LXRecordState)state;

- (void)showToast:(NSString *)message;

- (void)updatePower:(float)power;

- (void)showRecordCounting:(float)remainTime;

@end

NS_ASSUME_NONNULL_END
