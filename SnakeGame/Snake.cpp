#include "Snake.h"
#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <fstream>
#include <string>
const char *file_name = "Big_Data.txt";

using namespace std;
Snake::Snake(int _h = 20, int _w = 30) : height(_h), width(_w)
{
	srand(time(NULL));
	direction = STOP;
	game_end = false;
	score = 0;
	tail_n = 0;

	x = width / 2;
	y = height / 2;

	fruitX = rand() % width;
	fruitY = rand() % height;


}
//....................................................................
Snake::Snake() : height(20), width(30)
{
	srand(time(NULL));
	direction = STOP;
	game_end = false;
	score = 0;
	tail_n = 0;

	x = width / 2;
	y = height / 2;

	fruitX = rand() % width;
	fruitY = rand() % height;
}
//....................................................................
void Snake::fill_name()
{
	std::cout << "Podaj mi swoje imie: " << endl;
	cin >> surname;
}
//....................................................................
void Snake::draw()
{
	system("cls");
	for (int j = 0; j < width + 2; j++)
		cout << "\xDB";
	cout << endl;
	for (int i = 0; i < height; i++)
	{

		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "\xB2";
			if (x == j && y == i)
				cout << 'X';
			else if (fruitX == j && fruitY == i)
				cout << 'F';
			else
			{
				bool print = false;
				for (int k = 0; k < tail_n; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << 'O';
						print = true;
					}

				}
				if (!print)
					cout << ' ';
			}
			if (j == width - 1)
				cout << "\xB2";
		}
		cout << endl;

	}
	for (int j = 0; j < width + 2; j++)
		cout << "\xDB";
	cout << endl;
	cout << "Wynik:" << score << endl;
	Sleep(10);

}
//....................................................................
void Snake::input()
{
	if (_kbhit())
	{	
		switch (_getch())
		{
		case 'w': direction = UP; break;
		case 's': direction = DOWN; break;
		case 'a': direction = LEFT; break;
		case 'd': direction = RIGHT; break;

		}
	}
}
//....................................................................
void Snake::logic()
{
	int prevX = tailX[0], prev_prevX;
	int prevY = tailY[0], prev_prevY;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < tail_n; i++)  /**< dwa przypadki gdy dodano element i nie dodano nowe wspolrzedne do istniejacych */
	{
		prev_prevX = tailX[i];
		prev_prevY = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev_prevX;
		prevY = prev_prevY;
	}
	switch (direction)
	{
	case UP: y = y - 1; break;
	case DOWN: y = y + 1; break;
	case LEFT: x = x - 1; break;
	case RIGHT: x = x + 1; break;
	case STOP: break;
	}
	if (x <= -1)
		x = width;
	else if (x >= width)
		x = 0;
	else if (y >= height)
		y = 0;
	else if (y <= -1)
		y = height;

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		tail_n++;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
	for (int i = 0; i < tail_n; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			game_end = true;
			break;
		}
	}
}
//....................................................................
bool Snake::game_terminet()
{
	if (game_end == true)
		return true;
	else
		return false;
}
//....................................................................
void Snake::show_result()
{
	string name;
	int result;
	int counter = 1;
	wczyt.open(file_name);
	if (!wczyt.is_open())
	{
		cerr << "Nie udalo sie odczytac danych!" << endl;
	}
	while (!wczyt.eof())
	{
		wczyt >> name >> result;
		cout << "NR:" << counter << " Imie: " << name
			<< " Wynik: " << result << endl;
		counter++;
	}
	wczyt.close();
	cout << endl;

}
//....................................................................
void Snake::save_result()
{
	zapis.open(file_name, ios_base::out | ios_base::app);
	zapis << endl << surname << " " << score;

	zapis.close();
	cout << "Zapisano" << endl;
}
//....................................................................
void Snake::game_untermineted()
{
	game_end = false;
}
//....................................................................
void Snake::info() const
{
	cout << "\t Gra Waz (Snake) v1.3 , objektowo " << endl;
	cout << "\t Autor: Dominik Atrasik" << endl;
	cout << "\t Ostatnie poprawki 15/12/2016" << endl << endl;
	cout << "\t Gra jest gotowa w 90%, troche sie krzaczy i zaduzo kodu jest w main'ie\n"
		<< "\t ale najwazniesze bledy poprawilem\n"
		<< "\t Ostatnia poprawka to zmiana wygladu scian \n"
		<< "\t Gra w calosc stworzona w C++, Code::Blocks 16.01" << endl << endl;
}
//....................................................................
void Snake::clear_game()
{
	x = width / 2;
	y = height / 2;
	score = 0;
	fruitX = rand() % width;
	fruitY = rand() % height;
	tail_n = 0;
	direction = STOP;

}
Snake::~Snake()
{
	;
}