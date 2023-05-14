#include <iostream>
#include <conio.h>
#include "Header.h"

using namespace std;

void can_a_queen_beat(int i, int j, int size, char field[][12], char awn_pawn, char own_queen, char enemy_pawn, char enemy_queen, int pawn_beat_hor[], int pawn_beat_ver[], int& col_vo_voz_beat)//ћожет королева бить?
{
	int ost_v_v = 1, ost_v_n = 1, ost_n_v = 1, ost_n_n = 1;
	for (int k = 1; k < size; k++)
	{
		if (ost_v_v == 1)
		{
			if (((field[i + k][j + k] == enemy_pawn || field[i + k][j + k] == enemy_queen) && field[i + (k + 1)][j + (k + 1)] == ' ') && i + k + 1 <= 9 && j + k + 1 <= 9)
			{
				spaceFIELD();
				cout << "Ѕела€ дамка на позиции " << j - 1 << " ; " << i - 1 << " может бить\n";
				pawn_beat_hor[col_vo_voz_beat] = i;
				pawn_beat_ver[col_vo_voz_beat] = j;
				col_vo_voz_beat++;
			}
			else if (field[i + k][j + k] != ' ' && field[i + k + 1][j + k + 1] != ' ' || field[i + k][j + k] == awn_pawn || field[i + k][j + k] == own_queen)
			{
				ost_v_v = 2;
			}
		}
		if (ost_v_n == 1)
		{
			if (((field[i + k][j - k] == enemy_pawn || field[i + k][j - k] == enemy_queen) && field[i + (k + 1)][j - (k + 1)] == ' ') && i + k + 1 <= 9 && j - k - 1 >= 2)
			{
				spaceFIELD();
				cout << "Ѕела€ дамка на позиции " << j - 1 << " ; " << i - 1 << " может бить\n";
				pawn_beat_hor[col_vo_voz_beat] = i;
				pawn_beat_ver[col_vo_voz_beat] = j;
				col_vo_voz_beat++;
			}
			else if (field[i + k][j - k] != ' ' && field[i + (k + 1)][j - (k + 1)] != ' ' || field[i + k][j - k] == awn_pawn || field[i + k][j - k] == own_queen)
			{
				ost_v_n = 2;
			}
		}
		if (ost_n_v == 1)
		{
			if (((field[i - k][j + k] == enemy_pawn || field[i - k][j + k] == enemy_queen) && field[i - (k + 1)][j + (k + 1)] == ' ') && i - k - 1 >= 2 && j + k + 1 <= 9)
			{
				spaceFIELD();
				cout << "Ѕела€ дамка на позиции " << j - 1 << " ; " << i - 1 << " может бить\n";
				pawn_beat_hor[col_vo_voz_beat] = i;
				pawn_beat_ver[col_vo_voz_beat] = j;
				col_vo_voz_beat++;
			}
			else if (field[i - k][j + k] != ' ' && field[i - (k + 1)][j + (k + 1)] != ' ' || field[i - k][j + k] == awn_pawn || field[i - k][j + k] == own_queen)
			{
				ost_n_v = 2;
			}
		}
		if (ost_n_n == 1)
		{
			if (((field[i - k][j - k] == enemy_pawn || field[i - k][j - k] == enemy_queen) && field[i - (k + 1)][j - (k + 1)] == ' ') && i - k - 1 >= 2 && j - k - 1 >= 2)
			{
				spaceFIELD();
				cout << "Ѕела€ дамка на позиции " << j - 1 << " ; " << i - 1 << " может бить\n";
				pawn_beat_hor[col_vo_voz_beat] = i;
				pawn_beat_ver[col_vo_voz_beat] = j;
				col_vo_voz_beat++;
			}
			else if (field[i - k][j - k] != ' ' && field[i - (k + 1)][j - (k + 1)] != ' ' || field[i - k][j - k] == awn_pawn || field[i - k][j - k] == own_queen)
			{
				ost_n_n = 2;
			}
		}
	}
}

void the_queens_move(int& new_poz_ver, int& new_poz_hor, int& poz_ver, int& poz_hor, bool& exit_the_str_cucle, char field[][12], int AIturn)//ход королевы
{
	for (int i = 0; i < 8; i++)//цикл дл€ проверки не пошла ли королева на недоступные пол€, а дл€ того чтоб это проверить надо от вертикали и горизонтали отн€ть одно и тоже число, чтоб получилась позици€ королевы
	{
		if (new_poz_ver - i == poz_ver && new_poz_hor - i == poz_hor)//если нова€ позици€ королевы выше изначальной по горизонтали и вертикали
		{
			for (int j = 1; j <= i; j++)
			{
				if (field[poz_hor + j][poz_ver + j] != ' ' && j != i)
				{
					pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
					break;
				}
				else if (j == i)
				{
					exit_the_str_cucle = true;
					i = 10;
					break;
				}
			}
			if (i == 10)
			{
				break;
			}
		}
		else if (new_poz_ver + i == poz_ver && new_poz_hor + i == poz_hor)//если нова€ позици€ королевы ниже по вертикали и горизонтали
		{
			for (int j = 1; j <= i; j++)
			{
				if (field[poz_hor - j][poz_ver - j] != ' ' && j != i)
				{
					pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
					break;
				}
				else if (j == i)
				{
					exit_the_str_cucle = true;
					i = 10;
					break;
				}
			}
			if (i == 10)
			{
				break;
			}
		}
		else if (new_poz_ver + i == poz_ver && new_poz_hor - i == poz_hor)//если нова€ позици€ королевы по вертикали ниже, а по горизонтали выше
		{
			for (int j = 1; j <= i; j++)
			{
				if (field[poz_hor + j][poz_ver - j] != ' ' && j != i)
				{
					pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
					break;
				}
				else if (j == i)
				{
					exit_the_str_cucle = true;
					i = 10;
					break;
				}
			}
			if (i == 10)
			{
				break;
			}
		}
		else if (new_poz_ver - i == poz_ver && new_poz_hor + i == poz_hor)//если нова€ позици€ королевы по вертикали выше, а по горизонтали ниже
		{
			for (int j = 1; j <= i; j++)
			{
				if (field[poz_hor - j][poz_ver + j] != ' ' && j != i)
				{
					pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
					break;
				}
				else if (j == i)
				{
					exit_the_str_cucle = true;
					i = 10;
					break;
				}
			}
			if (i == 10)
			{
				break;
			}
		}
		else if (i == 7)//ошибка в случае если вообще ниразу не совпало
		{
			pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
		}
	}
}

void queen_beat(char field[][12], int& new_poz_hor, int& new_poz_ver, int& poz_hor, int& poz_ver, int turn_of_the_more, int& col_vo_white, int& col_vo_blakc, bool& exit_the_str_cucle, int AIturn, int k, int j)//королева бьЄт
{
	int ver = new_poz_ver, hor = new_poz_hor;
	field[new_poz_hor][new_poz_ver] = ' ';
	if (AIturn == 1)
	{
		new_poz_ver = rand() % 7 + 2;
		new_poz_hor = rand() % 7 + 2;
	}
	else
	{
		spaceFIELD();
		cout << "¬ведите поле, на которое походит дамка\n";
		cin >> new_poz_ver >> new_poz_hor;
		new_poz_hor++;
		new_poz_ver++;
	}
	for(int i = 1; i <= 8; i++)
	{
		if (new_poz_ver - j * i == poz_ver && new_poz_hor - k * i == poz_hor && new_poz_hor > hor)
		{
			if (k > 0)
			{
				if (j > 0)
				{
					if (new_poz_hor > hor && new_poz_ver > ver)
					{
						break;
					}
				}
				else
				{
					if (new_poz_hor > hor && new_poz_ver < ver)
					{
						break;
					}
				}
			}
			else
			{
				if (j > 0)
				{
					if (new_poz_hor < hor && new_poz_ver > ver)
					{
						break;
					}
				}
				else
				{
					if (new_poz_hor < hor && new_poz_ver < ver)
					{
						break;
					}
				}
			}

		}
		else
		{
			if (i == 8)
			{
				pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
				i = 0;
			}
		}
	}
	check_a_new_position(exit_the_str_cucle, new_poz_ver, new_poz_hor, poz_ver, poz_hor, field, 'B', 'D', 'A', 'C', AIturn);
	field[new_poz_hor][new_poz_ver] = field[poz_hor][poz_ver];
	field[poz_hor][poz_ver] = ' ';
	who_needs_to_take_away_figure(turn_of_the_more, col_vo_blakc, col_vo_white);
	can_the_queen_beat_more(new_poz_ver, new_poz_hor, poz_ver, poz_hor, exit_the_str_cucle, field, col_vo_white, col_vo_blakc, turn_of_the_more, 8, AIturn);
	exit_the_str_cucle = true;
}

void can_the_queen_beat_more( int& new_poz_ver, int& new_poz_hor, int& poz_ver, int& poz_hor, bool& exit_the_str_cucle, char field[][12], int& col_vo_white, int& col_vo_black, int turn_of_the_more, int size, int AIturn)//может ли королева бить еще раз
{
	int verM_horM = 0, verM_horB = 0, verB_horM = 0, verB_horB = 0;
	for(int i = 1; i < 8; i++)
	{
		poz_ver = new_poz_ver;
		poz_hor = new_poz_hor;
		if (verM_horM == 0 && i != 0)
		{
			if (field[poz_hor - i][poz_ver - i] != ' ' && field[poz_hor - (i + 1)][poz_ver - (i + 1)] == ' ')
			{
				if (turn_of_the_more % 2 == 0)
				{
					the_queen_repeat_bets(field, new_poz_ver, new_poz_hor, poz_ver, poz_hor, 'A', 'C', 'B', 'D', AIturn, -1, -1);
				}
				else
				{
					the_queen_repeat_bets(field, new_poz_ver, new_poz_hor, poz_ver, poz_hor, 'B', 'D', 'A', 'C', AIturn, -1, -1);
				}
				who_needs_to_take_away_figure(turn_of_the_more, col_vo_black, col_vo_white);
				verM_horM = 0;
				verB_horM = 0;
				verB_horB = 0;
				verM_horB = 0;
				i = 0;
			}
			else if (field[poz_hor - i][poz_ver - i] != ' ' && field[poz_hor - (i + 1)][poz_ver - (i + 1)] != ' ')
			{
				verM_horM = 1;
			}
		}
		if (verM_horB == 0 && i != 0)
		{
			if (field[poz_hor + i][poz_ver - i] != ' ' && field[poz_hor + (i + 1)][poz_ver - (i + 1)] == ' ')
			{
				if (turn_of_the_more % 2 == 0)
				{
					the_queen_repeat_bets(field, new_poz_ver, new_poz_hor, poz_ver, poz_hor, 'A', 'C', 'B', 'D', AIturn, 1, -1);
				}
				else
				{
					the_queen_repeat_bets(field, new_poz_ver, new_poz_hor, poz_ver, poz_hor, 'B', 'D', 'A', 'C', AIturn, 1, -1);
				}
				who_needs_to_take_away_figure(turn_of_the_more, col_vo_black, col_vo_white);
				verM_horB = 0;
				verB_horM = 0;
				verM_horM = 0;
				verB_horB = 0;
				i = 0;
			}
			else if (field[poz_hor + i][poz_ver - i] != ' ' && field[poz_hor + (i + 1)][poz_ver - (i + 1)] != ' ')
			{
				verM_horB = 1;
			}
		}
		if (verB_horM == 0 && i != 0)
		{
			if (field[poz_hor - i][poz_ver + i] != ' ' && field[poz_hor - (i + 1)][poz_ver + (i + 1)] == ' ')
			{
				if (turn_of_the_more % 2 == 0)
				{
					the_queen_repeat_bets(field, new_poz_ver, new_poz_hor, poz_ver, poz_hor, 'A', 'C', 'B', 'D', AIturn, -1, 1);
				}
				else
				{
					the_queen_repeat_bets(field, new_poz_ver, new_poz_hor, poz_ver, poz_hor, 'B', 'D', 'A', 'C', AIturn, -1, 1);
				}
				who_needs_to_take_away_figure(turn_of_the_more, col_vo_black, col_vo_white);
				verB_horM = 0;
				verM_horM = 0;
				verB_horB = 0;
				verM_horB = 0;
				i = 0;
			}
			else if (field[poz_hor - i][poz_ver + i] != ' ' && field[poz_hor - (i + 1)][poz_ver + (i + 1)] != ' ')
			{
				verB_horM = 1;
			}
		}
		if (verB_horB == 0 && i != 0)
		{
			if (field[poz_hor + i][poz_ver + i] != ' ' && field[poz_hor + (i + 1)][poz_ver + (i + 1)] == ' ')
			{
				if (turn_of_the_more % 2 == 0)
				{
					the_queen_repeat_bets(field, new_poz_ver, new_poz_hor, poz_ver, poz_hor, 'A', 'C', 'B', 'D', AIturn, 1, 1);
				}
				else
				{
					the_queen_repeat_bets(field, new_poz_ver, new_poz_hor, poz_ver, poz_hor, 'B', 'D', 'A', 'C', AIturn, 1, 1);
				}
				who_needs_to_take_away_figure(turn_of_the_more, col_vo_black, col_vo_white);
				verB_horB = 0;
				verB_horM = 0;
				verM_horM = 0;
				verM_horB = 0;
				i = 0;
			}
			else if (field[poz_hor + i][poz_ver + i] != ' ' && field[poz_hor + (i + 1)][poz_ver + (i + 1)] != ' ')
			{
				verB_horB = 1;
			}
		}
	}
}

void the_queen_repeat_bets(char field[][12], int& new_poz_ver, int& new_poz_hor, int& poz_ver, int& poz_hor, char own_pawn, char own_queen, char alien_pawn, char alien_queen, int AIturn, int k, int j)//королева бьет еще раз
{
	bool exit_the_str_cucle = false;
	system("cls");
	filed_out_durig_the_game(field, 12);
	if (AIturn == 1)
	{
		new_poz_ver = rand() % 7 + 2;
		new_poz_hor = rand() % 7 + 2;
	}
	else
	{
		spaceFIELD();
		cout << "” дамки есть возможность побить, бейте\n";
		cin >> new_poz_ver >> new_poz_hor;
		new_poz_hor++;
		new_poz_ver++;
	}
	while (field[new_poz_hor][new_poz_ver] != alien_pawn && field[new_poz_hor][new_poz_ver] != alien_queen)//проверка новой позиции
	{
		pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
	}
	check_a_new_position(exit_the_str_cucle, new_poz_ver, new_poz_hor, poz_ver, poz_hor, field, 'B', 'D', 'A', 'C', AIturn);
	field[new_poz_hor][new_poz_ver] = ' ';
	if (AIturn == 1)
	{
		new_poz_ver = rand() % 7 + 2;
		new_poz_hor = rand() % 7 + 2;
	}
	else
	{
		spaceFIELD();
		cout << "¬ведите поле, на которое походит дамка\n";
		cin >> new_poz_ver >> new_poz_hor;
		new_poz_hor++;
		new_poz_ver++;
	}
	for(int i = 1; i < 8; i++)
	{
		if (new_poz_ver - j * i == poz_ver && new_poz_hor - k * i == poz_ver)
		{
			break;
		}
		else
		{
			if (i < 8)
			{
				i++;
			}
			else
			{
				pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
				i = 1;
			}
		}
	}
	check_a_new_position(exit_the_str_cucle, new_poz_ver, new_poz_hor, poz_ver, poz_hor, field, 'B', 'D', 'A', 'C', AIturn);
	field[new_poz_hor][new_poz_ver] = field[poz_hor][poz_ver];
	field[poz_hor][poz_ver] = ' ';
	poz_hor = new_poz_hor;
	poz_ver = new_poz_ver;
}