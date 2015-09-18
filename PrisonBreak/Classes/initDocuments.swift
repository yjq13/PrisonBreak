//
//  initDocuments.swift
//  PrisonBreak
//
//  Created by yjq131250077 on 15/9/16.
//
//

import Foundation
class initDocument : NSObject {
    func initDoc(){
        let paths = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true) as NSArray
        let documentsDirectory = paths.objectAtIndex(0) as! NSString
        let pathS = documentsDirectory.stringByAppendingPathComponent("SystemInfo.plist")
        let pathG = documentsDirectory.stringByAppendingPathComponent("GameInfo.plist")
        let pathF = documentsDirectory.stringByAppendingPathComponent("FigureInfo.plist")
        let fileManager = NSFileManager.defaultManager()
        
        if(!fileManager.fileExistsAtPath(pathS)) {
        
        var SystemInfoD = NSDictionary(contentsOfFile: NSBundle.mainBundle().pathForResource("SystemInfo", ofType: "plist")!)
            SystemInfoD?.writeToFile(pathS, atomically: false)
        }else{
            println("SystemInfoD is ok")
                    }
        
        
        if(!fileManager.fileExistsAtPath(pathF)) {
            var FigureInfoD = NSDictionary(contentsOfFile: NSBundle.mainBundle().pathForResource("FigureInfo", ofType: "plist")!)
            FigureInfoD?.writeToFile(pathF, atomically: false)
        }else{
            println("FigureInfoD is ok")
        }


        
        if(!fileManager.fileExistsAtPath(pathG)) {
            
            var GameInfoD = NSDictionary(contentsOfFile: NSBundle.mainBundle().pathForResource("GameInfo", ofType: "plist")!)
            GameInfoD?.writeToFile(pathG, atomically: false)
        }else{
            println("GamenfoD is ok")
        }
        
    }
}