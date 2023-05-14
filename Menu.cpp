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
	cout << "Выберите свой цвет:\n";
	spaceFIELD();
	cout << "1.Белые(ходят первыми)\n";
	spaceFIELD();
	cout << "2.Чёрные(ходят вторыми)\n";
	cin >> color;
	while (color != 1 && color != 2)
	{
		spaceFIELD();
		cout << "Вы ввели неверное число\n";
		spaceFIELD();
		cout << "Введите его еще раз";
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
	cout << "С кем хотите играть?\n";
	spaceFIELD();
	cout << "1.С компьютером\n";
	spaceFIELD();
	cout << "2.С человеком\n";
	cin >> PCorHuman;
	while (PCorHuman != 1 && PCorHuman != 2)
	{
		spaceFIELD();
		cout << "Вы ввели неверное число\n";
		spaceFIELD();
		cout << "Введите его еще раз";
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
	cout << "1. В игре принимают участие 2 игрока. Игроки располагаются на противоположных сторонах доски.\n\n2. Игровое поле(доска) располагается таким образом, что бы угловая темная клетка была расположена  с левой стороны игрока.\n\n3. Выбор цвета игроками определяется жребием или по договоренности. Шашки расставляются на трех, ближних к игроку, рядах на темных клетках.\nПраво первого хода обычно принадлежит игроку, который играет черными(темными) шашками. Ходы осуществляются соперниками поочередно.\n\n4. В начале игры все шашки соперников являются простыми. Простые шашки можно перемещать только вперед по диагоналям на соседнюю свободную клетку.\n\n5. Если простая шашка дошла до последней горизонтали, она становится «дамкой» и обозначается переворачиванием.Дамка может ходить на одно поле по диагонали вперёд или назад\n\n6. Ход считается сделанным, если участник игры после перемещения шашки отпустил руку. Если игрок дотронулся до шашки, он обязан ей сделать ход. Если, кто - либо из соперников хочет поправить шашки, обязан предупредить заранее.\n\n7. Взятие шашки соперника производится, переносом через неё своей, в том случае, если она находится на соседней с простой шашкой диагональной клетке и за ней имеется свободное поле.\nВзятие шашки соперника простой шашкой может производиться только вперед. Дамка, при взятии ходит только через одно поле в любую сторону, а не на любое поле диагонали, как в русских или международных шашках.\nВзятие шашки соперника обязательное, но при наличии нескольких продолжений «боя», выбирается любой, наиболее тактически целесообразный(главный критерий – отсутствие дальнейших продолжений для взятий).\n\n8. Если простая шашка в процессе взятия шашек соперника достигает поля последней горизонтали и ей предоставляется возможность дальнейшего взятия по правилам боя дамкой, то она превращается в дамку, останавливаясь на поле последнего ряда.Право взятия по правилам дамки она приобретает лишь со следующего хода.\n";
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
			puts("Приходите еще!!!");
			exit_the_program = false;
			exit(1);
			break;
		case KONAMI:
			system("cls");
			cout << "\n";
			space();
			for (int i = 6; i < 95; i++)
				cout << " ";
			cout << "Неправильно введено число!!!";
			system("pause");
			KonamI(Konami);
			break;
		default:
			system("cls");
			cout << "\n";
			space();
			for (int i = 6; i < 95; i++)
				cout << " ";
			cout << "Неправильно введено число!!!";
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
		cout << "Что? Как ты вообще вводишь слова?\n";
		space();
		for (int i = 6; i < 95; i++)
			cout << " ";
		gets_s(a, 20);
		if (strcmp(a, "up") == 0)
		{
			space();
			for (int i = 6; i < 95; i++)
				cout << " ";
			cout << "Что? Как ты вообще вводишь слова?\n";
			space();
			for (int i = 6; i < 95; i++)
				cout << " ";
			gets_s(a, 20);
			if (strcmp(a, "down") == 0)
			{
				space();
				for (int i = 6; i < 95; i++)
					cout << " ";
				cout << "Что? Как ты вообще вводишь слова?\n";
				space();
				for (int i = 6; i < 95; i++)
					cout << " ";
				gets_s(a, 20);
				if (strcmp(a, "down") == 0)
				{
					space();
					for (int i = 6; i < 95; i++)
						cout << " ";
					cout << "Что? Как ты вообще вводишь слова?\n";
					space();
					for (int i = 6; i < 95; i++)
						cout << " ";
					gets_s(a, 20);
					if (strcmp(a, "left") == 0)
					{
						space();
						for (int i = 6; i < 95; i++)
							cout << " ";
						cout << "Что? Как ты вообще вводишь слова?\n";
						space();
						for (int i = 6; i < 95; i++)
							cout << " ";
						gets_s(a, 20);
						if (strcmp(a, "right") == 0)
						{
							space();
							for (int i = 6; i < 95; i++)
								cout << " ";
							cout << "Что? Как ты вообще вводишь слова?\n";
							space();
							for (int i = 6; i < 95; i++)
								cout << " ";
							gets_s(a, 20);
							if (strcmp(a, "left") == 0)
							{
								space();
								for (int i = 6; i < 95; i++)
									cout << " ";
								cout << "Что? Как ты вообще вводишь слова?\n";
								space();
								for (int i = 6; i < 95; i++)
									cout << " ";
								gets_s(a, 20);
								if (strcmp(a, "right") == 0)
								{
									space();
									for (int i = 6; i < 95; i++)
										cout << " ";
									cout << "Что? Как ты вообще вводишь слова?\n";
									space();
									for (int i = 6; i < 95; i++)
										cout << " ";
									gets_s(a, 20);
									if (strcmp(a, "b") == 0)
									{
										space();
										for (int i = 6; i < 95; i++)
											cout << " ";
										cout << "Что? Как ты вообще вводишь слова?\n";
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
	cout << "1.ИГРАТЬ";
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
	cout << "2.ПРАВИЛА ИГРЫ";
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
	cout << "3.ВЫХОД";
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