//
//  Tweet.swift
//  D04
//
//  Created by Oleksii ZHADAIEV on 10/5/19.
//  Copyright © 2019 Oleksii ZHADAIEV. All rights reserved.
//

import Foundation
import UIKit

struct Tweet: CustomStringConvertible {
    let title: String
    let text: String
    let userImageURL: URL
    let screenName: String
    let date: String
    var description: String {
        return "\(title) \(text)"
    }
}
