# C-Uno

Uno made with C!

## Todo

- model player's hands
	- Has a dynamically allocated array of dynamically allocated cards so the array can grow in size. Players might have only 5 cards in their hand, and possibly never more than 15.
- model the discard pile
	- Has an array of dynamically allocated cards with a static length of 108. Discard pile will start with 0 cards, but is very likely to eventually contain most of the 108 cards.
- model a series of turns
- model a turn for players and npc

## Todo History

- *2023-02-14*: add CardArray, first dynamically sized array implementation!
- *2023-02-13*: add CreateCardLabel(), first time returning allocated char string
- *2023-02-12*: model the deck
- *2023-02-11*: shuffling
- *2023-02-10*: model card data by card effects
- *2023-02-07*: add FillCards() and PrintCards()
- *2023-02-06*: start project

