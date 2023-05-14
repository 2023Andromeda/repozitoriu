#include <iostream>
#include <conio.h>
#include "Header.h"

using namespace std;

enum Menu
{
	MENU_PLAYING = 1,
	RULES,
	EXIT,
	KONAMI = 1986,
};

void PlayWithPC(int Konami)
{
	system("cls");
	const int size = 12;
	int color;
	char filed[size][size], black = 'B', white = 'A', queen_white = 'C', queen_black = 'D';
	spaceFIELD();
	cout << "�������� ���� ����:\n";
	spaceFIELD();
	cout << "1.�����(����� �������)\n";
	spaceFIELD();
	cout << "2.׸����(����� �������)\n";
	cin >> color;
	while (color != 1 && color != 2)
	{
		spaceFIELD();
		cout << "�� ����� �������� �����\n";
		spaceFIELD();
		cout << "������� ��� ��� ���";
		cin >> color;
	}
	system("cls");
	creat_a_field(size, white, black, queen_white, queen_black, filed, Konami);
	all_game(filed, white, black, size, queen_white, queen_black, color);
	system("cls");

}

void Menu_Playing(int Konami)
{
	system("cls");

	int PCorHuman;
	spaceFIELD();
	cout << "� ��� ������ ������?\n";
	spaceFIELD();
	cout << "1.� �����������\n";
	spaceFIELD();
	cout << "2.� ���������\n";
	cin >> PCorHuman;
	while (PCorHuman != 1 && PCorHuman != 2)
	{
		spaceFIELD();
		cout << "�� ����� �������� �����\n";
		spaceFIELD();
		cout << "������� ��� ��� ���";
		cin >> PCorHuman;
	}

	if (PCorHuman == 1)
		PlayWithPC(Konami);
	else
		PlayWithHuman(Konami);
}

void Rules()
{
	system("cls");
	cout << "1. � ���� ��������� ������� 2 ������. ������ ������������� �� ��������������� �������� �����.\n\n2. ������� ����(�����) ������������� ����� �������, ��� �� ������� ������ ������ ���� �����������  � ����� ������� ������.\n\n3. ����� ����� �������� ������������ ������� ��� �� ��������������. ����� ������������� �� ����, ������� � ������, ����� �� ������ �������.\n����� ������� ���� ������ ����������� ������, ������� ������ �������(�������) �������. ���� �������������� ����������� ����������.\n\n4. � ������ ���� ��� ����� ���������� �������� ��������. ������� ����� ����� ���������� ������ ������ �� ���������� �� �������� ��������� ������.\n\n5. ���� ������� ����� ����� �� ��������� �����������, ��� ���������� ������� � ������������ ����������������.����� ����� ������ �� ���� ���� �� ��������� ����� ��� �����\n\n6. ��� ��������� ���������, ���� �������� ���� ����� ����������� ����� �������� ����. ���� ����� ���������� �� �����, �� ������ �� ������� ���. ����, ��� - ���� �� ���������� ����� ��������� �����, ������ ������������ �������.\n\n7. ������ ����� ��������� ������������, ��������� ����� �� �����, � ��� ������, ���� ��� ��������� �� �������� � ������� ������ ������������ ������ � �� ��� ������� ��������� ����.\n������ ����� ��������� ������� ������ ����� ������������� ������ ������. �����, ��� ������ ����� ������ ����� ���� ���� � ����� �������, � �� �� ����� ���� ���������, ��� � ������� ��� ������������� ������.\n������ ����� ��������� ������������, �� ��� ������� ���������� ����������� �����, ���������� �����, �������� ���������� ��������������(������� �������� � ���������� ���������� ����������� ��� ������).\n\n8. ���� ������� ����� � �������� ������ ����� ��������� ��������� ���� ��������� ����������� � �� ��������������� ����������� ����������� ������ �� �������� ��� ������, �� ��� ������������ � �����, �������������� �� ���� ���������� ����.����� ������ �� �������� ����� ��� ����������� ���� �� ���������� ����.\n";
	system("pause");

	Menu();
}

void Menu()
{
	int userChoice = 0, Konami = 0;
	bool exit_the_program = true;

	do
	{	
		system("cls");
		Menus();
		cin >> userChoice;
		switch (userChoice)
		{
		case MENU_PLAYING:
			Menu_Playing(Konami);
			break;
		case RULES:
			Rules();
			break;
		case EXIT:
			system("cls");
			puts("��������� ���!!!");
			exit_the_program = false;
			exit(1);
			break;
		case KONAMI:
			system("cls");
			cout << "\n";
			space();
			for (int i = 6; i < 95; i++)
				cout << " ";
			cout << "����������� ������� �����!!!";
			system("pause");
			KonamI(Konami);
			break;
		default:
			system("cls");
			cout << "\n";
			space();
			for (int i = 6; i < 95; i++)
				cout << " ";
			cout << "����������� ������� �����!!!";
			system("pause");
			break;
		}
	} while (exit_the_program == true);
}

void PlayWithHuman(int Konami)
{
	system("cls");
	const int size = 12;
	int color = 0;
	char filed[size][size], black = 'B', white = 'A', queen_white = 'C', queen_black = 'D';
	creat_a_field(size, white, black, queen_white, queen_black, filed, Konami);
	all_game(filed, white, black, size, queen_white, queen_black, color);
}

void KonamI(int& Konami)
{
	char a[20];
	cout << "\n";
	space();
	for (int i = 6; i < 95; i++)
		cout << " ";
	getchar();
	gets_s(a, 20);
	if (strcmp(a, "up") == 0)
	{
		space();
		for (int i = 6; i < 95; i++)
			cout << " ";
		cout << "���? ��� �� ������ ������� �����?\n";
		space();
		for (int i = 6; i < 95; i++)
			cout << " ";
		gets_s(a, 20);
		if (strcmp(a, "up") == 0)
		{
			space();
			for (int i = 6; i < 95; i++)
				cout << " ";
			cout << "���? ��� �� ������ ������� �����?\n";
			space();
			for (int i = 6; i < 95; i++)
				cout << " ";
			gets_s(a, 20);
			if (strcmp(a, "down") == 0)
			{
				space();
				for (int i = 6; i < 95; i++)
					cout << " ";
				cout << "���? ��� �� ������ ������� �����?\n";
				space();
				for (int i = 6; i < 95; i++)
					cout << " ";
				gets_s(a, 20);
				if (strcmp(a, "down") == 0)
				{
					space();
					for (int i = 6; i < 95; i++)
						cout << " ";
					cout << "���? ��� �� ������ ������� �����?\n";
					space();
					for (int i = 6; i < 95; i++)
						cout << " ";
					gets_s(a, 20);
					if (strcmp(a, "left") == 0)
					{
						space();
						for (int i = 6; i < 95; i++)
							cout << " ";
						cout << "���? ��� �� ������ ������� �����?\n";
						space();
						for (int i = 6; i < 95; i++)
							cout << " ";
						gets_s(a, 20);
						if (strcmp(a, "right") == 0)
						{
							space();
							for (int i = 6; i < 95; i++)
								cout << " ";
							cout << "���? ��� �� ������ ������� �����?\n";
							space();
							for (int i = 6; i < 95; i++)
								cout << " ";
							gets_s(a, 20);
							if (strcmp(a, "left") == 0)
							{
								space();
								for (int i = 6; i < 95; i++)
									cout << " ";
								cout << "���? ��� �� ������ ������� �����?\n";
								space();
								for (int i = 6; i < 95; i++)
									cout << " ";
								gets_s(a, 20);
								if (strcmp(a, "right") == 0)
								{
									space();
									for (int i = 6; i < 95; i++)
										cout << " ";
									cout << "���? ��� �� ������ ������� �����?\n";
									space();
									for (int i = 6; i < 95; i++)
										cout << " ";
									gets_s(a, 20);
									if (strcmp(a, "b") == 0)
									{
										space();
										for (int i = 6; i < 95; i++)
											cout << " ";
										cout << "���? ��� �� ������ ������� �����?\n";
										space();
										for (int i = 6; i < 95; i++)
											cout << " ";
										gets_s(a, 20);
										if (strcmp(a, "a") == 0)
										{
											Konami = 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	system("cls");
	Menus();
}

void space()
{
	cout.width(20);
	cout << "";
}

void Menus()
{
	space();
	for (int i = 4; i < 200; i++)
		cout << "-";
	cout << "\n";
	space();
	cout << "|";
	for (int i = 6; i < 200; i++)
		cout << " ";
	cout << "|\n";
	space();
	cout << "|           ---------               |       |              ---------               ---------               |      /            ---------              ---------                ---------           |\n";
	space();
	cout << "|           |                       |       |              |                       |                       |    /              |                      |       |                |                   |\n";
	space();
	cout << "|           |                       |       |              |                       |                       |  /                |                      |       |                |                   |\n";
	space();
	cout << "|           |                       |       |              |                       |                       |/                  |                      |       |                |                   |\n";
	space();
	cout << "|           |                       ---------              ---------               |                       |                   ---------              ---------                ---------           |\n";
	space();
	cout << "|           |                       |       |              |                       |                       |\\                  |                      |\\                               |           |\n";
	space();
	cout << "|           |                       |       |              |                       |                       |  \\                |                      |  \\                             |           |\n";
	space();
	cout << "|           |                       |       |              |                       |                       |    \\              |                      |    \\                           |           |\n";
	space();
	cout << "|           ---------               |       |              ---------               ---------               |      \\            ---------              |      \\                 ---------           |\n";
	space();
	cout << "|";
	for (int i = 6; i < 200; i++)
		cout << " ";
	cout << "|\n";
	space();
	cout << "|";
	for (int i = 6; i < 200; i++)
		cout << " ";
	cout << "|\n";
	space();
	cout << "|";
	for (int i = 6; i < 100; i++)
		cout << " ";
	cout << "1.������";
	for (int i = 6; i < 98; i++)
		cout << " ";
	cout << "|\n";
	space();
	cout << "|";
	for (int i = 6; i < 200; i++)
		cout << " ";
	cout << "|\n";
	space();
	cout << "|";
	for (int i = 6; i < 100; i++)
		cout << " ";
	cout << "2.������� ����";
	for (int i = 6; i < 92; i++)
		cout << " ";
	cout << "|\n";
	space();
	cout << "|";
	for (int i = 6; i < 200; i++)
		cout << " ";
	cout << "|\n";
	space();
	cout << "|";
	for (int i = 6; i < 100; i++)
		cout << " ";
	cout << "3.�����";
	for (int i = 6; i < 99; i++)
		cout << " ";
	cout << "|\n";
	space();
	cout << "|";
	for (int i = 6; i < 200; i++)
		cout << " ";
	cout << "|\n";
	space();
	for (int i = 4; i < 200; i++)
		cout << "-";
}