# C-Uno

Uno made with C!

## Architecture

I'll instantiate all 108 cards on the stack. The deck, pile, and each player's hand will be a list of pointers to cards. The pointers will point to the cards on the stack. The lists keeping the pointers will be vectors that I'll implement, allocating pointers (growing) or deallocating pointers (shrinking) as the game goes on.

## Todo

- I'm unhappy with how you need to remember difference between `card.content.skip.color` and `card.content.repeat.color`.
- I'm unhappy with `card.content.none.nothing = 0`
- Maybe go backwards to before union and redefine card struct with pointers.
	- I could have `Card *CreateCard()` and `void FreeCard(Card *card)`
	- Yeah I think the union adds too much complexity with the different `card.content.skip/reverse/draw2` stuff and all the needed structs like `NumberedCardContent`.
```c
struct Card {
	enum CardType type; // so game rules know what kind of card was played and what to do
	int *number; // non-null if card has a number
	enum Color *color; // non-null if a card has a color
};

Card *CreateCard() {}
void FreeCard(Card *card) {}
```

- Maybe my problems are coming from wanting to store these structs in the same array. Maybe the only thing that has to go in that array is an int to id the card. Then the ids can be shuffled by rearranging the ints. Instead of players hands being of entire structures, just have them be of card ids.
	- But then I have no clue how to work with that. If a player has a card with id 4, how do you know what card that is?
