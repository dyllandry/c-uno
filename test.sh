#!/usr/bin/env bash

gcc -std=c99 test.c card.c -lm -o test.out && ./test.out

