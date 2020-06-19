//
//  LXRecordButton.h
//  LXRecorderDemo
//
//  Created by MightLee on 2020/6/19.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class LXRecordButton;
typedef void (^RecordTouchDown)         (LXRecordButton *recordButton);
typedef void (^RecordTouchUpOutside)    (LXRecordButton *recordButton);
typedef void (^RecordTouchUpInside)     (LXRecordButton *recordButton);
typedef void (^RecordTouchDragEnter)    (LXRecordButton *recordButton);
typedef void (^RecordTouchDragInside)   (LXRecordButton *recordButton);
typedef void (^RecordTouchDragOutside)  (LXRecordButton *recordButton);
typedef void (^RecordTouchDragExit)     (LXRecordButton *recordButton);

@interface LXRecordButton : UIButton

@property (nonatomic, copy) RecordTouchDown         recordTouchDownAction;
@property (nonatomic, copy) RecordTouchUpOutside    recordTouchUpOutsideAction;
@property (nonatomic, copy) RecordTouchUpInside     recordTouchUpInsideAction;
@property (nonatomic, copy) RecordTouchDragEnter    recordTouchDragEnterAction;
@property (nonatomic, copy) RecordTouchDragInside   recordTouchDragInsideAction;
@property (nonatomic, copy) RecordTouchDragOutside  recordTouchDragOutsideAction;
@property (nonatomic, copy) RecordTouchDragExit     recordTouchDragExitAction;

- (void)setButtonStateWithRecording;
- (void)setButtonStateWithNormal;

@end

NS_ASSUME_NONNULL_END
