#!/usr/bin/env bash

mkdir -p out
gcc -std=c99 main.c card.c array.c -lm -o out/main.out && ./out/main.out
