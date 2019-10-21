
import UIKit

class DeathTableViewCell: UITableViewCell {

    @IBOutlet weak var nameLabel: UILabel!
    
    @IBOutlet weak var descriptionLabel: UILabel!
    
    @IBOutlet weak var dateLabel: UILabel!
    
    var name : (String, String, String)? {
        didSet {
            if let n = name {
                nameLabel?.text = n.0
                descriptionLabel?.text = n.1
                dateLabel?.text = n.2
            }
        }
    }
}
