#ifndef SNAKE_H
#define SNAKE_H

#include <fstream>
#include <iostream>

class Snake
{
private:
	bool game_end;
	int x, y, fruitX, fruitY, score;
	const int width, height;
	int tail_n, tailX[100], tailY[100];
	std::string surname;
	enum Mode { STOP = 0, LEFT, RIGHT, UP, DOWN };
	Mode direction;

	std::ifstream wczyt;
	std::ofstream zapis;
	//static char *file_name;

public:
	Snake(int _h, int _w);
	Snake();
	~Snake();
	void draw();
	void input();
	void logic();
	bool game_terminet();
	void show_result();
	void save_result();
	void fill_name();
	void game_untermineted();
	void info() const;
	void clear_game();
};


#endif // SNAKE_H
