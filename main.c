#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum Color { blue, red, green, yellow, anyColor, noColor, };
enum Number { zero, one, two, three, four, five, six, seven, eight, nine, noNumber, };
enum TurnEffect { skip, reverse, noTurnEffect, };
enum DrawEffect { draw2, draw4, noDrawEffect, };

struct Card {
	enum Number number;
	enum Color color;
	enum TurnEffect turn_effect;
	enum DrawEffect draw_effect;
};

void FillCards(struct Card *cards);
void PrintCards(struct Card *cards);

char *ColorLabel(enum Color color);
char *TurnEffectLabel(enum TurnEffect turn_effect);
char *DrawEffectLabel(enum DrawEffect draw_effect);

int main() {
	struct Card cards[108];
	FillCards(cards);
	PrintCards(cards);
	return 0;
}

/**
 * Cards should be an array of 108 cards.
 */
void FillCards(struct Card *cards) {
	// An UNO deck has 108 cards in total.
	for (int i = 0; i < 108; i++) {
		// Zero struct
		cards[i].number = noNumber;
		cards[i].color = noColor;
		cards[i].turn_effect = noTurnEffect;
		cards[i].draw_effect = noDrawEffect;

		if (i < 76) {
			// Cards 1-76: 76 colored & numbered cards There are 19 of each color.
			// These are numbered 0-9, with each color having one 0 and two of 1-9.
			cards[i].number = ceilf((i % 19) / 2.0);
			cards[i].color = i / 19;
		} else if (i < 84) {
			// Cards 77-84: 8 colored skip cards
			cards[i].turn_effect = skip;
			cards[i].color = (i - 76) / 2;
		} else if (i < 92) {
			// Cards 85-92: 8 colored reverse cards
			cards[i].turn_effect = reverse;
			cards[i].color = (i - 84) / 2;
		} else if (i < 100) {
			// Cards 93-100: 8 colored draw 2 cards
			cards[i].draw_effect = draw2;
			cards[i].color = (i - 92) / 2;
		} else if (i < 104) {
			// Cards 101-104: 4 wild cards
			cards[i].color = anyColor;
		} else if (i < 108) {
			// Cards 105-108: 4 wild draw 4 cards
			cards[i].color = anyColor;
			cards[i].draw_effect = draw4;
		}
	}
}

void PrintCards(struct Card *cards) {
	printf("Here's what we have in our cards...\n");
	for (int i = 0; i < 108; i++) {
		struct Card *card = &cards[i];
		printf("Card #%i: ", i+1);
		if (card->color != noColor) {
			printf("%s ", ColorLabel(card->color));
		}
		if (card->number != noNumber) {
			printf("%i ", card->number);
		}
		if (card->turn_effect != noTurnEffect) {
			printf("%s ", TurnEffectLabel(card->turn_effect));
		}
		if (card->draw_effect != noDrawEffect) {
			printf("%s ", DrawEffectLabel(card->draw_effect));
		}
		printf("\n");
	}
}

char *ColorLabel(enum Color color) {
	if (color == blue) {
		return "blue";
	} else if (color == red) {
		return "red";
	} else if (color == green) {
		return "green";
	} else if (color == yellow) {
		return "yellow";
	} else if (color == anyColor) {
		return "wild";
	} else {
		return "";
	}
}

char *TurnEffectLabel(enum TurnEffect turn_effect) {
	if (turn_effect == skip) {
		return "skip";
	} else if (turn_effect == reverse) {
		return "reverse";
	} else {
		return "";
	}
}

char *DrawEffectLabel(enum DrawEffect draw_effect) {
	if (draw_effect == draw2) {
		return "draw 2";
	} else if (draw_effect == draw4) {
		return "draw 4";
	} else {
		return "";
	}
}
