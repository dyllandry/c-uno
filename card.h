#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>

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

char *CreateCardLabel(struct Card card);
void PrintCard(struct Card card);

struct UnoCardsData {
  struct Card cards[108];
};

struct UnoCardsData CreateUnoCardsData();

struct CardArray {
  struct Card **cards;
  size_t size;
  size_t used;
};

struct CardArray CreateCardArray();
void PushCardArray(struct CardArray *array, struct Card *card);
void PrintCardArray(struct CardArray *array);

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

void DealCard(struct CardStack *deck, struct CardArray *hand);
void DealStartingHand(struct CardStack *deck, struct CardArray *hand);

int RandomInt(int min, int max);

#endif
