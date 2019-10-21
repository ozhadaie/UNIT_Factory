//
//  FirstViewController.swift
//  D05
//
//  Created by Oleksii ZHADAIEV on 10/7/19.
//  Copyright © 2019 Oleksii ZHADAIEV. All rights reserved.
//

import UIKit
import CoreLocation
class FirstViewController: UIViewController {

    @IBOutlet weak var tableView: UITableView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }


}

extension FirstViewController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return locations.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let loc = locations[indexPath.row]
        let cell = tableView.dequeueReusableCell(withIdentifier: "locationCell")
        cell?.textLabel!.text = loc.title
        return cell!
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        let mapViewController = self.tabBarController?.viewControllers![0] as! SecondViewController
        let loc = locations[indexPath.row]
        self.tabBarController?.selectedViewController = mapViewController
        mapViewController.goToCoords(coords: loc.coords)
    }
    
}

struct Location {
    let title: String
    let coords: CLLocationCoordinate2D
    let description: String
    let color: UIColor
}


var locations: [Location] = [
    Location(title: "42", coords: CLLocationCoordinate2D(latitude:  48.896618, longitude: 2.318373),
             description: "Ecole 42", color: .black),
    Location(title: "UNIT Factory", coords: CLLocationCoordinate2D(latitude: 50.468828, longitude: 30.462118), description: "MOYA SHARAGA", color: .yellow),
    Location(title: "Motherland", coords: CLLocationCoordinate2D(latitude:  50.426477 , longitude: 30.563150), description: "Statue", color: .red),
]
