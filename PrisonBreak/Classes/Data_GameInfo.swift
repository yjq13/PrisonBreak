//
//  Data_GameInfo.swift
//  PrisonBreak
//
//  Created by yjq131250077 on 15/9/11.
//
//

import Foundation
class GameInfo_get: NSObject {
    func getGameInfoData()->GamePo{
        
        var Gpo : GamePo =  GamePo(step:13,state:0,time:0)
        return Gpo
    }
}