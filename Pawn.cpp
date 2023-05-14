#include <iostream>
#include <conio.h>
#include "Header.h"

using namespace std;

void check_poz_pawn(char filed[][12], int turn_of_the_more, int& poz_hor, int& poz_ver, char white, char black, char queen_white, char queen_black, int AIturn)//�������� ������� �����
{
	bool exit = false;
	if (turn_of_the_more % 2 == 0)//�������� ������������ ������ ������� ����� � ����������� �� ������� ����, � ��������� �� ��������� ���� �����
	{
		while (exit == false)
		{
			if (filed[poz_hor][poz_ver] == white)//���� ��� ����� �����
			{
				if (check_poz_pavn_white_or_black(filed, poz_ver, poz_hor, white, queen_white, black, queen_black, 1, 2))//������ ��� ����� ������� � �����
				{
					pawn_pos_inp_error(poz_ver, poz_hor, AIturn);
				}
				else
				{
					exit = true;
				}
			}
			else if (filed[poz_hor][poz_ver] == queen_white)
			{
				if (check_poz_queen_white_or_black(filed, poz_ver, poz_hor, white, queen_white, black, queen_black, 1, 2))//������ ��� ����� ������� � �����
				{
					pawn_pos_inp_error(poz_ver, poz_hor, AIturn);
				}
				else
				{
					exit = true;
				}
			}
			else
			{
				pawn_pos_inp_error(poz_ver, poz_hor, AIturn);
			}
		}
	}
	else
	{
		while (exit == false)
		{
			if (filed[poz_hor][poz_ver] == black)//���� ��� ������ �����
			{
				if (check_poz_pavn_white_or_black(filed, poz_ver, poz_hor, black, queen_black, white, queen_white, -1, -2))//������ ��� ����� ������� � ������
				{
					pawn_pos_inp_error(poz_ver, poz_hor, AIturn);
				}
				else
				{
					exit = true;
				}
			}
			else if (filed[poz_hor][poz_ver] == queen_black)//���� ��� ������ �����
			{
				if (check_poz_queen_white_or_black(filed, poz_ver, poz_hor, black, queen_black, white, queen_white, -1, -2))//������ ��� ����� ������� � ������
				{
					pawn_pos_inp_error(poz_ver, poz_hor, AIturn);
				}
				else
				{
					exit = true;
				}
			}
			else
			{
				pawn_pos_inp_error(poz_ver, poz_hor, AIturn);
			}
		}
	}
}

void check_the_ability_to_beat_again(char field[][12], int& new_poz_hor, int& new_poz_ver, int& poz_hor, int& poz_ver, int size, int turn_of_the_more, int& col_vo_white, int& col_vo_black, int AIturn, char evil_pawn, char evil_queen)//����� �� ����� ���� ��� ���
{
	poz_ver = new_poz_ver;
	poz_hor = new_poz_hor;
	while (turn_of_the_more % 2 == 0 ? pawn_black_and_white_beating(field, poz_ver, poz_hor, 'B', 'D') : pawn_black_and_white_beating(field, poz_ver, poz_hor, 'A', 'C'))//���� �������� ����� �� ����� ������ ��� ���, ������������� ���� ����������� ���
	{
		system("cls");
		filed_out_durig_the_game(field, size);

		if (AIturn == 1)
		{
			if ((field[new_poz_hor - 1][new_poz_ver - 1] == 'A' || field[new_poz_hor - 1][new_poz_ver - 1] == 'C') && field[new_poz_hor - 2][new_poz_ver - 2] == ' ')
			{
				new_poz_ver = new_poz_ver - 1;
				new_poz_hor = new_poz_hor - 1;
			}
			else if ((field[new_poz_hor + 1][new_poz_ver - 1] == 'A' || field[new_poz_hor + 1][new_poz_ver - 1] == 'C') && field[new_poz_hor + 2][new_poz_ver - 2] == ' ')
			{
				new_poz_ver = new_poz_ver - 1;
				new_poz_hor = new_poz_hor + 1;
			}
			else if ((field[new_poz_hor + 1][new_poz_ver + 1] == 'A' || field[new_poz_hor + 1][new_poz_ver + 1] == 'C') && field[new_poz_hor + 2][new_poz_ver + 2] == ' ')
			{
				new_poz_ver = new_poz_ver + 1;
				new_poz_hor = new_poz_hor + 1;
			}
			else if ((field[new_poz_hor - 1][new_poz_ver + 1] == 'A' || field[new_poz_hor - 1][new_poz_ver + 1] == 'C') && field[new_poz_hor - 2][new_poz_ver + 2] == ' ')
			{
				new_poz_ver = new_poz_ver + 1;
				new_poz_hor = new_poz_hor - 1;
			}
		}
		else
		{
			spaceFIELD();
			cout << "� ����� ���� ����������� ������, �����\n";
			cin >> new_poz_ver >> new_poz_hor;
			new_poz_ver++;
			new_poz_hor++;
		}
		while (turn_of_the_more % 2 == 0 ? pawn_black_and_white_beating(field, poz_ver, poz_hor, 'B', 'D') : pawn_black_and_white_beating(field, poz_ver, poz_hor, 'A', 'C'))
		{
			if (new_poz_ver - poz_ver == 1 && new_poz_hor - poz_hor == 1)//���� ��������� ����� ���� �� ����������� � ���������
			{
				if ((field[new_poz_hor][new_poz_ver] == evil_pawn || field[new_poz_hor][new_poz_ver] == evil_queen) && field[new_poz_hor + 1][new_poz_ver + 1] == ' ' && new_poz_hor + 1 <= 9 && new_poz_hor + 1 <= 9)//�������� ���� �� �� ������ ������ �����
				{
					process_of_eating_pawn(field, poz_hor, poz_ver, new_poz_hor, new_poz_ver, turn_of_the_more, col_vo_black, col_vo_white, 1, 1);
					break;
				}
				else
				{
					pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
				}
			}
			else if (new_poz_ver - poz_ver == -1 && new_poz_hor - poz_hor == 1)//���� ��������� ����� ���� �� ���������, �� ���� �� �����������
			{
				if ((field[new_poz_hor][new_poz_ver] == evil_pawn || field[new_poz_hor][new_poz_ver] == evil_queen) && field[new_poz_hor + 1][new_poz_ver - 1] == ' ' && new_poz_ver + 1 <= 9 && new_poz_hor - 1 >= 2)//�������� ���� �� �� ������ ������ �����
				{
					process_of_eating_pawn(field, poz_hor, poz_ver, new_poz_hor, new_poz_ver, turn_of_the_more, col_vo_black, col_vo_white, 1, -1);
					break;
				}
				else
				{
					pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
				}
			}
			else if (new_poz_ver - poz_ver == 1 && new_poz_hor - poz_hor == -1)//���� ��������� ����� ���� �� ���������, �� ���� �� �����������
			{
				if ((field[new_poz_hor][new_poz_ver] == evil_pawn || field[new_poz_hor][new_poz_ver] == evil_queen) && field[new_poz_hor - 1][new_poz_ver + 1] == ' ' && new_poz_hor - 1 >= 2 && new_poz_ver + 1 <= 9)//�������� ���� �� �� ������ ������ �����
				{
					process_of_eating_pawn(field, poz_hor, poz_ver, new_poz_hor, new_poz_ver, turn_of_the_more, col_vo_black, col_vo_white, -1, 1);
					break;
				}
				else
				{
					pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
				}
			}
			else if (new_poz_ver - poz_ver == -1 && new_poz_hor - poz_hor == -1)//���� ��������� ����� ���� �� ����������� � ���������
			{
				if ((field[new_poz_hor][new_poz_ver] == evil_pawn || field[new_poz_hor][new_poz_ver] == evil_queen) && field[new_poz_hor - 1][new_poz_ver - 1] == ' ' && new_poz_ver - 1 >= 2 && new_poz_ver - 1 >= 2)//�������� ���� �� �� ������ ������ �����
				{
					process_of_eating_pawn(field, poz_hor, poz_ver, new_poz_hor, new_poz_ver, turn_of_the_more, col_vo_black, col_vo_white, -1, -1);
					break;
				}
				else
				{
					pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
				}
			}
			else
			{
				pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
			}
		}
	}
}

void process_of_eating_pawn(char field[][12], int& hor, int& ver, int& new_hor, int& new_ver, int turn_of_the_more, int& col_vo_black, int& col_vo_white, int i, int j)//������� ����� �����
{
	field[new_hor + i][new_ver + j] = field[hor][ver];
	field[new_hor][new_ver] = ' ';
	field[hor][ver] = ' ';
	who_needs_to_take_away_figure(turn_of_the_more, col_vo_black, col_vo_white);
	new_hor += i;
	new_ver += j;
	ver = new_ver;
	hor = new_hor;
}

void check_a_new_position(bool& exit_the_str_cucle, int& new_poz_ver, int& new_poz_hor, int& poz_ver, int& poz_hor, char field[][12], char black, char queen_black, char white, char queen_white, int AIturn)//�������� ����� �������
{
	while (exit_the_str_cucle == false)
	{
		if (Check_the_req_cel(new_poz_ver, new_poz_hor) || (new_poz_hor <= 9 && new_poz_hor >= 2 && new_poz_ver <= 9 && new_poz_ver >= 2))
		{
			if (field[poz_hor][poz_ver] == black || field[poz_hor][poz_ver] == queen_black)//�������� ������������ ������ ����� ������� ����� � ����������� �� ������� ����, � ��������� �� ��������� ���� �����
			{
				if (field[poz_hor][poz_ver] == black)//���� ��� ������ �����
				{
					if (new_poz_ver > poz_ver)
					{
						if (new_poz_hor < poz_hor)
						{
							if (new_poz_hor - poz_hor == -1 && new_poz_ver - poz_ver == 1)//������ ��� ����� ������� � ������
							{
								exit_the_str_cucle = true;
							}
							else
							{
								pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
							}
						}
						else
						{
							if (field[new_poz_hor][new_poz_ver] == white || field[new_poz_hor][new_poz_ver] == queen_white)
							{
								if (new_poz_ver - poz_ver == 1 && new_poz_hor - poz_hor == 1)//������ ��� ����� ������� � ������
								{
									exit_the_str_cucle = true;
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
							else
							{
								pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
							}
						}
					}
					else
					{
						if (new_poz_hor < poz_hor)
						{
							if (new_poz_hor - poz_hor == -1 && new_poz_ver - poz_ver == -1)//������ ��� ����� ������� � ������
							{
								exit_the_str_cucle = true;
							}
							else
							{
								pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
							}
						}
						else
						{
							if (field[new_poz_hor][new_poz_ver] == white || field[new_poz_hor][new_poz_ver] == queen_white)
							{
								if (new_poz_ver - poz_ver == -1 && new_poz_hor - poz_hor == +1)//������ ��� ����� ������� � ������
								{
									exit_the_str_cucle = true;
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
							else
							{
								pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
							}
						}
					}
				}
				else if (field[poz_hor][poz_ver] == queen_black)//���� ��� ������ �����
				{
					the_queens_move( new_poz_ver, new_poz_hor, poz_ver, poz_hor, exit_the_str_cucle, field, AIturn);
				}
			}
			else if (field[poz_hor][poz_ver] == white || field[poz_hor][poz_ver] == queen_white)
			{
				if (field[poz_hor][poz_ver] == white)//���� ��� ����� �����
				{
					if (new_poz_ver > poz_ver)
					{
						if (new_poz_hor > poz_hor)
						{
							if (new_poz_hor - poz_hor == 1 && new_poz_ver - poz_ver == 1)//������ ��� ����� ������� � �����
							{
								exit_the_str_cucle = true;
							}
							else
							{
								pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
							}
						}
						else
						{
							if (field[new_poz_hor][new_poz_ver] == black || field[new_poz_hor][new_poz_ver] == queen_black)
							{
								if (new_poz_hor - poz_hor == -1 && new_poz_ver - poz_ver == 1)//������ ��� ����� ������� � �����
								{
									exit_the_str_cucle = true;
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
							else
							{
								pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
							}
						}
					}
					else
					{
						if (new_poz_hor > poz_hor)
						{
							if (new_poz_hor - poz_hor == 1 && new_poz_ver - poz_ver == -1)//������ ��� ����� ������� � �����
							{
								exit_the_str_cucle = true;
							}
							else
							{
								pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
							}
						}
						else
						{
							if (field[new_poz_hor][new_poz_ver] == black || field[new_poz_hor][new_poz_ver] == queen_black)
							{
								if (new_poz_hor - poz_hor == -1 && new_poz_ver - poz_ver == -1)//������ ��� ����� ������� � �����
								{
									exit_the_str_cucle = true;
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
							else
							{
								pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
							}
						}
					}
				}
				else if (field[poz_hor][poz_ver] == queen_white)//���� ��� ����� �����
				{
					the_queens_move( new_poz_ver, new_poz_hor, poz_ver, poz_hor, exit_the_str_cucle, field, AIturn);
				}
			}
		}
		else
		{
			pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
		}
	}
	exit_the_str_cucle = false;
}