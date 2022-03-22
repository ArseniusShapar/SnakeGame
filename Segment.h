#pragma once
#include "pair.h"
#include "consts.h"


typedef struct {
	pair pos;
	int num;
} Segment;

Segment CreateSegment(pair pos, int num) {
	Segment seg = { pos, num };
	return seg;
}

void ShowSegment(char game[game_height][game_width], Segment seg) {
	if (seg.num == 0) game[game_height - 1 - seg.pos.y][seg.pos.x] = head_pixel;
	else game[game_height - 1 - seg.pos.y][seg.pos.x] = seg_pixel;
}

void MoveSegment(Segment* seg, direction d) {
	if (d == right) seg->pos.x++;
	else if (d == left) seg->pos.x--;
	else if (d == up) seg->pos.y++;
	else if (d == down) seg->pos.y--;
}

bool isSegOutBorders(Segment seg) {
	return ((seg.pos.x < 0) || (seg.pos.x >= game_width) || (seg.pos.y < 0) || (seg.pos.y >= game_height));
}
