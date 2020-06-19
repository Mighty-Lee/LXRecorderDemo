//
//  LXRecordView.m
//  LXRecorderDemo
//
//  Created by MightLee on 2020/6/19.
//

#import "LXRecordView.h"
#import "LXRecordToastContentView.h"

@interface LXRecordView ()
@property (nonatomic, strong) LXRecordingView *recodingView;
@property (nonatomic, strong) LXRecordReleaseToCancelView *releaseToCancelView;
@property (nonatomic, strong) LXRecordCountingView *countingView;
@property (nonatomic, assign) LXRecordState currentState;
@end

@implementation LXRecordView

- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame])
    {
        [self setUp];
    }
    return self;
}

- (void)setUp
{
    self.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.6];

    self.recodingView = [[LXRecordingView alloc] init];
    [self addSubview:self.recodingView];
    self.recodingView.hidden = YES;

    self.releaseToCancelView = [[LXRecordReleaseToCancelView alloc] init];
    [self addSubview:self.releaseToCancelView];
    self.releaseToCancelView.hidden = YES;
    
    self.countingView = [[LXRecordCountingView alloc] init];
    [self addSubview:self.countingView];
    self.countingView.hidden = YES;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    self.layer.cornerRadius = 6;
    self.clipsToBounds = YES;
    self.recodingView.frame = self.bounds;
    self.releaseToCancelView.frame = self.bounds;
    self.countingView.frame = self.bounds;
}

- (void)updatePower:(float)power
{
    if (self.currentState != LXRecordState_Recording) {
        return;
    }
    [self.recodingView updateWithPower:power];
}

- (void)updateWithRemainTime:(float)remainTime
{
    if (self.currentState != LXRecordState_RecordCounting || self.releaseToCancelView.hidden == false) {
        return;
    }
    [self.countingView updateWithRemainTime:remainTime];
}

- (void)updateUIWithRecordState:(LXRecordState)state
{
    self.currentState = state;
    if (state == LXRecordState_Normal) {
        self.recodingView.hidden = YES;
        self.releaseToCancelView.hidden = YES;
        self.countingView.hidden = YES;
    }
    else if (state == LXRecordState_Recording)
    {
        self.recodingView.hidden = NO;
        self.releaseToCancelView.hidden = YES;
        self.countingView.hidden = YES;
    }
    else if (state == LXRecordState_ReleaseToCancel)
    {
        self.recodingView.hidden = YES;
        self.releaseToCancelView.hidden = NO;
        self.countingView.hidden = YES;
    }
    else if (state == LXRecordState_RecordCounting)
    {
        self.recodingView.hidden = YES;
        self.releaseToCancelView.hidden = YES;
        self.countingView.hidden = NO;
    }
    else if (state == LXRecordState_RecordTooShort)
    {
        self.recodingView.hidden = YES;
        self.releaseToCancelView.hidden = YES;
        self.countingView.hidden = YES;
    }
}
@end
