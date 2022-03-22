#pragma once
#include "consts.h"
#include "pair.h"


typedef struct {
	pair pos;
} Apple;

Apple CreateApple(pair pos) {
	Apple apple = { pos };
	return apple;
}

void ShowApple(char game[game_height][game_width], Apple apple) {
	game[game_height - 1 - apple.pos.y][apple.pos.x] = apple_pixel;
}

void SpawnApple(char game[game_height][game_width], Apple* apple) {
	srand(time(NULL));
	int x, y;
	for (;;) {
		x = rand() % game_width;
		y = rand() % game_height;
		if (game[game_height - 1 - y][x] == ' ') {
			apple->pos.x = x;
			apple->pos.y = y;
			break;
		}
	}
}
