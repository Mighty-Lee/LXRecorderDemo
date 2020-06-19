//
//  LXRecordToastContentView.h
//  LXRecorderDemo
//
//  Created by MightLee on 2020/6/19.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LXRecordToastContentView : UIView

@end

//*****************************************************//
@interface LXRecordingView : LXRecordToastContentView

- (void)updateWithPower:(float)power;

@end

//*****************************************************//
@interface LXRecordReleaseToCancelView : LXRecordToastContentView


@end

//*****************************************************//
@interface LXRecordCountingView : LXRecordToastContentView

- (void)updateWithRemainTime:(float)remainTime;

@end

//*****************************************************//
@interface LXRecordTipView : LXRecordToastContentView

- (void)showWithMessage:(NSString *)msg;

@end

NS_ASSUME_NONNULL_END
