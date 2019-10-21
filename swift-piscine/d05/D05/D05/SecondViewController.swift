//
//  SecondViewController.swift
//  D05
//
//  Created by Oleksii ZHADAIEV on 10/7/19.
//  Copyright © 2019 Oleksii ZHADAIEV. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class SecondViewController: UIViewController {

    @IBOutlet weak var currentLocation: UIButton!
    @IBOutlet weak var typeBar: UISegmentedControl!
    @IBOutlet weak var mapView: MKMapView!
    var locationManager = CLLocationManager()

    override func viewDidLoad() {
        super.viewDidLoad()
        //
        addPins()
        goToCoords(coords: locations[0].coords)
        //
        locationManager.requestWhenInUseAuthorization()
        locationManager.desiredAccuracy = kCLLocationAccuracyNearestTenMeters
        locationManager.distanceFilter = 10
        if CLLocationManager.locationServicesEnabled() {
            locationManager.startUpdatingLocation()
        } else {
            currentLocation.isEnabled = false
            currentLocation.isHidden = true
        }
        mapView.showsScale = true
        mapView.showsUserLocation = true
        //
        typeBar.layer.cornerRadius = 10
    }
    
    @IBAction func typeChange(_ sender: UISegmentedControl) {
        switch sender.selectedSegmentIndex {
        case 0:
            mapView.mapType = MKMapType.standard
        case 1:
            mapView.mapType = MKMapType.satellite
        case 2:
            mapView.mapType = MKMapType.hybrid
        default:
            print("Unknown type")
        }
    }
    @IBAction func goToCurrentLocation(_ sender: UIButton) {
        mapView.showsUserLocation = true
        
        if locationManager.location != nil {
            goToCoords(coords: locationManager.location!.coordinate)
        }
    }
    
    private func addPins() {
        for loc in locations {
            let pin = MKPointAnnotation()
            pin.coordinate = loc.coords
            pin.title = loc.title
            pin.subtitle = loc.description
            mapView.addAnnotation(pin)
        }
    }
    
    func goToCoords(coords: CLLocationCoordinate2D) {
        let cnt = coords
        let span = MKCoordinateSpan(latitudeDelta: 0.01, longitudeDelta: 0.01)
        let reg = MKCoordinateRegion(center: cnt, span: span)
        mapView.setRegion(reg, animated: true)
    }
}

extension SecondViewController: MKMapViewDelegate {
    func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView? {
        if annotation.isKind(of: MKUserLocation.self) {
            return nil
        }
        let view = MKPinAnnotationView(annotation: annotation, reuseIdentifier: "pin");
        view.canShowCallout = true;
        view.calloutOffset = CGPoint(x: -5, y: 5);
        for loc in locations {
            if (loc.coords.latitude == annotation.coordinate.latitude
                && loc.coords.longitude == annotation.coordinate.longitude) {
                view.pinTintColor = loc.color;
                break;
            }
        }
        return (view);
    }
}

extension SecondViewController: CLLocationManagerDelegate {
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        goToCoords(coords: locations[0].coordinate)
        
    }
}
