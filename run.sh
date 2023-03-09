#!/usr/bin/env bash

gcc -std=c99 main.c card.c -lm -o main.out && ./main.out
