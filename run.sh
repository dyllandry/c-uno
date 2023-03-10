#!/usr/bin/env bash

gcc -std=c99 main.c card.c array.c -lm -o main.out && ./main.out
