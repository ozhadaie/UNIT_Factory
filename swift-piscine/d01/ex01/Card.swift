import Foundation

class Card: NSObject {
	var color : Color
	var value : Value

	init(c : Color, v : Value) {
        self.color = c
        self.value = v
        super.init()
	}

	override var description: String {
        return "C: \(color)| V: \(value)"
	}

    override func isEqual(_ object: Any?) -> Bool {
        if let card = object as? Card {
            return (self.value == card.value && self.color == card.color)
        }
        return false
    }
}

func ==(lhs: Card, rhs: Card) -> Bool {
    return lhs.isEqual(rhs)
}
