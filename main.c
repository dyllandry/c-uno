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

void DealCard(struct CardStack *deck, struct Player *player);
void DealHand(struct CardStack *deck, struct Player *player);

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
	DealHand(&deck, &player);
	printf("After:\n");
	PrintCardArray(&player.hand);

	return 0;
}

struct Player CreatePlayer() {
	struct Player player;
	player.hand = CreateCardArray();
	return player;
}

void DealCard(struct CardStack *deck, struct Player *player) {
	if (deck->used == 0) {
		// TODO: shuffle discard pile into deck
	}
	struct Card *drawn_card = PopCardStack(deck);
	PushCardArray(&player->hand, drawn_card);
}

void DealHand(struct CardStack *deck, struct Player *player) {
	while (player->hand.used < 7) {
		DealCard(deck, player);
	}
}

