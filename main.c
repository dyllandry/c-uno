#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "card.h"
#include <stdbool.h>

struct Player {
	struct CardArray hand;
};

struct Player CreatePlayer();

int main() {
	struct UnoCardsData uno_cards_data = CreateUnoCardsData();
	struct CardStack deck = CreateCardStack();
	for (int i = 0; i < sizeof uno_cards_data.cards / sizeof uno_cards_data.cards[0]; i++) {
		PushCardStack(&deck, &uno_cards_data.cards[i]);
	}
	ShuffleCardStack(&deck);

	struct Player player = CreatePlayer();
	printf("Before:\n");
	PrintCardArray(&player.hand);
	DealStartingHand(&deck, &player.hand);
	printf("After:\n");
	PrintCardArray(&player.hand);

	return 0;
}

struct Player CreatePlayer() {
	struct Player player;
	player.hand = CreateCardArray();
	return player;
}

