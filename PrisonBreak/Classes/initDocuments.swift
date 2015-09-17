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
        let path = documentsDirectory.stringByAppendingPathComponent("SystemInfo.plist")
        
        let fileManager = NSFileManager.defaultManager()
        
        if(!fileManager.fileExistsAtPath(path)) {
        
        var SystemInfoD = NSDictionary(contentsOfFile: NSBundle.mainBundle().pathForResource("SystemInfo", ofType: "plist")!)
        
        var GameInfoD = NSDictionary(contentsOfFile: NSBundle.mainBundle().pathForResource("GameInfo", ofType: "plist")!)
        
        var FigureInfoD = NSDictionary(contentsOfFile: NSBundle.mainBundle().pathForResource("FigureInfo", ofType: "plist")!)
        
        
        let path1 = documentsDirectory.stringByAppendingPathComponent("SystemInfo.plist")
        let path2 = documentsDirectory.stringByAppendingPathComponent("GameInfo.plist")
        let path3 = documentsDirectory.stringByAppendingPathComponent("Figure.plist")
        
        
        SystemInfoD?.writeToFile(path1, atomically: false)
        GameInfoD?.writeToFile(path2, atomically: false)
        FigureInfoD?.writeToFile(path3, atomically: false)
        }else{
            println("data has existed")
        }
        println("loadDataSuccessed")
    }
}