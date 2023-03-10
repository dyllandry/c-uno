# C-Uno

Uno made with C!

## Todo

- Add tests
	- Add way of testing results
		- keep it simple first
		- need to show which tests pass and which fail
		- model test as struct with name & pointer to function to run test
		- (NEXT) add tests by adding struct to array of tests
		- those tests are all run, and their results are collected.
		- result is name of test and bool for whether it passed
		- the tests that pass are printed first, the tests that fail are printed second
		- maybe somehow a macro could make adding a test easier
			- currently would require a few steps:
				- add a test function forward declaration
				- define function
				- add test & name to array of tests
			- maybe somehow a macro could take the function name from the definition, and use that to
				- generate a name for the test that's just the function name
				- make the function pointer
				- compose the test struct
				- add the test to the array of tests
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

