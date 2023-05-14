#include <iostream>
#include <conio.h>
#include "Header.h"

using namespace std;

void all_game(char field[][12], char white, char black, int size, int queen_white, int queen_black, int color)//������� ����
{
	int new_poz_hor = 0, new_poz_ver = 0, poz_hor = 0, poz_ver = 0, col_vo_white = 12, col_vo_blakc = 12, turn_of_the_more = 0, AIexort = 0, AIturn = 0;
	bool exit_the_str_cucle = false;
	int pawn_beat_hor[12], pawn_beat_ver[12], col_vo_voz_beat = 0, draw = 0;

	//new_poz_hor - ����� ������� ����� �� �����������
	//new_poz_ver - ����� ������� ����� �� ���������
	//poz_hor - ��������� ������� ����� �� �����������
	//poz_ver - ��������� ������� ����� �� ���������
	//col_vo_white - ���������� ����� �����
	//col_vo_blakc - ���������� ������ �����
	//furn_of_the_more - ������� ����
	//exit_the_str_cucle - ����� �� ������ ��������
	//pawn_beat_hor - ������� ����� �� �����������, ������� ����� ����
	//pawn_beat_ver - ������� ����� �� ���������, ������� ����� ����
	//col_vo_voz_beat - ���������� �����, ������� ����� ���� 
	//AIexort - ��� �������
	//AIturn - ��� ����
	//draw - �����, ���� ���������� �����, ������� �� ����� �������� ����� ���������� ����� �� ����
	do
	{
		if (turn_of_the_more % 2 == 0)//��������� ������� ����
		{
			cout << "\n";
			spaceFIELD();
			cout << "������ �����";
			if (color == 1)
			{
				AIturn = 0;
			}
			else if (color == 2)
			{
				AIturn = 1;
			}
		}
		else
		{
			cout << "\n";
			spaceFIELD();
			cout << "����� ������";
			if (color == 1)
			{
				AIturn = 1;
			}
			else if (color == 2)
			{
				AIturn = 0;
			}
		}

		for (int i = 0; i < size; i++)//�������� ���� �� ����� ��������� ����
		{
			for (int j = 0; j < size; j++)
			{
				if (turn_of_the_more % 2 == 0)
				{
					if (field[i][j] == white)
					{
						if (pawn_black_and_white_beating(field, j, i, black, queen_black) && color == 2)//AI ����� ����
						{
							pawn_beat_hor[col_vo_voz_beat] = i;
							pawn_beat_ver[col_vo_voz_beat] = j;
							poz_hor = pawn_beat_hor[col_vo_voz_beat];
							poz_ver = pawn_beat_ver[col_vo_voz_beat];
							col_vo_voz_beat++;
							if ((field[i - 1][j - 1] == 'B' || field[i - 1][j - 1] == 'D') && field[i - 2][j - 2] == ' ')
							{
								new_poz_ver = j - 1;
								new_poz_hor = i - 1;
							}
							else if ((field[i + 1][j - 1] == 'B' || field[i + 1][j - 1] == 'D') && field[i + 2][j - 2] == ' ')
							{
								new_poz_ver = j - 1;
								new_poz_hor = i + 1;
							}
							else if ((field[i + 1][j + 1] == 'B' || field[i + 1][j + 1] == 'D') && field[i + 2][j + 2] == ' ')
							{
								new_poz_ver = j + 1;
								new_poz_hor = i + 1;
							}
							else if ((field[i - 1][j + 1] == 'B' || field[i - 1][j + 1] == 'D') && field[i - 2][j + 2] == ' ')
							{
								new_poz_ver = j + 1;
								new_poz_hor = i - 1;
							}
							AIexort = 1;
						}
						else if (pawn_black_and_white_beating(field, j, i, black, queen_black) && AIturn != 1)
						{
							cout << "\n";
							spaceFIELD();
							cout << "����� ����� �� ������� " << j - 1 << " ; " << i - 1 << " ����� ����\n";
							pawn_beat_hor[col_vo_voz_beat] = i;
							pawn_beat_ver[col_vo_voz_beat] = j;
							col_vo_voz_beat++;
						}
						if (check_poz_pavn_white_or_black(field, i, j, white, queen_white, black, queen_black, 1, 2) )
						{
							draw++;
						}
					}
					else if (field[i][j] == queen_white)
					{
						can_a_queen_beat(i, j, size, field, white, queen_white, black, queen_black, pawn_beat_hor, pawn_beat_ver, col_vo_voz_beat);
						if (check_poz_queen_white_or_black(field, i, j, white, queen_white, black, queen_black, 1, 2))
						{
							draw++;
						}
					}

				}
				else
				{
					if (field[i][j] == black)
					{
						if (pawn_black_and_white_beating(field, j, i, white, queen_white) && color == 1)//AI ����� ����
						{
							pawn_beat_hor[col_vo_voz_beat] = i;
							pawn_beat_ver[col_vo_voz_beat] = j;
							poz_hor = pawn_beat_hor[col_vo_voz_beat];
							poz_ver = pawn_beat_ver[col_vo_voz_beat];
							col_vo_voz_beat++;
							if ((field[i - 1][j - 1] == 'A' || field[i - 1][j - 1] == 'C') && field[i - 2][j - 2] == ' ')
							{
								new_poz_ver = j - 1;
								new_poz_hor = i - 1;
							}
							else if ((field[i + 1][j - 1] == 'A' || field[i + 1][j - 1] == 'C') && field[i + 2][j - 2] == ' ')
							{
								new_poz_ver = j - 1;
								new_poz_hor = i + 1;
							}
							else if ((field[i + 1][j + 1] == 'A' || field[i + 1][j + 1] == 'C') && field[i + 2][j + 2] == ' ')
							{
								new_poz_ver = j + 1;
								new_poz_hor = i + 1;
							}
							else if ((field[i - 1][j + 1] == 'A' || field[i - 1][j + 1] == 'C') && field[i - 2][j + 2] == ' ')
							{
								new_poz_ver = j + 1;
								new_poz_hor = i - 1;
							}
							AIexort = 1;
						}
						else if (pawn_black_and_white_beating(field, j, i, white, queen_white) && AIturn != 1)
						{
							cout << "\n";
							spaceFIELD();
							cout << "׸���� ����� �� ������� " << j - 1 << " ; " << i - 1 << " ����� ����\n";
							pawn_beat_hor[col_vo_voz_beat] = i;
							pawn_beat_ver[col_vo_voz_beat] = j;
							col_vo_voz_beat++;
						}
						if (check_poz_pavn_white_or_black(field, i, j, black, queen_black, white, queen_white, 1, 2))
						{
							draw++;
						}
					}
					else if (field[i][j] == queen_black)
					{
						can_a_queen_beat(i, j, size, field, black, queen_black, white, queen_white, pawn_beat_hor, pawn_beat_ver, col_vo_voz_beat);
						if (check_poz_queen_white_or_black(field, i, j, black, queen_black, white, queen_white, 1, 2))
						{
							draw++;
						}
					}
				}
			}
		}
		if (turn_of_the_more % 2 == 0 ? draw == col_vo_white : draw == col_vo_blakc)
		{
			exit_the_str_cucle = true;
			break;
		}
		draw = 0;

		if (AIexort == 0 && AIturn == 1 && (color == 1 || color == 2))//����� ����� AI
		{
			poz_hor = rand() % 10;
			poz_ver = rand() % 10;
		}
		else if (AIturn == 0)
		{
			cout << "\n";
			spaceFIELD();
			cout << "�������� ���\n";
			spaceFIELD();
			cout << "��� ����� ������ �������� ���������� �����, ������� ������ �����������, � ����� ���� � �����������\n";
			spaceFIELD();
			cout << "�������� ����� ������ ������� � ������� �� ���������, � ����� �� �����������\n";
			cin >> poz_ver >> poz_hor;//���� ������� �����
			poz_hor++;//���������� �� 1 ��� ����, ����� ��������� ���������� ������� ����� 
			poz_ver++;
		}

		if (col_vo_voz_beat == 0)//�������� ������� ���� ��� ����� ��������� ����
		{
			check_poz_pawn(field, turn_of_the_more, poz_hor, poz_ver, white, black, queen_white, queen_black, AIturn);
		}
		else//���� ���� ����� ��������� ����
		{
			while (exit_the_str_cucle == false)
			{
				for (int i = 0; i < col_vo_voz_beat; i++)
				{
					if (poz_ver == pawn_beat_ver[i] && poz_hor == pawn_beat_hor[i])
					{
						check_poz_pawn(field, turn_of_the_more, poz_hor, poz_ver, white, black, queen_white, queen_black, AIturn);
						exit_the_str_cucle = true;
						break;
					}
				}
				if (exit_the_str_cucle == false)
				{
					pawn_pos_inp_error(poz_ver, poz_hor, AIturn);
				}
			}
		}

		col_vo_voz_beat = 0;

		if (AIexort == 0 && AIturn == 1 && (color == 1 || color == 2))//����� ����� AI
		{
			new_poz_hor = rand() % 10;
			new_poz_ver = rand() % 10;
		}
		else if (AIturn == 0)
		{
			cout << "\n";
			spaceFIELD();
			cout << "������� ���������� ���� �� � ������ ����������� (������ ���������, ����� �����������)\n";
			cin >> new_poz_ver >> new_poz_hor;//���� ����� ������� �����
			new_poz_hor++;//���������� �� 1 ��� ����, ����� ��������� ���������� ����� ������� �����
			new_poz_ver++;
		}

		if (exit_the_str_cucle != false)
		{
			if (turn_of_the_more % 2 == 0 ? field[new_poz_hor][new_poz_ver] == black || field[new_poz_hor][new_poz_ver] == queen_black : field[new_poz_hor][new_poz_ver] == white || field[new_poz_hor][new_poz_ver] == queen_white)
			{
				check_a_new_position(exit_the_str_cucle, new_poz_ver, new_poz_hor, poz_ver, poz_hor, field, black, queen_black, white, queen_white, AIturn);//�������� ����� �������
			}
			else
			{
				exit_the_str_cucle = false;
				if (turn_of_the_more % 2 == 0)
				{
					while (field[new_poz_hor][new_poz_ver] != black && field[new_poz_hor][new_poz_ver] != queen_black)
					{
						pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
						check_a_new_position(exit_the_str_cucle, new_poz_ver, new_poz_hor, poz_ver, poz_hor, field, black, queen_black, white, queen_white, AIturn);//�������� ����� �������
					}
				}
				else
				{
					while (field[new_poz_hor][new_poz_ver] != white && field[new_poz_hor][new_poz_ver] != queen_white)
					{
						pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
						check_a_new_position(exit_the_str_cucle, new_poz_ver, new_poz_hor, poz_ver, poz_hor, field, black, queen_black, white, queen_white, AIturn);//�������� ����� ������
					}
				}
			}
		}

		exit_the_str_cucle = false;

		while (exit_the_str_cucle == false)//��� �����
		{
			check_a_new_position(exit_the_str_cucle, new_poz_ver, new_poz_hor, poz_ver, poz_hor, field, black, queen_black, white, queen_white, AIturn);//�������� ����� �������
			if (field[new_poz_hor][new_poz_ver] == ' ')//����������� ����� ���� �� ����� ������� ��� ������ �����
			{
				field[new_poz_hor][new_poz_ver] = field[poz_hor][poz_ver];
				field[poz_hor][poz_ver] = ' ';
				exit_the_str_cucle = true;
			}
			else//����������� ����� ���� �� ����� ������� ���� ������ �����
			{
				if (turn_of_the_more % 2 == 0 && field[new_poz_hor][new_poz_ver] == black || field[new_poz_hor][new_poz_ver] == queen_black)//���� ������ ����� � ���� ���� ������
				{
					if (field[poz_hor][poz_ver] == white)//���� ��� ����� �����
					{
						if (new_poz_ver > poz_ver)//���������� � ����� ������� �� ��������� ���� ����
						{
							if (new_poz_hor > poz_hor)//���������� � ����� ������� �� ����������� ���� ����
							{
								if (field[new_poz_hor + 1][new_poz_ver + 1] == ' ' && new_poz_hor + 1 <= 9 && new_poz_ver + 1 <= 9)//�������� ���� �� �� ������ ������ �����
								{
									field[new_poz_hor + 1][new_poz_ver + 1] = field[poz_hor][poz_ver];
									field[new_poz_hor][new_poz_ver] = ' ';
									field[poz_hor][poz_ver] = ' ';
									col_vo_blakc--;
									new_poz_hor++;
									new_poz_ver++;
									check_the_ability_to_beat_again(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, size, turn_of_the_more, col_vo_white, col_vo_blakc, AIturn, black, queen_black);
									exit_the_str_cucle = true;
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
							else
							{
								if (field[new_poz_hor - 1][new_poz_ver + 1] == ' ' && new_poz_hor - 1 >= 2 && new_poz_ver + 1 <= 9)//�������� ���� �� �� ������ ������ �����
								{
									field[new_poz_hor - 1][new_poz_ver + 1] = field[poz_hor][poz_ver];
									field[new_poz_hor][new_poz_ver] = ' ';
									field[poz_hor][poz_ver] = ' ';
									col_vo_blakc--;
									new_poz_hor--;
									new_poz_ver++;
									check_the_ability_to_beat_again(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, size, turn_of_the_more, col_vo_white, col_vo_blakc, AIturn, black, queen_black);
									exit_the_str_cucle = true;
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
								if (field[new_poz_hor + 1][new_poz_ver - 1] == ' ' && new_poz_hor + 1 <= 9 && new_poz_ver - 1 >= 2)//�������� ���� �� �� ������ ������ �����
								{
									field[new_poz_hor + 1][new_poz_ver - 1] = field[poz_hor][poz_ver];
									field[new_poz_hor][new_poz_ver] = ' ';
									field[poz_hor][poz_ver] = ' ';
									col_vo_blakc--;
									new_poz_hor++;
									new_poz_ver--;
									check_the_ability_to_beat_again(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, size, turn_of_the_more, col_vo_white, col_vo_blakc, AIturn, black, queen_black);
									exit_the_str_cucle = true;
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
							else
							{
								if (field[new_poz_hor - 1][new_poz_ver - 1] == ' ' && new_poz_hor - 1 >= 2 && new_poz_ver - 1 >= 2)//�������� ���� �� �� ������ ������ �����
								{
									field[new_poz_hor - 1][new_poz_ver - 1] = field[poz_hor][poz_ver];
									field[new_poz_hor][new_poz_ver] = ' ';
									field[poz_hor][poz_ver] = ' ';
									col_vo_blakc--;
									new_poz_hor--;
									new_poz_ver--;
									check_the_ability_to_beat_again(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, size, turn_of_the_more, col_vo_white, col_vo_blakc, AIturn, black, queen_black);
									exit_the_str_cucle = true;
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
						}
					}
					else if (field[poz_hor][poz_ver] == queen_white)
					{
						if (new_poz_ver > poz_ver)//���������� � ����� ������� �� ��������� ���� ����
						{
							if (new_poz_hor > poz_hor)//���������� � ����� ������� �� ����������� ���� ����
							{
								if (field[new_poz_hor + 1][new_poz_ver + 1] == ' ' && new_poz_hor + 1 <= 9 && new_poz_ver + 1 <= 9)//�������� ���� �� �� ������ ������ �����
								{
									queen_beat(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, turn_of_the_more, col_vo_white, col_vo_blakc, exit_the_str_cucle, AIturn, 1, 1);
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
							else
							{
								if (field[new_poz_hor - 1][new_poz_ver + 1] == ' ' && new_poz_hor - 1 >= 2 && new_poz_ver + 1 <= 9)//�������� ���� �� �� ������ ������ �����
								{
									queen_beat(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, turn_of_the_more, col_vo_white, col_vo_blakc, exit_the_str_cucle, AIturn, -1, 1);
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
								if (field[new_poz_hor + 1][new_poz_ver - 1] == ' ' && new_poz_hor + 1 <= 9 && new_poz_ver - 1 >= 2)//�������� ���� �� �� ������ ������ �����
								{
									queen_beat(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, turn_of_the_more, col_vo_white, col_vo_blakc, exit_the_str_cucle, AIturn, 1, -1);
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
							else
							{
								if (field[new_poz_hor - 1][new_poz_ver - 1] == ' ' && new_poz_hor - 1 >= 2 && new_poz_ver - 1 >= 2)//�������� ���� �� �� ������ ������ �����
								{
									queen_beat(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, turn_of_the_more, col_vo_white, col_vo_blakc, exit_the_str_cucle, AIturn, -1, -1);
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
						}
					}
				}
				else if (turn_of_the_more % 2 != 0 && (field[new_poz_hor][new_poz_ver] == white || field[new_poz_hor][new_poz_ver] == queen_white))//���� ������ ������ � ���� ���� �����
				{
					if (field[poz_hor][poz_ver] == black)
					{
						if (new_poz_ver > poz_ver)//���������� � ����� ������� �� ��������� ���� ����
						{
							if (new_poz_hor < poz_hor)//���������� � ����� ������� �� ����������� ���� ����
							{
								if (field[new_poz_hor - 1][new_poz_ver + 1] == ' ' && new_poz_hor - 1 >= 2 && new_poz_ver + 1 <= 9)//�������� ���� �� �� ������ ������ �����
								{
									field[new_poz_hor - 1][new_poz_ver + 1] = field[poz_hor][poz_ver];
									field[new_poz_hor][new_poz_ver] = ' ';
									field[poz_hor][poz_ver] = ' ';
									col_vo_white--;
									new_poz_hor--;
									new_poz_ver++;
									check_the_ability_to_beat_again(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, size, turn_of_the_more, col_vo_white, col_vo_blakc, AIturn, white, queen_white);
									exit_the_str_cucle = true;
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
							else
							{
								if (field[new_poz_hor + 1][new_poz_ver + 1] == ' ' && new_poz_hor + 1 <= 9 && new_poz_ver + 1 <= 9)//�������� ���� �� �� ������ ������ �����
								{
									field[new_poz_hor + 1][new_poz_ver + 1] = field[poz_hor][poz_ver];
									field[new_poz_hor][new_poz_ver] = ' ';
									field[poz_hor][poz_ver] = ' ';
									col_vo_white--;
									new_poz_hor++;
									new_poz_ver++;
									check_the_ability_to_beat_again(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, size, turn_of_the_more, col_vo_white, col_vo_blakc, AIturn, white, queen_white);
									exit_the_str_cucle = true;
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
								if (field[new_poz_hor - 1][new_poz_ver - 1] == ' ' && new_poz_hor - 1 >= 2 && new_poz_ver - 1 >= 2)//�������� ���� �� �� ������ ������ �����
								{
									field[new_poz_hor - 1][new_poz_ver - 1] = field[poz_hor][poz_ver];
									field[new_poz_hor][new_poz_ver] = ' ';
									field[poz_hor][poz_ver] = ' ';
									col_vo_white--;
									new_poz_hor--;
									new_poz_ver--;
									check_the_ability_to_beat_again(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, size, turn_of_the_more, col_vo_white, col_vo_blakc, AIturn, white, queen_white);
									exit_the_str_cucle = true;
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
							else
							{
								if (field[new_poz_hor + 1][new_poz_ver - 1] == ' ' && new_poz_hor + 1 <= 9 && new_poz_ver - 1 >= 2)//�������� ���� �� �� ������ ������ �����
								{
									field[new_poz_hor + 1][new_poz_ver - 1] = field[poz_hor][poz_ver];
									field[new_poz_hor][new_poz_ver] = ' ';
									field[poz_hor][poz_ver] = ' ';
									col_vo_white--;
									new_poz_hor++;
									new_poz_ver--;
									check_the_ability_to_beat_again(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, size, turn_of_the_more, col_vo_white, col_vo_blakc, AIturn, white, queen_white);
									exit_the_str_cucle = true;
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
						}
					}
					else if (field[poz_hor][poz_ver] == queen_black)
					{
						if (new_poz_ver > poz_ver)//���������� � ����� ������� �� ��������� ���� ����
						{
							if (new_poz_hor > poz_hor)//���������� � ����� ������� �� ����������� ���� ����
							{
								if (field[new_poz_hor + 1][new_poz_ver + 1] == ' ' && new_poz_hor + 1 <= 9 && new_poz_ver + 1 <= 9)//�������� ���� �� �� ������ ������ �����
								{
									queen_beat(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, turn_of_the_more, col_vo_white, col_vo_blakc, exit_the_str_cucle, AIturn, 1, 1);
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
							else
							{
								if (field[new_poz_hor - 1][new_poz_ver + 1] == ' ' && new_poz_hor - 1 >= 2 && new_poz_ver + 1 <= 9)//�������� ���� �� �� ������ ������ �����
								{
									queen_beat(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, turn_of_the_more, col_vo_white, col_vo_blakc, exit_the_str_cucle, AIturn, -1, 1);
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
								if (field[new_poz_hor + 1][new_poz_ver - 1] == ' ' && new_poz_hor + 1 <= 9 && new_poz_ver - 1 >= 2)//�������� ���� �� �� ������ ������ �����
								{
									queen_beat(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, turn_of_the_more, col_vo_white, col_vo_blakc, exit_the_str_cucle, AIturn, 1, -1);
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
							else
							{
								if (field[new_poz_hor - 1][new_poz_ver - 1] == ' ' && new_poz_hor - 1 >= 2 && new_poz_ver - 1 >= 2)//�������� ���� �� �� ������ ������ �����
								{
									queen_beat(field, new_poz_hor, new_poz_ver, poz_hor, poz_ver, turn_of_the_more, col_vo_white, col_vo_blakc, exit_the_str_cucle, AIturn, -1, -1);
								}
								else
								{
									pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
								}
							}
						}
					}
				}
				else
				{
					pawn_pos_inp_error(new_poz_ver, new_poz_hor, AIturn);
				}
			}
		}

		turning_a_pawn(new_poz_hor, new_poz_ver, field, queen_white, queen_black, turn_of_the_more);

		turn_of_the_more++;//��������� ���

		exit_the_str_cucle = false;

		system("cls");//������� ���� ����� ����

		filed_out_durig_the_game(field, size);//����� ���� ����� ���� ������
		cout << "\n";
		spaceFIELD();
		cout << "�������� " << col_vo_white << " ����� ����� � " << col_vo_blakc << " ������ �����\n";
		AIexort = 0;
	} while (col_vo_blakc != 0 && col_vo_white != 0);

	if (col_vo_blakc == 0)//���������� ���������� ������
	{
		spaceFIELD();
		cout << "\n\n�������� �����\n";
	}
	else if (col_vo_white == 0)
	{
		spaceFIELD();
		cout << "\n\n�������� ������\n";
	}
	else if (exit_the_str_cucle == true)
	{
		spaceFIELD();
		cout << "\n\n�����\n";
	}
}

void who_needs_to_take_away_figure(int turn_of_the_more, int& col_vo_black, int& col_vo_white)//���� ������� ������
{
	if (turn_of_the_more % 2 == 0)
	{
		col_vo_black--;
	}
	else
	{
		col_vo_white--;
	}
}

void pawn_pos_inp_error(int& ver, int& hor, int AIturn)//��� ����� ������� ����� �������� ������
{
	if (AIturn == 1)
	{
		hor = rand() % 8 + 2;
		ver = rand() % 8 + 2;
		//cout << ver - 1 << " ";
		//cout << hor - 1 << "\n";
	}
	else
	{
		spaceFIELD();
		cout << "�� ����� �������� ����������, ������� �� ��� ���\n";
		cin >> ver >> hor;
		hor++;
		ver++;
	}
}

void turning_a_pawn(int hor, int ver, char field[][12], char queen_white, char queen_black, int turn_of_the_more)//����������� ����� � ����� ���� ��� ����� �� �������
{
	if (hor == 9 && turn_of_the_more % 2 == 0)
	{
		field[hor][ver] = queen_white;
	}
	else if (hor == 2 && turn_of_the_more % 2 != 0)
	{
		field[hor][ver] = queen_black;
	}
}