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
  struct Card card = CreateCard();
  card.number = five;
  card.color = red;
  struct Card card_2 = CreateCard();
  card_2.number = three;
  card_2.color = blue;
  struct Card card_3 = CreateCard();
  card_3.number = seven;
  card_3.color = yellow;

  struct Array cards = CreateArray(sizeof(struct Card));
  PushArray(&cards, &card);
  PushArray(&cards, &card_2);
  PushArray(&cards, &card_3);

	PrintCards(&cards);
}

struct Player CreatePlayer() {
  struct Player player;
  player.hand = CreateCardArray();
  return player;
}
