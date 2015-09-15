//
//  Data_GameInfo.swift
//  PrisonBreak
//
//  Created by yjq131250077 on 15/9/11.
//
//

import Foundation
class GameInfo_deal: NSObject {
    func getGameInfoData(step:Int)->GamePo{
        var dict = NSDictionary(contentsOfFile: NSBundle.mainBundle().pathForResource("GameInfo", ofType: "plist")!)
        
        var valueArr:AnyObject? = dict?.objectForKey("Game_\(step)")!
        var _step: Int = valueArr?.objectForKey("step") as! Int
        var _state: Int = valueArr?.objectForKey("state") as! Int
        var _time: Int = valueArr?.objectForKey("time") as! Int

        
        var Gpo : GamePo =  GamePo(step:_step,state:_state,time:_time)
        return Gpo
    }
}