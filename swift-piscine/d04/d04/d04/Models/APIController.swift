//
//  APIController.swift
//  D04
//
//  Created by Oleksii ZHADAIEV on 10/5/19.
//  Copyright © 2019 Oleksii ZHADAIEV. All rights reserved.
//

import Foundation

class APIController {
    
    weak var delegate: APITwitterDelegate?
    let token: String
    var tweets = [Tweet]()
    
    init(delegate: APITwitterDelegate?, token: String) {
        self.delegate = delegate
        self.token = token
    }
    
    static func authTwitter(with viewController: ViewController) {
        let apiKey = "B6gkH8VZHw7aSihZZgrFXJ3QW"
        let secretApiKey = "03jRweiZPGHC3OnVPuQoQueS3kG9uNGtNOJwBLzMIrKgJNxXNi"
        let url = URL(string: "https://api.twitter.com/oauth2/token")
        let bearer = ((apiKey + ":" + secretApiKey).data(using: String.Encoding.utf8))!.base64EncodedString(options: NSData.Base64EncodingOptions())
        
        var request = URLRequest(url: url!)
        request.httpMethod = "POST"
        request.setValue("Basic " + bearer, forHTTPHeaderField: "Authorization")
        request.setValue("application/x-www-form-urlencoded;charset=utf-8", forHTTPHeaderField: "Content-Type")
        request.httpBody = "grant_type=client_credentials".data(using: String.Encoding.utf8)
        
        URLSession.shared.dataTask(with: request) { (data, response, error) in
            guard let data = data, error == nil else {

                return
            }
            if let json = try? JSONSerialization.jsonObject(with: data, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary {
                viewController.token = json["access_token"] as? String
                viewController.api = APIController(delegate: viewController, token: viewController.token!)
                viewController.api?.fetchTweets(searchWord: viewController.searchText)
            }
            }.resume()
    }
    
    func fetchTweets(searchWord: String) {
        let req = searchWord.addingPercentEncoding(withAllowedCharacters: CharacterSet.urlQueryAllowed)!
        let url = URL(string: "https://api.twitter.com/1.1/search/tweets.json?q=" + req + "&count=100&result_type=recent")
        
        var request = URLRequest(url: url!)
        request.httpMethod = "GET"
        request.setValue("Bearer " + self.token, forHTTPHeaderField: "Authorization")
        
        URLSession.shared.dataTask(with: request) { (data, response, error) in
            guard let data = data, error == nil else {
                DispatchQueue.main.sync {
                    let userInfo: [String : Any] = [ NSLocalizedDescriptionKey :  NSLocalizedString("Authentication", value: "Failed to Authenticate", comment: "") ]
                    self.delegate?.tweetError(error: NSError(domain: "https://api.twitter.com/1.1/search/tweets.json", code: 401, userInfo: userInfo))
                    return
                }
                return
            }
            
            if let json = try? JSONSerialization.jsonObject(with: data, options: []) as? NSDictionary {
                let tweetsReceived = json["statuses"] as? [[String:Any]]
                
                if tweetsReceived!.count < 1 {
                    DispatchQueue.main.sync {
                        let userInfo: [String : Any] = [ NSLocalizedDescriptionKey :  NSLocalizedString("No results", value: "Nothing came up for that search. \(searchWord)", comment: "") ]
                        self.delegate?.tweetError(error: NSError(domain: "https://api.twitter.com/1.1/search/tweets.json", code: 401, userInfo: userInfo))
                        return
                    }
                }
                self.tweets.removeAll()
                for tweet in tweetsReceived! {
                    let date = dateFormatterDate(string: tweet["created_at"] as! String)
                    let user = tweet["user"] as AnyObject
                    let imageUrl = user["profile_image_url_https"] as! String
                    let name = user["name"] as! String
                    var screen_name = user["screen_name"] as! String
                    screen_name.insert("@", at: screen_name.startIndex)
                    let title = tweet["text"] as! String
                    self.tweets.append(Tweet(title: name,
                                             text: title,
                                             userImageURL: URL(string: imageUrl)!,
                                             screenName: screen_name,
                                             date: date))
                }
            }
            
            DispatchQueue.main.sync {
                self.delegate?.processReceivedTweets(tweets: self.tweets)
            }
            
            }.resume()
    }
}

private func dateFormatterDate(string: String) -> String {
    let dateFormatter = DateFormatter()
    dateFormatter.dateFormat = "E MMM dd HH:mm:ss Z yyyy"
    let date = dateFormatter.date(from: string)
    dateFormatter.dateFormat = "MMM d, h:mm a"
    let dateString = dateFormatter.string(from: date!)
    return dateString
}
