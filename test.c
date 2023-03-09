#include "card.h"
#include <stdbool.h>
#include <stdio.h>

typedef bool (*TestFunction)();

struct Test {
  char *name;
  bool (*function)();
};

bool test_can_play_card();
bool test_can_play_card_can_play_blue1_on_red1();
bool test_can_play_card_can_play_blue1_on_blue2();
bool test_can_play_card_cannot_play_blue1_on_red2();
bool test_can_play_card_can_play_blue_skip_on_red_skip();
bool test_can_play_card_can_play_blue_draw_2_on_red_draw_2();
bool test_can_play_card_cannot_play_blue_skip_on_red_draw_2();
bool test_can_play_card_can_play_wild_blue_on_blue_1();
bool test_can_play_card_cannot_play_wild_blue_on_red_1();

int main() {

  struct Test test;
  test.name = "CanPlayCard()";
  test.function = &test_can_play_card;

  bool test_passes = (*test.function)();
  if (test_passes) {
    printf("pass\n");
  } else {
    printf("fail\n");
  }
  return 0;
}

bool test_can_play_card() {
  return test_can_play_card_can_play_blue1_on_red1() &&
         test_can_play_card_can_play_blue1_on_blue2() &&
         test_can_play_card_cannot_play_blue1_on_red2() &&
         test_can_play_card_can_play_blue_skip_on_red_skip() &&
         test_can_play_card_can_play_blue_draw_2_on_red_draw_2() &&
         test_can_play_card_cannot_play_blue_skip_on_red_draw_2() &&
         test_can_play_card_can_play_wild_blue_on_blue_1() &&
         test_can_play_card_cannot_play_wild_blue_on_red_1();
}

bool test_can_play_card_can_play_blue1_on_red1() {
  struct Card blue_1 = CreateCard();
  blue_1.number = one;
  blue_1.color = blue;

  struct Card red_1 = CreateCard();
  red_1.number = one;
  red_1.color = red;

  bool received = CanPlayCard(&red_1, &blue_1);
  bool expected = true;
  return expected == received;
}

bool test_can_play_card_can_play_blue1_on_blue2() {
  struct Card blue_1 = CreateCard();
  blue_1.number = one;
  blue_1.color = blue;

  struct Card blue_2 = CreateCard();
  blue_2.number = two;
  blue_2.color = blue;

  bool expected = true;
  bool received = CanPlayCard(&blue_1, &blue_2);
  return expected == received;
}

bool test_can_play_card_cannot_play_blue1_on_red2() {
  struct Card blue_1 = CreateCard();
  blue_1.number = one;
  blue_1.color = blue;
  struct Card red_2 = CreateCard();
  red_2.number = two;
  red_2.color = red;
  bool expected = false;
  bool received = CanPlayCard(&red_2, &blue_1);
  return expected == received;
}

bool test_can_play_card_can_play_blue_skip_on_red_skip() {
  struct Card blue_skip = CreateCard();
  blue_skip.color = blue;
  blue_skip.turn_effect = skip;

  struct Card red_skip = CreateCard();
  red_skip.color = red;
  red_skip.turn_effect = skip;

  bool expected = true;
  bool received = CanPlayCard(&red_skip, &blue_skip);
  return expected == received;
}

bool test_can_play_card_can_play_blue_draw_2_on_red_draw_2() {
  struct Card blue_draw_2 = CreateCard();
  blue_draw_2.color = blue;
  blue_draw_2.draw_effect = draw2;

  struct Card red_draw_2 = CreateCard();
  red_draw_2.color = red;
  red_draw_2.draw_effect = draw2;

  bool expected = true;
  bool received = CanPlayCard(&red_draw_2, &blue_draw_2);
  return expected == received;
}

bool test_can_play_card_cannot_play_blue_skip_on_red_draw_2() {
  struct Card blue_skip = CreateCard();
  blue_skip.color = blue;
  blue_skip.turn_effect = skip;

  struct Card red_draw_2 = CreateCard();
  red_draw_2.color = red;
  red_draw_2.draw_effect = draw2;

  bool expected = false;
  bool received = CanPlayCard(&red_draw_2, &blue_skip);
  return expected == received;
}

bool test_can_play_card_can_play_wild_blue_on_blue_1() {
  struct Card wild_blue = CreateCard();
  wild_blue.wild = true;
  wild_blue.color = blue;

  struct Card blue_1 = CreateCard();
  blue_1.color = blue;
  blue_1.number = one;

  bool expected = true;
  bool received = CanPlayCard(&blue_1, &wild_blue);
  return expected == received;
}

bool test_can_play_card_cannot_play_wild_blue_on_red_1() {
  struct Card wild_blue = CreateCard();
  wild_blue.wild = true;
  wild_blue.color = blue;

  struct Card red_1 = CreateCard();
  red_1.color = red;
  red_1.number = one;

  bool expected = false;
  bool received = CanPlayCard(&red_1, &wild_blue);
  return expected == received;
}
