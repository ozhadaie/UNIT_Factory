var testDeck = Deck(shuffle: false)
var x: Card?

print(testDeck)

x = testDeck.draw()
x = testDeck.draw()
x = testDeck.draw()
x = testDeck.draw()
x = testDeck.draw()
x = testDeck.draw()
x = testDeck.draw()
x = testDeck.draw()
x = testDeck.draw()
x = testDeck.draw()

x = nil

print("OUTS:")
print(testDeck.outs)

print()
testDeck.fold(c: testDeck.outs[0])
testDeck.fold(c: testDeck.outs[1])
testDeck.fold(c: testDeck.outs[2])
testDeck.fold(c: testDeck.outs[3])

print("DISCARDS")
print(testDeck.discards)

print("OUTS:")
print(testDeck.outs)
print()
print(testDeck.cards)

