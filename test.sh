#!/usr/bin/env bash

gcc -std=c99 test.c card.c array.c -lm -o test.out && ./test.out

