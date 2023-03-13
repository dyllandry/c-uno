#include "card.h"
#include "array.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct CardArray CreateCardArray() {
  struct CardArray array;
  array.size = 1;
  array.used = 0;
  array.cards = malloc(array.size * sizeof(*array.cards));
  array.cards[0] = 0;
  return array;
}

void PushCardArray(struct CardArray *array, struct Card *card) {
  if (array->used == array->size) {
    array->size *= 2;
    array->cards = realloc(array->cards, array->size * sizeof(*array->cards));
  }
  array->cards[array->used] = card;
  array->used++;
}

void PrintCards(struct Array *array) {
  for (int i = 0; i < array->used; i++) {
    struct Card *card = GetElementArray(array, i);
    PrintCard(*card);
  }
}

struct CardStack CreateCardStack() {
  struct CardStack stack;
  stack.size = 1;
  stack.used = 0;
  stack.cards = malloc(stack.size * sizeof(*stack.cards));
  stack.cards[0] = 0;
  return stack;
}

void PushCardStack(struct CardStack *stack, struct Card *card) {
  if (stack->used == stack->size) {
    stack->size *= 2;
    stack->cards = realloc(stack->cards, stack->size * sizeof(*stack->cards));
  }
  stack->cards[stack->used] = card;
  stack->used++;
}

struct Card *PopCardStack(struct CardStack *stack) {
  if (stack->used == 0) {
    return 0;
  }
  struct Card *card = &*stack->cards[stack->used - 1];
  stack->cards[stack->used - 1] = 0;
  stack->used--;
  return card;
}

bool IsEmptyCardStack(struct CardStack *stack) { return stack->used == 0; }

void PrintCardStack(struct CardStack *stack) {
  printf("Cards starting at the top...\n");
  for (int i = stack->used - 1; i >= 0; i--) {
    char *card_label = CreateCardLabel(*stack->cards[i]);
    printf("Card #%lu: %s\n", stack->used - i, card_label);
  }
}

void ShuffleCardStack(struct CardStack *stack) {
  if (stack->used == 0) {
    return;
  }
  for (int i = 0; i < 100; i++) {
    int card_a_position = RandomInt(0, stack->used - 1);
    int card_b_position = RandomInt(0, stack->used - 1);
    struct Card *card_a = stack->cards[card_a_position];
    struct Card *card_b = stack->cards[card_b_position];
    stack->cards[card_a_position] = card_b;
    stack->cards[card_b_position] = card_a;
  }
}

char *CreateCardLabel(struct Card card) {
  char *color_label = ColorLabel(card.color);
  char *number_label = NumberLabel(card.number);
  char *turn_effect_label = TurnEffectLabel(card.turn_effect);
  char *draw_effect_label = DrawEffectLabel(card.draw_effect);
  char *format = "%s %s %s %s";
  // snprintf returns number of bytes to be written
  // passing NULL for char buffer and 0 for bufsz will make it skip writing any
  // data
  size_t card_label_length =
      snprintf(NULL, 0, format, color_label, number_label, turn_effect_label,
               draw_effect_label);
  char *card_label = malloc(1 + card_label_length);
  // here we actually write the char string to the buffer along with the needed
  // bufsz
  snprintf(card_label, 1 + card_label_length, format, color_label, number_label,
           turn_effect_label, draw_effect_label);
  return card_label;
}

void PrintCard(struct Card card) {
  char *label = CreateCardLabel(card);
  printf("Card: %s\n", label);
  free(label);
}

/**
 * Inclusive.
 */
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
  } else {
    return "";
  }
}

char *NumberLabel(enum Number number) {
  if (number == noNumber) {
    return "";
  } else {
    size_t label_length = snprintf(NULL, 0, "%i", number);
    char *number_label = malloc(1 + label_length);
    snprintf(number_label, 1 + label_length, "%i", number);
    return number_label;
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

struct UnoCardsData CreateUnoCardsData() {
  struct UnoCardsData uno_cards_data;
  for (int i = 0; i < 108; i++) {
    struct Card new_card = CreateCard();

    if (i < 76) {
      // Cards 1-76: 76 colored & numbered cards There are 19 of each color.
      // These are numbered 0-9, with each color having one 0 and two of 1-9.
      new_card.number = ceilf((i % 19) / 2.0);
      new_card.color = i / 19;
    } else if (i < 84) {
      // Cards 77-84: 8 colored skip cards
      new_card.turn_effect = skip;
      new_card.color = (i - 76) / 2;
    } else if (i < 92) {
      // Cards 85-92: 8 colored reverse cards
      new_card.turn_effect = reverse;
      new_card.color = (i - 84) / 2;
    } else if (i < 100) {
      // Cards 93-100: 8 colored draw 2 cards
      new_card.draw_effect = draw2;
      new_card.color = (i - 92) / 2;
    } else if (i < 104) {
      // Cards 101-104: 4 wild cards
      new_card.wild = true;
    } else if (i < 108) {
      // Cards 105-108: 4 wild draw 4 cards
      new_card.wild = true;
      new_card.draw_effect = draw4;
    }
    uno_cards_data.cards[i] = new_card;
  }
  return uno_cards_data;
}

void DealCard(struct CardStack *deck, struct CardArray *hand) {
  if (deck->used == 0) {
    // TODO: shuffle discard pile into deck
  }
  struct Card *drawn_card = PopCardStack(deck);
  PushCardArray(hand, drawn_card);
}

void DealStartingHand(struct CardStack *deck, struct CardArray *hand) {
  while (hand->used < 7) {
    DealCard(deck, hand);
  }
}

bool CanPlayCard(struct Card *last_played_card, struct Card *card_to_play) {
  if (card_to_play->number != noNumber &&
      card_to_play->number == last_played_card->number) {
    return true;
  }
  if (card_to_play->color != noColor &&
      card_to_play->color == last_played_card->color) {
    return true;
  }
  if (card_to_play->turn_effect != noTurnEffect &&
      card_to_play->turn_effect == last_played_card->turn_effect) {
    return true;
  }
  if (card_to_play->draw_effect != noDrawEffect &&
      card_to_play->draw_effect == last_played_card->draw_effect) {
    return true;
  }
  return false;
}

struct Card CreateCard() {
  struct Card card;
  card.number = noNumber;
  card.color = noColor;
  card.draw_effect = noDrawEffect;
  card.turn_effect = noTurnEffect;
  card.wild = false;
  return card;
}
