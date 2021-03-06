//
//  LXRecordShowManager.m
//  LXRecorderDemo
//
//  Created by MightLee on 2020/6/19.
//

#import "LXRecordShowManager.h"
#import "LXRecordToastContentView.h"
#import "LXRecordView.h"

@interface LXRecordShowManager()
@property (nonatomic, strong) LXRecordView *voiceRecordView;
@property (nonatomic, strong) LXRecordTipView *tipView;
@end

@implementation LXRecordShowManager

- (void)updatePower:(float)power
{
    [self.voiceRecordView updatePower:power];
}

- (void)showRecordCounting:(float)remainTime
{
    [self.voiceRecordView updateWithRemainTime:remainTime];
}

- (void)showToast:(NSString *)message
{
    if (self.tipView.superview == nil) {
        [[UIApplication sharedApplication].keyWindow addSubview:self.tipView];
        [self.tipView showWithMessage:message];
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [self.tipView removeFromSuperview];
        });
    }
}

- (void)updateUIWithRecordState:(LXRecordState)state
{
    if (state == LXRecordState_Normal) {
        if (self.voiceRecordView.superview) {
            [self.voiceRecordView removeFromSuperview];
        }
        return;
    }
    
    if (self.voiceRecordView.superview == nil) {
        [[UIApplication sharedApplication].keyWindow addSubview:self.voiceRecordView];
    }
    
    [self.voiceRecordView updateUIWithRecordState:state];
}

- (LXRecordView *)voiceRecordView
{
    if (_voiceRecordView == nil) {
        _voiceRecordView = [LXRecordView new];
        _voiceRecordView.frame = CGRectMake(0, 0, 150, 150);
        _voiceRecordView.center = CGPointMake([UIScreen mainScreen].bounds.size.width/2, [UIScreen mainScreen].bounds.size.height/2);
    }
    return _voiceRecordView;
}

- (LXRecordTipView *)tipView
{
    if (_tipView == nil) {
        _tipView = [LXRecordTipView new];
        _tipView.frame = CGRectMake(0, 0, 150, 150);
        _tipView.center = CGPointMake([UIScreen mainScreen].bounds.size.width/2, [UIScreen mainScreen].bounds.size.height/2);
    }
    return _tipView;
}

@end
