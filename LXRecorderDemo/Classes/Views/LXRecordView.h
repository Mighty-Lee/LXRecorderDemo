//
//  LXRecordView.h
//  LXRecorderDemo
//
//  Created by MightLee on 2020/6/19.
//

#import <UIKit/UIKit.h>
#import "LXRecordHeaderDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface LXRecordView : UIView

- (void)updateUIWithRecordState:(LXRecordState)state;

- (void)updatePower:(float)power;

- (void)updateWithRemainTime:(float)remainTime;

@end

NS_ASSUME_NONNULL_END
