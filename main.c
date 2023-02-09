#include <stdio.h>
#include <stdlib.h>

enum Color {
	blue,
	red,
	green,
	yellow,
};

char *ColorLabel(enum Color color) {
	if (color == blue) {
		return "blue";
	} else if (color == red) {
		return "red";
	} else if (color == green) {
		return "green";
	} else if (color == yellow) {
		return "yellow";
	} else {
		return "";
	}
}

enum CardType {
	number,
	skip,
	reverse,
	draw2,
	wild,
	wildDraw4,
};

char *CardTypeLabel(enum CardType type) {
	if (type == number) {
		return "number";
	} else if (type == skip) {
		return "skip";
	} else if (type == reverse) {
		return "reverse";
	} else if (type == draw2) {
		return "draw 2";
	} else if (type == wild) {
		return "wild";
	} else if (type == wildDraw4) {
		return "wild draw 4";
	} else {
		return "";
	}
}

struct Card {
	enum CardType type;
	// Null unless card type is number.
	int *number;
	// Null unless card type is one of number, skip, reverse, or draw2.
	enum Color *color;
};

/**
 * Cards should be an array of 108 cards.
 */
void FillCards(struct Card *cards) {
	for (int i = 0; i < 108; i++) {
		struct Card *card = &cards[i];
		card->number = 0;
		card->color = 0;

		// An UNO deck has 108 cards in total.
		// Cards 1-76: 76 colored & numbered cards
		// Cards 77-84: 8 colored skip cards
		// Cards 85-92: 8 colored reverse cards
		// Cards 93-100: 8 colored draw 2 cards
		// Cards 101-104: 4 wild cards
		// Cards 105-108: 4 wild draw 4 cards

		// Cards 1-100 are colored.
		if (i < 100) {
			card->color = malloc(sizeof card->color);
		}

		// Of the 76 colored & numbered cards, there are 19 of each color. These
		// are numbered 0-9, with each color having one 0 and two of 1-9.
		if (i < 76) {
			card->type = number;
			card->number = malloc(sizeof card->number);
			*card->number = (i % 19 + 1) / 2;
			*card->color = i / 19;
		} else if (i < 84) {
			*card->color = (i % 4);
			card->type = skip;
		} else if (i < 92) {
			*card->color = (i % 4);
			card->type = reverse;
		} else if (i < 100) {
			*card->color = (i % 4);
			card->type = draw2;
		} else if (i < 104) {
			card->type = wild;
		} else if (i < 108) {
			card->type = wildDraw4;
		}
	}
}

void PrintCards(struct Card *cards) {
	printf("Here's what we have in our cards...\n");
	for (int i = 0; i < 108; i++) {
		struct Card *card = &cards[i];
		printf("Card #%i: ", i+1);
		if (card->color != 0) {
			printf("%s ", ColorLabel(*card->color));
		}
		if (card->type != number) {
			printf("%s ", CardTypeLabel(card->type));
		}
		if(card->number != 0) {
			printf("%i", *card->number);
		}
		printf("\n");
	}
}

int main() {
	struct Card cards[108];
	FillCards(cards);
	PrintCards(cards);
	return 0;
}
