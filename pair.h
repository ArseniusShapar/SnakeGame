#pragma once
#include <stdbool.h>


typedef struct {
	int x;
	int y;
} pair;

pair CreatePair(int x, int y) {
	pair pair = { x, y };
	return pair;
}

bool isEqual(pair pair1, pair pair2) {
	return ((pair1.x == pair2.x) && (pair1.y == pair2.y));
}
