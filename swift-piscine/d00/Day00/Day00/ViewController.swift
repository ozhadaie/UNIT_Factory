//
//  ViewController.swift
//  Day00
//
//  Created by Oleksii ZHADAIEV on 9/30/19.
//  Copyright © 2019 Oleksii ZHADAIEV. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    
    @IBOutlet weak var label: UILabel!
    
    var firstNum:Double?
    var secondNum:Double?
    var lastOp:Int?
    var result:Double?
    
    func logThis() {
        print("------------------")
        print("1Num:")
        print(firstNum)
        print("2Num:")
        print(secondNum)
        print("LastOp:")
        print(lastOp)
        print("Result:")
        print(result)
    }
    @IBAction func onChangeSign(_ sender: UIButton) {
        var labelNum:Double
        if label.text == "Not a number" {
            labelNum = 0
            firstNum = 0
            secondNum = nil
        } else {
            firstNum = -Double(label.text!)!
        }
        label.text = String(format: "%0.f", firstNum!)
    }
    @IBAction func onAC(_ sender: UIButton) {
        firstNum = 0
        secondNum = nil
        lastOp = nil
        result = nil
        label.text = "0"
    }
    @IBAction func onDigClick(_ sender: UIButton) {
        var labelNum:Double
        if result != nil {
            firstNum = 0
        }
        if label.text == "Not a number" {
            labelNum = 0
            firstNum = 0
            secondNum = nil
        } else {
            labelNum = Double(label.text!)!
        }
        if lastOp != nil {
            if secondNum == nil {
                secondNum = 0
            }
            labelNum = secondNum!
        }
        let digTag = Double(sender.tag)
        let out:Double?
        if labelNum >= 0 {
            out = labelNum * 10 + digTag
        } else {
            out = labelNum * 10 - digTag
        }
        if out != nil {
            if lastOp != nil {
                secondNum = out!
            } else {
                firstNum = out!
            }
            label.text = String(format: "%0.f", out!)
        }
        logThis()
    }
    
    @IBAction func onOperClick(_ sender: UIButton) {
        let labelNum:Double
        if label.text == "Not a number" {
            labelNum = 0
            firstNum = 0
            secondNum = nil
        } else {
            labelNum = Double(label.text!)!
        }
        let opTag = Int(sender.tag)
        var out:Double?
        if lastOp == nil {
            lastOp = opTag
        } else {
            if secondNum != nil {
                if lastOp! == 1 {
                    if secondNum! != 0 {
                        out = round(firstNum! / secondNum!)
                    }
                } else if lastOp! == 2 {
                    out = firstNum! * secondNum!
                } else if lastOp! == 3 {
                    out = firstNum! - secondNum!
                } else if lastOp! == 4 {
                    out = firstNum! + secondNum!
                }
                if out == nil {
                    label.text = "Not a number"
                } else {
                    if result == nil {
                        result = out!
                        label.text = String(format: "%0.f", result!)
                        firstNum = result
                    }
                }
            }
            lastOp = opTag
            secondNum = nil
            result = nil
        }
        logThis()
    }
    
    @IBAction func onResClick(_ sender: UIButton) {
        if lastOp != nil && firstNum != nil {
            if secondNum == nil {
                secondNum = firstNum
            }
            if lastOp! == 1 {
                if secondNum! != 0 {
                    result = floor(firstNum! / secondNum!)
                }
            } else if lastOp! == 2 {
                result = firstNum! * secondNum!
            } else if lastOp! == 3 {
                result = firstNum! - secondNum!
            } else if lastOp! == 4 {
                result = firstNum! + secondNum!
            }
            if result == nil {
                label.text = "Not a number"
            } else {
                firstNum = result
                label.text = String(format: "%0.f", result!)
            }
        }
        logThis()
    }
}
