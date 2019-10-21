

import UIKit

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    @IBOutlet weak var deathTable: UITableView!
    
    public func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Data.names.count
    }
    
    public func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "nameCell") as! DeathTableViewCell
        cell.name = Data.names[indexPath.row]
        cell.nameLabel?.numberOfLines = 0
        cell.descriptionLabel?.numberOfLines = 0
        cell.dateLabel?.numberOfLines = 0
        deathTable.rowHeight = UITableViewAutomaticDimension
        deathTable.estimatedRowHeight = 44
        return cell
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.navigationItem.hidesBackButton = true;
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
}

