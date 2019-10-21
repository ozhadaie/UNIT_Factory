//
//  APITwitterDelegateProtocol.swift
//  D04
//
//  Created by Oleksii ZHADAIEV on 10/5/19.
//  Copyright © 2019 Oleksii ZHADAIEV. All rights reserved.
//

import Foundation

protocol APITwitterDelegate: class {
    func processReceivedTweets(tweets: [Tweet])
    func tweetError(error: NSError)
}
