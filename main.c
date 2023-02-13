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

struct Deck {
	struct Card *cards[108];
};

void FillDeck(struct Deck *deck);
void PrintDeck(struct Deck *deck);
void ShuffleDeck(struct Deck *deck, int shuffles);

char *ColorLabel(enum Color color);
char *TurnEffectLabel(enum TurnEffect turn_effect);
char *DrawEffectLabel(enum DrawEffect draw_effect);

int RandomInt(int min, int max);

int main() {
	struct Deck deck;
	FillDeck(&deck);
	ShuffleDeck(&deck, 500);
	PrintDeck(&deck);
	return 0;
}

/**
 * Creates 108 cards and fills an array with them.
 */
void FillDeck(struct Deck *deck) {
	// An UNO deck has 108 cards in total.
	for (int i = 0; i < 108; i++) {
		struct Card *new_card = malloc(sizeof(struct Card));
		new_card->number = noNumber;
		new_card->color = noColor;
		new_card->turn_effect = noTurnEffect;
		new_card->draw_effect = noDrawEffect;

		if (i < 76) {
			// Cards 1-76: 76 colored & numbered cards There are 19 of each color->
			// These are numbered 0-9, with each color having one 0 and two of 1-9->
			new_card->number = ceilf((i % 19) / 2.0);
			new_card->color = i / 19;
		} else if (i < 84) {
			// Cards 77-84: 8 colored skip cards
			new_card->turn_effect = skip;
			new_card->color = (i - 76) / 2;
		} else if (i < 92) {
			// Cards 85-92: 8 colored reverse cards
			new_card->turn_effect = reverse;
			new_card->color = (i - 84) / 2;
		} else if (i < 100) {
			// Cards 93-100: 8 colored draw 2 cards
			new_card->draw_effect = draw2;
			new_card->color = (i - 92) / 2;
		} else if (i < 104) {
			// Cards 101-104: 4 wild cards
			new_card->color = anyColor;
		} else if (i < 108) {
			// Cards 105-108: 4 wild draw 4 cards
			new_card->color = anyColor;
			new_card->draw_effect = draw4;
		}
		deck->cards[i] = new_card;
	}
}

void PrintDeck(struct Deck *deck) {
	printf("Here's what we have in our cards...\n");
	for (int i = 0; i < 108; i++) {
		struct Card *card = deck->cards[i];
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

void ShuffleDeck(struct Deck *deck, int shuffles) {
	for (int shuffle = 0; shuffle < shuffles; shuffle++) {
		int card_a_position = RandomInt(0, 107);
		int card_b_position = RandomInt(0,107);
		struct Card *card_a = deck->cards[card_a_position];
		struct Card *card_b = deck->cards[card_b_position];
		deck->cards[card_a_position] = card_b;
		deck->cards[card_b_position] = card_a;
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
