# C-Uno

Uno made with C!

## Architecture

I'll instantiate all 108 cards on the stack. The deck, pile, and each player's hand will be a list of pointers to cards. The pointers will point to the cards on the stack. The lists keeping the pointers will be vectors that I'll implement, allocating pointers (growing) or deallocating pointers (shrinking) as the game goes on.

## Todo

