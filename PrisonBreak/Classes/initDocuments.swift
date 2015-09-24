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
        
<<<<<<< HEAD
        if(!fileManager.fileExistsAtPath(path)) {
        
        let SystemInfoD = NSDictionary(contentsOfFile: NSBundle.mainBundle().pathForResource("SystemInfo", ofType: "plist")!)
        
        let GameInfoD = NSDictionary(contentsOfFile: NSBundle.mainBundle().pathForResource("GameInfo", ofType: "plist")!)
        
        let FigureInfoD = NSDictionary(contentsOfFile: NSBundle.mainBundle().pathForResource("FigureInfo", ofType: "plist")!)
=======
        if(!fileManager.fileExistsAtPath(pathS)) {
>>>>>>> origin/master
        
        let SystemInfoD = NSDictionary(contentsOfFile: NSBundle.mainBundle().pathForResource("SystemInfo", ofType: "plist")!)
            SystemInfoD?.writeToFile(pathS, atomically: false)
        }else{
            print("SystemInfoD is ok")
                    }
        
        
        if(!fileManager.fileExistsAtPath(pathF)) {
            let FigureInfoD = NSDictionary(contentsOfFile: NSBundle.mainBundle().pathForResource("FigureInfo", ofType: "plist")!)
            FigureInfoD?.writeToFile(pathF, atomically: false)
        }else{
            print("FigureInfoD is ok")
        }


        
        if(!fileManager.fileExistsAtPath(pathG)) {
            
            let GameInfoD = NSDictionary(contentsOfFile: NSBundle.mainBundle().pathForResource("GameInfo", ofType: "plist")!)
            GameInfoD?.writeToFile(pathG, atomically: false)
        }else{
<<<<<<< HEAD
            print("data has existed")
        }
        print("loadDataSuccessed")
=======
            print("GamenfoD is ok")
        }
        
>>>>>>> origin/master
    }
}