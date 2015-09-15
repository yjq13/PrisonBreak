//
//  OC-callSystemInfo.m
//  PrisonBreak
//
//  Created by yjq131250077 on 15/9/11.
//
//

#import <OC_callSystemInfo.h>
#import "PrisonBreak_mobile-Swift.h"
#import "SystemVo.h"
SystemVo getSystemInfo(){
    SystemVo vo;
    SystemPo *po;
    SystemInfo_get *Sget = [[SystemInfo_get alloc]init];
    po = [Sget getSystemInfoData];
    vo.setData(po.voice,po.sound);
    return vo;
}