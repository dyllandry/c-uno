#include "array.h"
#include "card.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef bool (*TestFunction)();

enum TestResult {
  passResult,
  failResult,
  noResult,
};

struct Test {
  char *name;
  TestFunction function;
  enum TestResult result;
};

struct Test CreateTest(char *name, bool (*function)());
void AddTestToTests(struct Array *tests, char *name, bool (*function)());

bool test_can_play_card();
bool test_can_play_card_can_play_blue1_on_red1();
bool test_can_play_card_can_play_blue1_on_blue2();
bool test_can_play_card_cannot_play_blue1_on_red2();
bool test_can_play_card_can_play_blue_skip_on_red_skip();
bool test_can_play_card_can_play_blue_draw_2_on_red_draw_2();
bool test_can_play_card_cannot_play_blue_skip_on_red_draw_2();
bool test_can_play_card_can_play_wild_blue_on_blue_1();
bool test_can_play_card_cannot_play_wild_blue_on_red_1();

bool test_array();
bool test_array_push_int();
bool test_array_push_string();
bool test_array_get_element_array();

int main() {
  struct Array tests = CreateArray(sizeof(struct Test));

  AddTestToTests(&tests, "CanPlayCard(): can play blue 1 on red 1",
                 &test_can_play_card_can_play_blue1_on_red1);
  AddTestToTests(&tests, "CanPlayCard(): can play blue 1 on blue 2",
                 &test_can_play_card_can_play_blue1_on_blue2);
  AddTestToTests(&tests, "CanPlayCard(): cannot play blue 1 on red 2",
                 &test_can_play_card_cannot_play_blue1_on_red2);
  AddTestToTests(&tests, "CanPlayCard(): can play blue skip on red skip",
                 &test_can_play_card_can_play_blue_skip_on_red_skip);
  AddTestToTests(&tests, "CanPlayCard(): can play blue draw 2 on red draw 2",
                 &test_can_play_card_can_play_blue_draw_2_on_red_draw_2);
  AddTestToTests(&tests, "CanPlayCard(): cannot play blue skip on red draw 2",
                 &test_can_play_card_cannot_play_blue_skip_on_red_draw_2);
  AddTestToTests(&tests, "CanPlayCard(): can play wild blue on blue 1",
                 &test_can_play_card_can_play_wild_blue_on_blue_1);
  AddTestToTests(&tests, "CanPlayCard(): cannot play wild blue on red 1",
                 &test_can_play_card_cannot_play_wild_blue_on_red_1);
  AddTestToTests(
      &tests, "PushArray(): can push an int, then get it back by manual access",
      &test_array_push_int);
  AddTestToTests(
      &tests,
      "PushArray(): can push a string, then get it back by manual access",
      &test_array_push_string);
  AddTestToTests(&tests, "GetElementArray(): can get an element ",
                 &test_array_get_element_array);

  printf("running %zu tests\n", tests.used);
  for (int i = 0; i < tests.used; i++) {
    struct Test *test = GetElementArray(&tests, i);
    bool pass = (*test->function)();
    enum TestResult result;
    if (pass) {
      result = passResult;
    } else {
      result = failResult;
    }
    test->result = result;
  }

  printf("\n");

  for (int i = 0; i < tests.used; i++) {
    struct Test *test = GetElementArray(&tests, i);
    if (test->result == passResult) {
      printf("PASS %s\n", test->name);
    }
  }

  printf("\n");

  for (int i = 0; i < tests.used; i++) {
    struct Test *test = GetElementArray(&tests, i);
    if (test->result == failResult) {
      printf("FAIL %s\n", test->name);
    }
  }

  return 0;
}

struct Test CreateTest(char *name, bool (*function)()) {
  struct Test test;
  test.name = name;
  test.function = function;
  test.result = noResult;
  return test;
}

void AddTestToTests(struct Array *tests, char *name, bool (*function)()) {
  struct Test test = CreateTest(name, function);
  PushArray(tests, &test);
}

bool test_array() {
  return test_array_push_int() && test_array_push_string() &&
         test_array_get_element_array();
}

bool test_array_push_int() {
  struct Array array = CreateArray(sizeof(int));
  int year = 2023;
  int month = 4;
  PushArray(&array, &year);
  PushArray(&array, &month);
  int received_year = ((int *)array.elements)[0];
  int received_month = ((int *)array.elements)[1];
  return received_year == year && received_month == month;
}

bool test_array_push_string() {
  struct Array array = CreateArray(sizeof(char *));
  char *first_name = "dylan";
  char *last_name = "landry";
  PushArray(&array, &first_name);
  PushArray(&array, &last_name);
  char *received_first_name = ((char **)array.elements)[0];
  char *received_last_name = ((char **)array.elements)[1];
  return strcmp(received_first_name, first_name) == 0 &&
         strcmp(received_last_name, last_name) == 0;
}

bool test_array_get_element_array() {
  struct Array array = CreateArray(sizeof(int));
  int year = 2023;
  int month = 4;
  PushArray(&array, &year);
  PushArray(&array, &month);
  int *received_year = GetElementArray(&array, 0);
  int *received_month = GetElementArray(&array, 1);
  return *received_year == year && *received_month == month;
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
