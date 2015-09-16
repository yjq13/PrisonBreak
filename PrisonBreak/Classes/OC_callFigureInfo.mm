//
//  OC-callFigureInfo.m
//  PrisonBreak
//
//  Created by yjq131250077 on 15/9/11.
//
//

//#import <Foundation/Foundation.h>
#import <OC_callFigureInfo.h>
#import "PrisonBreak_mobile-Swift.h"
#import "FigureVo.h"
FigureVo getFigureInfo(){
    FigureVo vo;
    FigurePo *po;
    FigureInfo_deal *Fget = [[FigureInfo_deal alloc]init];
    po = [Fget getFigureInfoData];
    vo.setData(po.LV,po.speed,po.gold_coin,po.diamond);
    return vo;
}