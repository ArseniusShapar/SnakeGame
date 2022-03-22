#pragma once
#include <string.h>
#include <windows.h>
#include "Snake.h"


void DrawMap(char screen[window_height][window_width]) {
	for (int i = 0; i < game_width + 2; i++) {
		screen[0][i] = vertical_border_pixel;
		screen[game_height + 1][i] = vertical_border_pixel;
	}

	for (int j = 0; j < game_height + 2; j++) {
		screen[j][0] = horizontal_border_pixel;
		screen[j][game_width + 1] = horizontal_border_pixel;
	}
}

void ShowScore(char screen[window_height][window_width], Snake* snake) {
	int len = snake->len;
	char score[12];
	sprintf(score, "Score: %d", len);
	for (int i = 0; score[i] != '\0'; i++) {
		screen[0][game_width + 4 + i] = score[i];
	}
}

void CopyGameToScreen(char screen[window_height][window_width], char game[game_height][game_width]) {
	for (int i = 0; i < game_height; i++) {
		for (int j = 0; j < game_width; j++) {
			screen[i + 1][j + 1] = game[i][j];
		}
	}
}

void ClearGameAndScreen(char screen[window_height][window_width], char game[game_height][game_width]) {
	memset(screen, ' ', window_width * window_height);
	screen[window_height][0] = '\0';

	memset(game, ' ', game_width * game_height);
	game[game_height][0] = '\0';
}

void DrawGame(char screen[window_height][window_width], char game[game_height][game_width], Snake* snake, Apple apple) {
	DrawMap(screen);
	ShowScore(screen, snake);
	ShowSnake(game, snake);
	ShowApple(game, apple);
	CopyGameToScreen(screen, game);
	printf(screen);
}
