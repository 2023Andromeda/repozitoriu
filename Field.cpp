#include <iostream>
#include <conio.h>
#include "Header.h"

using namespace std;

void creat_a_field(int size, char white, char black, char queen_white, char queen_black, char field[][12], int Konami)//Формирование поля и расстановка пешек
{
	spaceFIELD();
	cout << "A - белая пешка\n";
	spaceFIELD();
	cout << "B - чёрная пешка\n";
	spaceFIELD();
	cout << "C - белая дамка\n";
	spaceFIELD();
	cout << "D - чёрная дамка\n\n";
	spaceFIELD();
	cout << "      1       2       3       4       5       6       7       8\n";
	spaceFIELD();
	cout << "  +-------+-------+-------+-------+-------+-------+-------+-------+";
	for (int i = 2; i < size - 2; i++)
	{
		cout << "\n";
		spaceFIELD();
		cout << "  |       |       |       |       |       |       |       |       |\n";
		spaceFIELD();
		cout << i - 1 << " |   ";
		for (int j = 2; j < size - 2; j++)
		{
			if (i % 2 != 0)//Правила расстановки при чётном или не чётном поле по горизонтали
			{
				if (i < 5)//Расстановка белых пешек
				{
					if (j % 2 == 0)//Правила расстановки при чётном или не чётном поле по вертикали
					{
						if (Konami == 1)
							field[i][j] = queen_white;
						else
							field[i][j] = white;
					}
					else
					{
						field[i][j] = ' ';
					}
				}
				else if (i >= 5 && i <= 6)//Пустые клетки
				{
					field[i][j] = ' ';
				}
				else//Расстановка чёрных пешек
				{
					if (j % 2 == 0)//Правила расстановки при чётном или не чётном поле по вертикали
					{
						if (Konami == 1)
							field[i][j] = queen_black;
						else
							field[i][j] = black;
					}
					else
					{
						field[i][j] = ' ';
					}
				}
				if (i < 5)//Расстановка белых пешек
				{
					if (j % 2 != 0)//Правила расстановки при чётном или не чётном поле по вертикали
					{
						if (Konami == 1)
							field[i][j] = queen_white;
						else
							field[i][j] = white;
					}
					else
					{
						field[i][j] = ' ';
					}
				}
				else if (i >= 5 && i <= 6)//Пустые клетки
				{
					field[i][j] = ' ';
				}
				else//Расстановка чёрных пешек
				{
					if (j % 2 != 0)//Правила расстановки при чётном или не чётном поле по вертикали
					{
						if (Konami == 1)
							field[i][j] = queen_black;
						else
							field[i][j] = black;
					}
					else
					{
						field[i][j] = ' ';
					}
				}
			}
			else
			{
				if (i < 5)//Расстановка белых пешек
				{
					if (j % 2 != 0)//Правила расстановки при чётном или не чётном поле по вертикали
					{
						if (Konami == 1)
							field[i][j] = queen_white;
						else
							field[i][j] = white;
					}
					else
					{
						field[i][j] = ' ';
					}
				}
				else if (i >= 5 && i <= 6)//Пустые клетки
				{
					field[i][j] = ' ';
				}
				else//Расстановка чёрных пешек
				{
					if (j % 2 != 0)//Правила расстановки при чётном или не чётном поле по вертикали
					{
						if (Konami == 1)
							field[i][j] = queen_black;
						else
							field[i][j] = black;
					}
					else
					{
						field[i][j] = ' ';
					}
				}
				if (i < 5)//Расстановка белых пешек
				{
					if (j % 2 == 0)//Правила расстановки при чётном или не чётном поле по вертикали
					{
						if (Konami == 1)
							field[i][j] = queen_white;
						else
							field[i][j] = white;
					}
					else
					{
						field[i][j] = ' ';
					}
				}
				else if (i >= 5 && i <= 6)//Пустые клетки
				{
					field[i][j] = ' ';
				}
				else//Расстановка чёрных пешек
				{
					if (j % 2 == 0)//Правила расстановки при чётном или не чётном поле по вертикали
					{
						if (Konami == 1)
							field[i][j] = queen_black;
						else
							field[i][j] = black;
					}
					else
					{
						field[i][j] = ' ';
					}
				}
			}
			cout << field[i][j] << "   |   ";
		}
		cout << "\n";
		spaceFIELD();
		cout << "  |       |       |       |       |       |       |       |       |\n";
		spaceFIELD();
		cout << "  +-------+-------+-------+-------+-------+-------+-------+-------+";
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i < 2 || i > 9)
			{
				field[i][j] = '0';
			}
			else
			{
				if (j < 2 || j > 9)
				{
					field[i][j] = '0';
				}
			}
		}
	}
	cout << "\n";
	spaceFIELD();
	cout << "Осталось 12 белых фигур и 12 чёрных фигур";

}

void filed_out_durig_the_game(char field[][12], int size)//Вывод поля после хода игрока
{
	spaceFIELD();
	cout << "A - белая пешка\n";
	spaceFIELD();
	cout << "B - чёрная пешка\n";
	spaceFIELD();
	cout << "C - белая дамка\n";
	spaceFIELD();
	cout << "D - чёрная дамка\n\n";
	spaceFIELD();
	cout << "      1       2       3       4       5       6       7       8\n";
	spaceFIELD();
	cout << "  +-------+-------+-------+-------+-------+-------+-------+-------+";
	for (int i = 2; i < size - 2; i++)
	{
		cout << "\n";
		spaceFIELD();
		cout << "  |       |       |       |       |       |       |       |       |\n";
		spaceFIELD();
		cout << i - 1 << " |   ";
		for (int j = 2; j < size - 2; j++)
		{
			cout << field[i][j] << "   |   ";
		}
		cout << "\n";
		spaceFIELD();
		cout << "  |       |       |       |       |       |       |       |       |\n";
		spaceFIELD();
		cout << "  +-------+-------+-------+-------+-------+-------+-------+-------+";
	}
}

void spaceFIELD()
{
	cout.width(90);
	cout << "";
}