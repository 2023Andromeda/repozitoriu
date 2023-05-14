#include <iostream>
#include <conio.h>
#include "Header.h"

using namespace std;

void creat_a_field(int size, char white, char black, char queen_white, char queen_black, char field[][12], int Konami)//������������ ���� � ����������� �����
{
	spaceFIELD();
	cout << "A - ����� �����\n";
	spaceFIELD();
	cout << "B - ������ �����\n";
	spaceFIELD();
	cout << "C - ����� �����\n";
	spaceFIELD();
	cout << "D - ������ �����\n\n";
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
			if (i % 2 != 0)//������� ����������� ��� ������ ��� �� ������ ���� �� �����������
			{
				if (i < 5)//����������� ����� �����
				{
					if (j % 2 == 0)//������� ����������� ��� ������ ��� �� ������ ���� �� ���������
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
				else if (i >= 5 && i <= 6)//������ ������
				{
					field[i][j] = ' ';
				}
				else//����������� ������ �����
				{
					if (j % 2 == 0)//������� ����������� ��� ������ ��� �� ������ ���� �� ���������
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
				if (i < 5)//����������� ����� �����
				{
					if (j % 2 != 0)//������� ����������� ��� ������ ��� �� ������ ���� �� ���������
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
				else if (i >= 5 && i <= 6)//������ ������
				{
					field[i][j] = ' ';
				}
				else//����������� ������ �����
				{
					if (j % 2 != 0)//������� ����������� ��� ������ ��� �� ������ ���� �� ���������
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
				if (i < 5)//����������� ����� �����
				{
					if (j % 2 != 0)//������� ����������� ��� ������ ��� �� ������ ���� �� ���������
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
				else if (i >= 5 && i <= 6)//������ ������
				{
					field[i][j] = ' ';
				}
				else//����������� ������ �����
				{
					if (j % 2 != 0)//������� ����������� ��� ������ ��� �� ������ ���� �� ���������
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
				if (i < 5)//����������� ����� �����
				{
					if (j % 2 == 0)//������� ����������� ��� ������ ��� �� ������ ���� �� ���������
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
				else if (i >= 5 && i <= 6)//������ ������
				{
					field[i][j] = ' ';
				}
				else//����������� ������ �����
				{
					if (j % 2 == 0)//������� ����������� ��� ������ ��� �� ������ ���� �� ���������
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
	cout << "�������� 12 ����� ����� � 12 ������ �����";

}

void filed_out_durig_the_game(char field[][12], int size)//����� ���� ����� ���� ������
{
	spaceFIELD();
	cout << "A - ����� �����\n";
	spaceFIELD();
	cout << "B - ������ �����\n";
	spaceFIELD();
	cout << "C - ����� �����\n";
	spaceFIELD();
	cout << "D - ������ �����\n\n";
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