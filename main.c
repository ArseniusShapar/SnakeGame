#include "Play.h"
#include "DrawGame.h"


int main() {
	char screen[window_height + 1][window_width];
	char game[game_height + 1][game_width];
	bool GameOver;
	Apple apple;
	Segment head;
	Snake snake;

	ClearGameAndScreen(screen, game);
	SpawnApple(game, &apple);
	GameOver = false;

	head = CreateSegment(CreatePair(game_width / 2, game_height / 2), 0);
	snake = CreateSnake(head, right);

	while (!GameOver) {
		DrawGame(screen, game, &snake, apple);

		Sleep(freq * 1000);

		snake.direct = Input(snake.direct);
		
		Move(&snake);

		GameOver = isGameOver(&snake);

		if (isAppleEaten(&snake, apple)) {
			AddTail(&snake);
			SpawnApple(game, &apple);
		}

		ClearGameAndScreen(screen, game);
	}
}
