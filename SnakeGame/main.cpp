#include <iostream>
#include "Snake.h"
#include <windows.h>


using namespace std;
bool game_builde(Snake & pointer)
{
	while (!pointer.game_terminet())
	{
		pointer.draw();
		pointer.input();
		pointer.logic();
	}
	cout << "do you want o save your result: Y yes N no" << endl;

	return 0;
}
void game_managment(Snake & new_game)
{
	char ch;
	int choose2;
	new_game.fill_name();
	while (!new_game.game_terminet())
	{
		new_game.draw();
		new_game.input();
		new_game.logic();
	}

	new_game.game_untermineted();

	cout << "Czy chcesz zapisac swoj wynik ? 1:TAK, 2:NIE" << endl;

	while (!(cin >> choose2))
	{
		cin.clear();
		while (cin.get(ch) && ch != '\n')
			continue;
		cout << "Podaj Ponownie " << endl;
	}

	if (choose2 == 1)
	{
		new_game.save_result();
		system("cls");
	}
	else
		system("cls");

	new_game.clear_game();
}
int main()
{
	cout << "\t Gra Waz (Snake) v1.3 , objektowo " << endl;
	cout << "\t Autor: Dominik Atrasik" << endl;
	cout << "\t Ostatnie poprawki 15/12/2016" << endl << endl;
	Sleep(2000);


	int choose;
	Snake new_game;
	char ch;
	//game_builde(new_game);
	do {

		cout << "\t1: Nowa Gra " << endl;
		cout << "\t2: Pokarz Wyniki " << endl;
		cout << "\t3: Info " << endl;
		cout << "\t4: Koniec" << endl << endl;

		while (!(cin >> choose))
		{
			cin.clear();
			while (cin.get(ch) && ch != '\n')
				continue;
			cout << "Podaj Ponownie " << endl;
		}

		system("cls");

		switch (choose)
		{
		case 1: game_managment(new_game); break;
		case 2: new_game.show_result(); break;
		case 3: new_game.info(); break;
		case 4: system("cls"); cout << "\t\tKONIEC" << endl; break;
		default: break;
		}

	} while (choose != 4);

	return 0;
}
