#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include "Segment.h"
#include "Apple.h"

typedef struct {
	Segment* arr;
	int len;
	direction direct;
} Snake;

Snake CreateSnake(Segment head, direction direct) {
	Segment* arr = (Segment*)malloc(game_width * game_height * sizeof(Segment));
	if (arr) arr[0] = head;
	Snake snake = { arr, 1 , direct };
	return snake;
}

void ShowSnake(char game[game_height][game_width], Snake* snake) {
	for (int i = 0; i < snake->len; i++) {
		ShowSegment(game, snake->arr[i]);
	}
}

void AddSegment(Snake* snake, Segment seg) {
	snake->arr[snake->len] = seg;
	snake->len++;
}

void AddTail(Snake* snake) {
	int len = snake->len;
	Segment old_tail = snake->arr[len - 1];

	Segment new_tail = CreateSegment(CreatePair(old_tail.pos.x, old_tail.pos.y), len);

	if (snake->len == 1) {
		MoveSegment(&new_tail, reverse(snake->direct));
	}

	else {
		direction old_tail_direct;
		Segment old_pretail = snake->arr[len - 2];
		int dx = old_pretail.pos.x - old_tail.pos.x;
		int dy = old_pretail.pos.y - old_tail.pos.y;

		if (dx == 1) old_tail_direct = right;
		else if (dx == -1) old_tail_direct = left;
		else if (dy == 1) old_tail_direct = up;
		else if (dy == -1) old_tail_direct = down;

		MoveSegment(&new_tail, reverse(old_tail_direct));
	}

	AddSegment(snake, new_tail);
}

void Move(Snake* snake) {
	for (int i = snake->len - 1; i > 0; i--) {
		(snake->arr)[i].pos = (snake->arr)[i - 1].pos;
	}

	MoveSegment(&snake->arr[0], snake->direct);
}

bool isGameOver(Snake* snake) {
	Segment head = snake->arr[0];

	if (isSegOutBorders(head)) {
		return true;
	}

	if (snake->len > 1) {
		for (int i = 1; i < snake->len; i++) {
			if (isEqual(head.pos, snake->arr[i].pos)) {
				return true;
			}
		}
	}

	return false;
}

bool isAppleEaten(Snake* snake, Apple apple) {
	Segment head = snake->arr[0];
	return isEqual(head.pos, apple.pos);
}
