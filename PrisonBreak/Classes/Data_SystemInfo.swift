//
//  Data_SystemInfo.swift
//  PrisonBreak
//
//  Created by yjq131250077 on 15/9/12.
//
//

import Foundation

class SystemInfo_deal: NSObject {
    func getSystemInfoData()->SystemPo{
            let paths = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true) as NSArray
            let documentsDirectory = paths.objectAtIndex(0) as! NSString
            let path = documentsDirectory.stringByAppendingPathComponent("SystemInfo.plist")
            var dict = NSDictionary(contentsOfFile: path)

            var _voice: Bool = dict?.objectForKey("voice") as! Bool
            var _sound: Bool = dict?.objectForKey("sound") as! Bool
            var Gpo : SystemPo =  SystemPo(voice:_voice,sound:_sound)
            return Gpo
            }
    
    func writeSystemInfoData(po:SystemPo){
        let paths = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true) as NSArray
        let documentsDirectory = paths.objectAtIndex(0) as! NSString
        let path = documentsDirectory.stringByAppendingPathComponent("SystemInfo.plist")
        var dict = NSMutableDictionary(contentsOfFile: path)

        dict?.setObject(po.voice, forKey: "voice")
        dict?.setObject(po.sound, forKey: "sound")
        
        dict?.writeToFile(path, atomically: false)

    }
}