#include "array.h"
#include "card.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Player {
  struct CardArray hand;
};

struct Player CreatePlayer();

int main() {
  struct UnoCardsData uno_cards_data = CreateUnoCardsData();
  struct CardStack deck = CreateCardStack();
  for (int i = 0;
       i < sizeof(uno_cards_data.cards) / sizeof(uno_cards_data.cards[0]);
       i++) {
    PushCardStack(&deck, &uno_cards_data.cards[i]);
  }
  struct Array hand = CreateArray(sizeof(struct Card));
  DealStartingHand(&deck, &hand);
  PrintCards(&hand);
}

struct Player CreatePlayer() {
  struct Player player;
  player.hand = CreateCardArray();
  return player;
}
