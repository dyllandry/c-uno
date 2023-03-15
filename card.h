#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>
#include "array.h"

enum Color {
  blue,
  red,
  green,
  yellow,
  noColor,
};

enum Number {
  zero,
  one,
  two,
  three,
  four,
  five,
  six,
  seven,
  eight,
  nine,
  noNumber,
};

enum TurnEffect {
  skip,
  reverse,
  noTurnEffect,
};

enum DrawEffect {
  draw2,
  draw4,
  noDrawEffect,
};

char *ColorLabel(enum Color color);
char *WildLabel(bool wild);
char *NumberLabel(enum Number number);
char *TurnEffectLabel(enum TurnEffect turn_effect);
char *DrawEffectLabel(enum DrawEffect draw_effect);

struct Card {
  enum Number number;
  enum Color color;
  enum TurnEffect turn_effect;
  enum DrawEffect draw_effect;
  bool wild;
};

struct Card CreateCard();
char *CreateCardLabel(struct Card card);
void PrintCard(struct Card card);

struct UnoCardsData {
  struct Card cards[108];
};

struct UnoCardsData CreateUnoCardsData();

void PrintCards(struct Array *array);

struct CardStack {
  struct Card **cards;
  size_t size;
  size_t used;
};

struct CardStack CreateCardStack();
void PushCardStack(struct CardStack *stack, struct Card *card);
struct Card *PopCardStack(struct CardStack *stack);
bool IsEmptyCardStack(struct CardStack *stack);
void PrintCardStack(struct CardStack *stack);
void ShuffleCardStack(struct CardStack *stack);

void DealCard(struct CardStack *deck, struct Array *hand);
void DealStartingHand(struct CardStack *deck, struct Array *hand);

bool CanPlayCard(struct Card *last_played_card, struct Card *card_to_play);

int RandomInt(int min, int max);

#endif
