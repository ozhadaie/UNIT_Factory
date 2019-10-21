let colors = Color.allColors
for c in colors {
    print(c.rawValue)
}

let values = Value.allValues
for v in values {
    print(v.rawValue)
}

var c1:Card = Card(c: Color.spade, v: Value.Ace)
var c2:Card = Card(c: Color.spade, v: Value.Ace)
print(c1)
print(c2)
print(c1.isEqual(c2))
c1.color = Color.club
print(c1)
print(c2)
print(c1.isEqual(c2))
