#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define window_width 90
#define window_height 35
#define game_width 75
#define game_height 33
#define FPS 8
const float freq = 1.0f / (float)FPS;
const char head_pixel = '@';
const char seg_pixel = 'o';
const char apple_pixel = '*';
const char vertical_border_pixel = '#';
const char horizontal_border_pixel = '#';
typedef enum { right, left, up, down } direction;


direction reverse(direction direct) {
	if (direct == right) return left;
	else if (direct == left) return right;
	else if (direct == up) return down;
	else if (direct == down) return up;
}
