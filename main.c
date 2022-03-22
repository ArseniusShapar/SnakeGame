#include "Play.h"
#include "DrawGame.h"


int main() {
	// Оглашение всех переменных
	char screen[window_height + 1][window_width];
	char game[game_height + 1][game_width];
	bool GameOver;
	Apple apple;
	Segment head;
	Snake snake;

	// Подготовка масивов для рисования
	ClearGameAndScreen(screen, game);

	// Спавн первого яблока
	SpawnApple(game, &apple);

	// Переменная, отвечающая за окончание игры
	GameOver = false;

	// Создание головы змеи и самой змеи
	head = CreateSegment(CreatePair(game_width / 2, game_height / 2), 0);
	snake = CreateSnake(head, right);

	while (!GameOver) {

		// Рисуем поле игры, змею, яблоко
		DrawGame(screen, game, &snake, apple);

		// Делаем задержку
		Sleep(freq * 1000);

		// Пользователь выбирает направление движения
		snake.direct = Input(snake.direct);

		// Змея двигается
		Move(&snake);

		// Проверка на то, не закончилась ли игра
		GameOver = isGameOver(&snake);

		// Если змея съела яблоко
		if (isAppleEaten(&snake, apple)) {
			AddTail(&snake);
			SpawnApple(game, &apple);
		}

		// Очищаем экран
		ClearGameAndScreen(screen, game);
	}
}


