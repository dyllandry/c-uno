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
	numbered,
	skip,
	reverse,
	draw2,
	wild,
	wildDraw4,
};

char *CardTypeLabel(enum CardType type) {
	if (type == numbered) {
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

struct NumberedCardContent {
	int number;
	enum Color color;
};

struct SkipCardContent {
	enum Color color;
};

struct ReverseCardContent {
	enum Color color;
};

struct Draw2CardContent {
	enum Color color;
};

struct NoCardContent {
	int nothing;
};

struct Card {
	enum CardType type;
	union {
		struct NumberedCardContent numbered;
		struct SkipCardContent skip;
		struct ReverseCardContent reverse;
		struct Draw2CardContent draw2;
		struct NoCardContent none;
	} content;
};

/**
 * Cards should be an array of 108 cards.
 */
void FillCards(struct Card *cards) {
	for (int i = 0; i < 108; i++) {
		// An UNO deck has 108 cards in total.
		if (i < 76) {
			// Cards 1-76: 76 colored & numbered cards There are 19 of each color.
			// These are numbered 0-9, with each color having one 0 and two of 1-9.
			cards[i].type = numbered;
			cards[i].content.numbered.number = ((i % 19) + 1 ) / 2;
			cards[i].content.numbered.color = i / 19;
		} else if (i < 84) {
			// Cards 77-84: 8 colored skip cards
			cards[i].type = skip;
			cards[i].content.skip.color = (i - 76) / 2;
		} else if (i < 92) {
			// Cards 85-92: 8 colored reverse cards
			cards[i].type = reverse;
			cards[i].content.reverse.color = (i - 84) / 2;
		} else if (i < 100) {
			// Cards 93-100: 8 colored draw 2 cards
			cards[i].type = draw2;
			cards[i].content.draw2.color = (i - 92) / 2;
		} else if (i < 104) {
			// Cards 101-104: 4 wild cards
			cards[i].type = wild;
			cards[i].content.none.nothing = 0;
		} else if (i < 108) {
			// Cards 105-108: 4 wild draw 4 cards
			cards[i].type = wildDraw4;
			cards[i].content.none.nothing = 0;
		}
	}
}

void PrintCards(struct Card *cards) {
	printf("Here's what we have in our cards...\n");
	for (int i = 0; i < 108; i++) {
		struct Card *card = &cards[i];
		printf("Card #%i: ", i+1);
		if (card->type == numbered) {
			printf("%s ", ColorLabel(card->content.numbered.color));
			printf("%i", card->content.numbered.number);
		} else if (card->type == skip) {
			printf("%s ", ColorLabel(card->content.skip.color));
			printf("%s", CardTypeLabel(card->type));
		} else if (card->type == reverse) {
			printf("%s ", ColorLabel(card->content.reverse.color));
			printf("%s", CardTypeLabel(card->type));
		} else if (card->type == draw2) {
			printf("%s ", ColorLabel(card->content.draw2.color));
			printf("%s", CardTypeLabel(card->type));
		} else {
			printf("%s", CardTypeLabel(card->type));
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
