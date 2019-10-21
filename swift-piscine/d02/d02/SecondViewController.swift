
import UIKit

class SecondViewController: UIViewController {
    @IBOutlet weak var nameField: UITextField!
    
    @IBOutlet weak var descriptionField: UITextView!
    
    @IBOutlet weak var dateField: UIDatePicker!
    
    
    @IBAction func doneBtn(_ sender: Any) {
        if let name = nameField.text {
            print(name)
        }
        if let description = descriptionField.text {
            print(description)
        }
        let format = DateFormatter()
        format.dateFormat = "dd MMMM yyyy HH:mm:ss"
        let date  = format.string(from: dateField.date)
        print(date)
        if nameField.text != "" {
            
            performSegue(withIdentifier: "toFirstView", sender: self)
        }
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        let format = DateFormatter()
        format.dateFormat = "dd MMMM yyyy HH:mm:ss"
        let date  = format.string(from: dateField.date)
        Data.names.append((nameField.text!, descriptionField.text!, date))
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        dateField.minimumDate = Date()
        nameField.placeholder = "name"
        descriptionField.layer.borderWidth = 1
        descriptionField.layer.borderColor = UIColor.black.cgColor
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
}
