# C-Uno

Uno made with C!

## Todo

- Add tests
	- Add way of testing results
		- keep it simple first
		- need to show which tests pass and which fail
		- maybe can model a test as a function pointer and a test name.
				- then run all tests in an array. Print the name of those that failed.
- model the discard pile
- model playing a card
	- CanPlayCard(discard_pile, card);
	- PlayCard()
- design game loop
- model a series of turns including turns for players (skip npcs for now)

## Todo History

- *2023-03-08*: add CanPlayCard and start of testing system
- *2023-03-08*: model wild cards using own flag
- *2023-02-28*: add DealCard() and DealHand()
- *2023-02-28*: change ShuffleDeck to work with card stacks
- *2023-02-23*: change CardArray to not be a dynamic array of cards, but instead a dynamic array of pointers to cards.
- *2023-02-20*: add UnoCardsData and CardStack to implement the deck and discard pile
- *2023-02-14*: add CardArray, first dynamically sized array implementation!
- *2023-02-13*: add CreateCardLabel(), first time returning allocated char string
- *2023-02-12*: model the deck
- *2023-02-11*: shuffling
- *2023-02-10*: model card data by card effects
- *2023-02-07*: add FillCards() and PrintCards()
- *2023-02-06*: start project

