// declare card elements
const types = ["Spades", "Diamonds", "Club", "Heart"];
const cards = [
  "A",
  "2",
  "3",
  "4",
  "5",
  "6",
  "7",
  "8",
  "9",
  "10",
  "J",
  "Q",
  "K",
];

// empty array to contain cards
let deck = [];

// creating a deck of cards
for (let i = 0; i < types.length; i++) {
    for (let x = 0; x < cards.length; x++) {
        let card = { Value: cards[x], types: types[i] };
        deck.push(card);
    }
}

// shuffle the cards
for (let i = deck.length - 1; i > 0; i--) {
    let j = Math.floor(Math.random() * i);
    let temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
}

console.log('The first five cards are:');

// display 5 results
for (let i = 0; i < 5; i++) {
    console.log(`${deck[i].Value} of ${deck[i].types}`)
}
