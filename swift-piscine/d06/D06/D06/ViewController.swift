//
//  ViewController.swift
//  D06
//
//  Created by Oleksii ZHADAIEV on 10/8/19.
//  Copyright © 2019 Oleksii ZHADAIEV. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    var animator: UIDynamicAnimator!
    var gravity: UIGravityBehavior!
    var boundaries: UICollisionBehavior!
    var bounce: UIDynamicItemBehavior!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        // Gravity
        animator = UIDynamicAnimator(referenceView: self.view)
        self.gravity = UIGravityBehavior(items: [])
        self.gravity.gravityDirection = CGVector(dx: 0.0, dy: 1.0)
        animator.addBehavior(self.gravity)
        
        // Collision
        self.boundaries = UICollisionBehavior(items: [])
        self.boundaries.translatesReferenceBoundsIntoBoundary = true
        animator.addBehavior(self.boundaries)
        
        // Elasticity
        self.bounce = UIDynamicItemBehavior(items: [])
        self.bounce.elasticity = 0.5
        animator.addBehavior(self.bounce)
    }
    
    @IBAction func tapGesture(_ sender: UITapGestureRecognizer) {
        let new = Shape(frame: CGRect(x: Int(sender.location(in: self.view).x - 50), y: Int(sender.location(in: self.view).y - 50), width: 100, height: 100))
        self.view.addSubview(new)
        
        // Add behaviors
        self.gravity.addItem(new)
        self.boundaries.addItem(new)
        self.bounce.addItem(new)
        
        // Add user interaction
        new.addGestureRecognizer(UIPanGestureRecognizer(target: self, action: #selector(panAction)))
        new.addGestureRecognizer(UIPinchGestureRecognizer(target: self, action: #selector(pinchAction)))
        new.addGestureRecognizer(UIRotationGestureRecognizer(target: self, action: #selector(rotationAction)))
    }
    
    // User interaction process
    @objc func panAction(panGesture: UIPanGestureRecognizer) {
        let shape = panGesture.view as! Shape
        
        switch panGesture.state {
        case .began:
            self.gravity.removeItem(shape)
        case .changed:
            shape.center = panGesture.location(in: self.view)
            self.animator.updateItem(usingCurrentState: shape)
        case .ended:
            self.gravity.addItem(shape)
        default:
            break
        }
    }
    
    @objc func pinchAction(pinGesture: UIPinchGestureRecognizer) {
        let shape = pinGesture.view as! Shape
        
        switch pinGesture.state {
        case .began:
            self.gravity.removeItem(shape)
        case .changed:
            self.bounce.removeItem(shape)
            self.boundaries.removeItem(shape)
            shape.bounds.size.width = shape.oldBounds.width * pinGesture.scale
            shape.bounds.size.height = shape.oldBounds.height * pinGesture.scale
            self.bounce.addItem(shape)
            self.boundaries.addItem(shape)
            self.animator.updateItem(usingCurrentState: shape)
        case .ended:
            self.gravity.addItem(shape)
        default:
            break
        }
    }
    
    @objc func rotationAction(rotationGesture: UIRotationGestureRecognizer) {
        let shape = rotationGesture.view as! Shape
        
        switch rotationGesture.state {
        case .began:
            self.gravity.removeItem(shape)
        case .changed:
            self.bounce.removeItem(shape)
            self.boundaries.removeItem(shape)
            shape.transform = shape.transform.rotated(by: rotationGesture.rotation)
            rotationGesture.rotation = 0
            self.bounce.addItem(shape)
            self.boundaries.addItem(shape)
            self.animator.updateItem(usingCurrentState: shape)
        case .ended:
            self.gravity.addItem(shape)
        default:
            break
        }
    }
}
