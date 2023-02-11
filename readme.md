# C-Uno

Uno made with C!

## Architecture

I'll instantiate all 108 cards on the stack. The deck, pile, and each player's hand will be a list of pointers to cards. The pointers will point to the cards on the stack. The lists keeping the pointers will be vectors that I'll implement, allocating pointers (growing) or deallocating pointers (shrinking) as the game goes on.

## Todo

- model a series of turns
- model a turn for players and npc
- model the discard pile
- model player's hands

## Todo History

- *2023-02-11* shuffling
- *2023-02-10* model card data by card effects
- *2023-02-07* add FillCards() and PrintCards()
- *2023-02-06* start project

