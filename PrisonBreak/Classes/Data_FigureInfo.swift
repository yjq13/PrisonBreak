//
//  Data_FigureInfo.swift
//  PrisonBreak
//
//  Created by yjq131250077 on 15/9/12.
//
//

import Foundation

class FigureInfo_deal: NSObject {
    func getFigureInfoData()->FigurePo{
        var dict1 = NSDictionary(contentsOfFile: NSBundle.mainBundle().pathForResource("FigureInfo", ofType: "plist")!)
        
        let paths = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true) as NSArray
        let documentsDirectory = paths.objectAtIndex(0) as! NSString
        let path = documentsDirectory.stringByAppendingPathComponent("FigureInfo.plist")
        var dict = NSDictionary(contentsOfFile: path)
        
        var _LV:Int = dict?.objectForKey("LV") as! Int
        var _speed:Int = dict?.objectForKey("speed") as! Int
        
        var Gpo : FigurePo =  FigurePo(LV:_LV,speed:_speed)
        return Gpo
    }
}