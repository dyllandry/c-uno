# C-Uno

Uno made with C!

## Architecture

I'll instantiate all 108 cards on the stack. The deck, pile, and each player's hand will be a list of pointers to cards. The pointers will point to the cards on the stack. The lists keeping the pointers will be vectors that I'll implement, allocating pointers (growing) or deallocating pointers (shrinking) as the game goes on.

## Todo

- I found a different way of storing cards, by their effects.
	- The benefits are: Card structs are same size and can be stored in a single array.
	- No necessary unions.
	- No null pointers to imply "none".

```c
enum Color {
	blue,
	red,
	green,
	yellow,
	any
};

enum Number {
	none,
	one,
	...,
};

enum TurnEffect {
	skip,
	reverse
};

struct Card {
	enum Number number;
	enum Color color;
	enum TurnEffect turn_effect;
	enum DrawEffect draw_effect;
}
```

