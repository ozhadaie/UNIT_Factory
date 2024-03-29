import Foundation

class Deck : NSObject {
    static let allSpades : [Card] = Value.allValues.map({Card(c:Color.spade, v:$0)})
    static let allDiamonds : [Card] = Value.allValues.map({Card(c:Color.diamond, v:$0)})
    static let allClubs : [Card] = Value.allValues.map({Card(c:Color.club, v:$0)})
    static let allHearts : [Card] = Value.allValues.map({Card(c:Color.heart, v:$0)})
    static let allCards : [Card] = allSpades + allClubs + allHearts + allDiamonds
}

extension Array {
    mutating func shuffle() {
        var swapi:Int
        for i in 0..<self.count {
            swapi = Int(arc4random_uniform(UInt32(self.count)))
            if swapi != i {
                self.swapAt(i, swapi)
            }
        }
    }
}
