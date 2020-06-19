//
//  LXRecorderTool.h
//  LXRecorderDemo
//
//  Created by MightLee on 2020/6/19.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@class LXRecorderTool;
@protocol LXSecretTrainRecorderDelegate <NSObject>

@optional
- (void)recorder:(LXRecorderTool *)recorder didstartRecoring:(int)no;
- (void)recordToolDidFinishPlay:(LXRecorderTool *)recorder;

@end

@interface LXRecorderTool : NSObject

//录音工具的单例
+ (instancetype)sharedRecorder;

//开始录音
- (void)startRecording;

//停止录音
- (void)stopRecording;

//播放录音文件
- (void)playRecordingFile;

//停止播放录音文件
- (void)stopPlaying;

//销毁录音文件
- (void)destructionRecordingFile;

//播放器对象
@property (nonatomic, strong) AVAudioPlayer *player;

//录音对象
@property (nonatomic, strong) AVAudioRecorder *recorder;

//更新图片的代理
@property (nonatomic, assign) id<LXSecretTrainRecorderDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
