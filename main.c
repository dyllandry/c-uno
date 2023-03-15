#include "array.h"
#include "card.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Player {
  struct Array hand;
};

struct Player CreatePlayer();

int main() {
  struct UnoCardsData uno_cards_data = CreateUnoCardsData();
  struct Array deck = CreateArray(sizeof(struct Card));
  for (int i = 0;
       i < sizeof(uno_cards_data.cards) / sizeof(uno_cards_data.cards[0]);
       i++) {
    PushArray(&deck, &uno_cards_data.cards[i]);
  }
  ShuffleCards(&deck);
  struct Player player = CreatePlayer();
  for (int i = 0; i < 5; i++) {
    struct Card card = ((struct Card *)deck.elements)[i];
    PushArray(&player.hand, &card);
  }
  PrintCards(&player.hand);
}

struct Player CreatePlayer() {
  struct Player player;
  player.hand = CreateArray(sizeof(struct Card));
  return player;
}
