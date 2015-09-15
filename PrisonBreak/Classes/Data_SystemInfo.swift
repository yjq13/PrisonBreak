//
//  Data_SystemInfo.swift
//  PrisonBreak
//
//  Created by yjq131250077 on 15/9/12.
//
//

import Foundation

class SystemInfo_get: NSObject {
    func getSystemInfoData()->SystemPo{
        
        var Gpo : SystemPo =  SystemPo(voice:true,sound:true)
        return Gpo
    }

}