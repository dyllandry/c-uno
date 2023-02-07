#include <stdio.h>

// The deck has 108 cards in total.
// Each colour has 19 cards numbered 0-9, with one 0 and two of every other number.
// Each colour has 2 skip, 2 reverse, and 2 draw 2 cards.
// There are 4 wild cards.
// There are 4 wild draw 4 cards.

enum Color {
	blue,
	red,
	green,
	yellow,
};

enum CardType {
	number,
	skip,
	reverse,
	draw2,
	wild,
	wildDraw4,
};

struct Card {
	enum CardType type;
	// Null unless card type is number.
	int* number;
	// Null unless card type is one of number, skip, reverse, or draw2.
	enum Color* color;
};

struct Card NewCard() {
	struct Card new_card = { .type = wild };
	return new_card;
}

int main() {
	struct Card card = NewCard();
	printf("card type: %i\n", card.type);
	return 0;
}
