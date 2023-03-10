#!/usr/bin/env bash

mkdir out
gcc -std=c99 test.c card.c array.c -lm -o out/test.out && ./out/test.out

