//
//  ViewController.swift
//  D04
//
//  Created by Oleksii ZHADAIEV on 10/5/19.
//  Copyright © 2019 Oleksii ZHADAIEV. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    var api: APIController?
    var token: String?
    var searchText = "Swift"
    private var tweets: [Tweet] = []
    
    @IBOutlet weak var tableView: UITableView! {
        didSet {
            tableView.dataSource = self
            tableView.rowHeight = UITableView.automaticDimension
            tableView.estimatedRowHeight = 600
            tableView.register(UINib(nibName: "TweetCell", bundle: nil), forCellReuseIdentifier: "tweetCell")
            
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setupNavBar()
        APIController.authTwitter(with: self)
    }
    
    private func setupNavBar() {
        let searchController = UISearchController(searchResultsController: nil)
        
        self.definesPresentationContext = true
        navigationController?.navigationBar.prefersLargeTitles = true
        navigationItem.searchController = searchController
        navigationItem.hidesSearchBarWhenScrolling = true
        navigationItem.searchController?.searchBar.placeholder = "Search Twitter"
        navigationItem.searchController?.searchBar.delegate = self
    }
    
    private func showAlert(title: String, message: String, action: String) {
        let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
        let actionOk = UIAlertAction(title: action, style: .default) { (UIAlertAction) in }
        alert.addAction(actionOk)
        present(alert, animated: true, completion: nil)
    }
}

extension ViewController: UISearchBarDelegate {
    
    func searchBarSearchButtonClicked(_ searchBar: UISearchBar) {
        navigationItem.searchController?.dismiss(animated: true, completion: nil)
        api?.fetchTweets(searchWord: searchBar.text!)
    }
    
}

extension ViewController: UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return tweets.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "tweetCell") as! TweetCell
        let tweet = tweets[indexPath.row]
        
        cell.name.text = tweet.title
        cell.login.text = tweet.screenName
        cell.date.text = tweet.date
        cell.tweet.text = tweet.text
        
        cell.userImage.downloaded(from: tweet.userImageURL)
        
        return cell
    }
}

extension ViewController: APITwitterDelegate {
    func processReceivedTweets(tweets: [Tweet]) {
        DispatchQueue.main.async {
            self.tweets = tweets
            self.tableView.reloadData()
        }
    }
    
    func tweetError(error: NSError) {
        showAlert(title: "Error", message: error.localizedDescription, action: "OK")
        print(error.localizedDescription)
    }
}
