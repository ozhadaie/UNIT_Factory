//
//  ViewController.swift
//  D07
//
//  Created by Oleksii ZHADAIEV on 10/10/19.
//  Copyright © 2019 Oleksii ZHADAIEV. All rights reserved.
//

import UIKit
import RecastAI
import ForecastIO
import CoreLocation

class ViewController: UIViewController {
    var recast : RecastAIClient!
    var darkSky : DarkSkyClient!
    
    @IBOutlet weak var place: UITextField!
    @IBOutlet weak var weather: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.recast = RecastAIClient(token : "cb0d2b1490636ece4812be58f08f7087", language: "en")
        self.darkSky = DarkSkyClient(apiKey: "cc07b70b7b868e75bbb1fa17d257852d")
        self.darkSky.units = .si
    }
    
    @IBAction func makeRequest(_ sender: UIButton) {
        if place.text != "" {
            self.recast.textRequest(place.text!, successHandler: successHandler, failureHandle: {
                (err) in
                print(err.localizedDescription)
            })
        } else {
            displayError(message: "Please enter place")
        }
    }
    
    private func successHandler(response : Response) {
        if let location = response.get(entity: "location") {
            print(location)
            self.weather.text = "Fetching info..."
            let myLoc = CLLocationCoordinate2D(latitude: location["lat"]! as! CLLocationDegrees, longitude: location["lng"]! as! CLLocationDegrees)
            if let city = location["city"] as? String {
                self.weather.text = "Weather in \(city) is "
            } else if let formatted = location["formatted"] as? String {
                self.weather.text = "Weather in \(formatted) is "
            }
            self.darkSky.getForecast(location: myLoc, completion: completion)
        } else {
            displayError(message: "Invalid place")
        }
    }
    
    private func completion(result: Result<(Forecast, RequestMetadata), Error>) {
        switch result {
        case .success(let currentForecast, let requestMetadata):
            print(currentForecast)
            print(requestMetadata)
            DispatchQueue.main.async {
                self.weather.text = self.weather.text! + String(describing: currentForecast.currently!.summary!) + "\nTemperature is \(String(describing: currentForecast.currently!.temperature!))°C"
            }
        case .failure(let error):
            print(error.localizedDescription)
        }
    }
}

extension UIViewController {
    func displayError(message: String) {
        let alert = UIAlertController(title: "Error", message: message, preferredStyle: UIAlertController.Style.alert)
        alert.addAction(UIAlertAction(title: "OK", style: UIAlertAction.Style.default, handler: nil))
        self.present(alert, animated: true)
    }
}
