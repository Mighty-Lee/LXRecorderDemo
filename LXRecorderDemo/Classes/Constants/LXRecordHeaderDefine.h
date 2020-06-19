//
//  LXRecordHeaderDefine.h
//  LXRecorderDemo
//
//  Created by MightLee on 2020/6/19.
//

#ifndef LXRecordHeaderDefine_h
#define LXRecordHeaderDefine_h

typedef NS_ENUM(NSInteger, LXRecordState)
{
    LXRecordState_Normal,          //初始状态
    LXRecordState_Recording,       //正在录音
    LXRecordState_ReleaseToCancel, //上滑取消（也在录音状态，UI显示有区别）
    LXRecordState_RecordCounting,  //最后10s倒计时（也在录音状态，UI显示有区别）
    LXRecordState_RecordTooShort,  //录音时间太短（录音结束了）
};

#endif /* LXRecordHeaderDefine_h */
