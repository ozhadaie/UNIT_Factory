//
//  ViewController.swift
//  D03
//
//  Created by Oleksii ZHADAIEV on 10/4/19.
//  Copyright © 2019 Oleksii ZHADAIEV. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UICollectionViewDataSource, UICollectionViewDelegate {
    
    let imgs: [URL] = [
        URL(string: "https://www.nasa.gov/sites/default/files/thumbnails/image/haguereturns_0.jpg")!,
        URL(string: "https://www.nasa.gov/sites/default/files/thumbnails/image/sdo_9-21-2017_transit_hmi-171_blend.jpg")!,
        URL(string: "https://www.nasa.gov/sites/default/files/thumbnails/image/moon_satellite.gif")!,
        URL(string: "https://www.nasa.gov/sites/default/files/thumbnails/image/3._cme_gif_11660.gif")!,
        URL(string: "ERROR_PHOTO")!
]
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return imgs.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "imageView", for: indexPath) as! ImgCollectionViewCell
        DispatchQueue.global().async {
            let image = try? Data (contentsOf: self.imgs[indexPath.row])
            if image != nil {
                DispatchQueue.main.async {
                    cell.indicator.hidesWhenStopped = true
                    cell.indicator.stopAnimating()
                    cell.image.image = UIImage(data: image!)
                }
            } else {
                let alert = UIAlertController(title: "No connection", message: "Cannot receive photo \(self.imgs[indexPath.row])", preferredStyle: UIAlertController.Style.alert)
                alert.addAction(UIAlertAction(title: "OK", style: UIAlertAction.Style.default, handler: nil))
                self.present(alert, animated: true, completion: nil)
            }
        }
        cell.indicator.startAnimating()
        return cell
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        let seg = segue.destination as! ScrollViewController
        let cell = sender! as! ImgCollectionViewCell
        if cell.image.image != nil {
            seg.image = cell.image.image!
        } else {
            let alert = UIAlertController(title: "No connection", message: "Cannot receive photo", preferredStyle: UIAlertController.Style.alert)
            alert.addAction(UIAlertAction(title: "OK", style: UIAlertAction.Style.default, handler: nil))
            self.present(alert, animated: true, completion: nil)
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }


}

