# C-Uno

Uno made with C!

## Todo

- Add tests
	- I'd like to have a test.c file that runs tests
	- This means the game code will have to be in its own file that's includable by both main.c and test.c
	- [How to split a C program into multiple files?](https://stackoverflow.com/questions/5128664/how-to-split-a-c-program-into-multiple-files)
	- [Compiling multiple C files with gcc](https://stackoverflow.com/questions/18777326/compiling-multiple-c-files-with-gcc)
	- [Compiling multiple C files in a program](https://stackoverflow.com/questions/8728728/compiling-multiple-c-files-in-a-program)
	- Add test.c file
	- Add way of testing results
		- keep it simple first
		- need to show which tests pass and which fail
		- Can't throw errors in C.
		- like AssertEqual().
		- Maybe a macro?
	- Add shell script to run tests
- model the discard pile
- model playing a card
	- CanPlayCard(discard_pile, card);
	- PlayCard()
- design game loop
- model a series of turns including turns for players (skip npcs for now)

## Todo History

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

