#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

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

struct Card **CreateCards();
void FreeCards(struct Card **cards);
void PrintCards(struct Card **cards);
void ShuffleCards(struct Card **cards, int shuffles);

char *ColorLabel(enum Color color);
char *TurnEffectLabel(enum TurnEffect turn_effect);
char *DrawEffectLabel(enum DrawEffect draw_effect);

int RandomInt(int min, int max);

int main() {
	struct Card **cards = CreateCards();
	ShuffleCards(cards, 500);
	PrintCards(cards);
	FreeCards(cards);
	return 0;
}

/**
 * Returns an array of 108 cards.
 */
struct Card **CreateCards() {
	// An UNO deck has 108 cards in total.
	struct Card **cards = malloc((sizeof(struct Card *)) * 108);
	for (int i = 0; i < 108; i++) {
		cards[i] = malloc(sizeof(struct Card));
		cards[i]->number = noNumber;
		cards[i]->color = noColor;
		cards[i]->turn_effect = noTurnEffect;
		cards[i]->draw_effect = noDrawEffect;

		if (i < 76) {
			// Cards 1-76: 76 colored & numbered cards There are 19 of each color->
			// These are numbered 0-9, with each color having one 0 and two of 1-9->
			cards[i]->number = ceilf((i % 19) / 2.0);
			cards[i]->color = i / 19;
		} else if (i < 84) {
			// Cards 77-84: 8 colored skip cards
			cards[i]->turn_effect = skip;
			cards[i]->color = (i - 76) / 2;
		} else if (i < 92) {
			// Cards 85-92: 8 colored reverse cards
			cards[i]->turn_effect = reverse;
			cards[i]->color = (i - 84) / 2;
		} else if (i < 100) {
			// Cards 93-100: 8 colored draw 2 cards
			cards[i]->draw_effect = draw2;
			cards[i]->color = (i - 92) / 2;
		} else if (i < 104) {
			// Cards 101-104: 4 wild cards
			cards[i]->color = anyColor;
		} else if (i < 108) {
			// Cards 105-108: 4 wild draw 4 cards
			cards[i]->color = anyColor;
			cards[i]->draw_effect = draw4;
		}
	}

	return cards;
}

/**
 * Frees an array of 108 cards.
 */
void FreeCards(struct Card **cards) {
	for (int i = 0; i < 108; i++) {
		free(cards[i]);
	}
	free(cards);
};

void PrintCards(struct Card **cards) {
	printf("Here's what we have in our cards...\n");
	for (int i = 0; i < 108; i++) {
		struct Card *card = cards[i];
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

void ShuffleCards(struct Card **cards, int shuffles) {
	for (int shuffle = 0; shuffle < shuffles; shuffle++) {
		int card_a_position = RandomInt(0, 107);
		int card_b_position = RandomInt(0,107);
		struct Card *card_a = cards[card_a_position];
		struct Card *card_b = cards[card_b_position];
		cards[card_a_position] = card_b;
		cards[card_b_position] = card_a;
	}
};

int RandomInt(int min, int max) {
	static bool seeded = false;
	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}
	double random_number_0to1 = (double)rand() / RAND_MAX;
	int range = max - min;
	int random_number = min + (int)round(random_number_0to1 * range);
	return random_number;
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
