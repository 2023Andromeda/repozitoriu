#pragma once
#include <iostream>
#include <conio.h>

#define Check_the_req_cel(ver, hor) (ver % 2 != 0 && hor % 2 == 0) || (ver % 2 == 0 && hor % 2 != 0)//макрос вычёркивающий из использования половину поля, которая по правилам не должна быть задействована
#define check_poz_pavn_white_or_black(filed, ver, hor, my_pavn, my_queen, evil_pavn, evil_queen, i, j) ((((filed[hor + i][ver + i] == my_pavn || filed[hor + i][ver + i] == my_queen) || ((filed[hor + i][ver + i] == evil_pavn || filed[hor + i][ver + i] == evil_queen) && filed[hor + j][ver + j] != ' ') || filed[hor + i][ver + i] == '0') &&((filed[hor + i][ver - i] == my_pavn || filed[hor + i][ver - i] == my_queen) || ((filed[hor + i][ver - i] == evil_queen || filed[hor + i][ver - i] == evil_queen) && filed[hor + j][ver - j] != ' ') || filed[hor + i][ver - i] == '0') &&(filed[hor - i][ver + i] == my_pavn || filed[hor - i][ver + i] == my_queen || filed[hor - i][ver + i] == ' ' || (filed[hor - i][ver + i] != ' ' && filed[hor - j][ver + j] != ' ') || filed[hor - i][ver + i] == '0') &&(filed[hor - i][ver - i] == my_pavn || filed[hor - i][ver - i] == my_queen || filed[hor - i][ver - i] == ' ' || (filed[hor - i][ver - i] != ' ' && filed[hor - j][ver - j] != ' ') || filed[hor - j][ver - j] == '0')))
#define check_poz_queen_white_or_black(filed, ver, hor, my_pavn, my_queen, evil_pavn, evil_queen, i, j) (((filed[hor + i][ver + i] == my_pavn || filed[hor + i][ver + i] == my_queen) || ((filed[hor + i][ver + i] == evil_pavn || filed[hor + i][ver + i] == evil_queen) && filed[hor + j][ver + j] != ' ') || filed[hor + i][ver + i] == '0') &&((filed[hor + i][ver - i] == my_pavn || filed[hor + i][ver - i] == my_queen) || ((filed[hor + i][ver - i] == evil_queen || filed[hor + i][ver - i] == evil_queen) && filed[hor + j][ver - j] != ' ') || filed[hor + i][ver - i] == '0') &&(filed[hor - i][ver + i] == my_pavn || filed[hor - i][ver + i] == my_queen || (filed[hor - i][ver + i] != ' ' && filed[hor - j][ver + j] != ' ') || filed[hor - i][ver + i] == '0') &&(filed[hor - i][ver - i] == my_pavn || filed[hor - i][ver - i] == my_queen || (filed[hor - i][ver - i] != ' ' && filed[hor - j][ver - j] != ' ') || filed[hor - j][ver - j] == '0'))
#define pawn_black_and_white_beating(filed, ver, hor, pawn, queen) (((filed[hor - 1][ver + 1] == pawn || filed[hor - 1][ver + 1] == queen) && filed[hor - 2][ver + 2] == ' ' && hor - 2 >= 2 && ver + 2 <= 9) || ((filed[hor + 1][ver + 1] == pawn || filed[hor + 1][ver + 1] == queen) && filed[hor + 2][ver + 2] == ' ' && hor + 2 <= 9 && ver + 2 <= 9) || ((filed[hor + 1][ver - 1] == pawn || filed[hor + 1][ver - 1] == queen) && filed[hor + 2][ver - 2] == ' ' && hor + 2 <= 9 && ver - 2 >= 2) || ((filed[hor - 1][ver - 1] == pawn || filed[hor - 1][ver - 1] == queen) && filed[hor - 2][ver - 2] == ' ' && hor - 2 >= 2 && ver - 2 >= 2))

using namespace std;

void PlayWithPC(int Konami);
void PlayWithHuman(int Konami);
void Menu_Playing(int Konami);
void Rules();
void Menu();
void Menus();
void KonamI(int& Konami);
void space();
void spaceFIELD();
void creat_a_field(int size, char white, char black, char queen_white, char queen_black, char filed[][12], int Konami);//Формирование поля и расстановка пешек
void all_game(char filed[][12], char white, char black, int size, int queen_white, int queen_black, int color);//Процесс игры
void check_poz_pawn(char filed[][12], int turn_of_the_more, int& poz_hor, int& poz_ver, char white, char black, char queen_white, char queen_black, int AIturn);//Проверка вводимых координат пешки
void filed_out_durig_the_game(char filed[][12], int size);//Вывод поля после хода игрока
void pawn_pos_inp_error(int& poz_ver, int& poz_hor, int AIturn);//При вводе позиции пешки допущена ошибка
void the_queens_move(int& new_poz_ver, int& new_poz_hor, int& poz_ver, int& poz_hor, bool& exit_the_str_cucle, char filed[][12], int AIturn);//ход королевы
void check_the_ability_to_beat_again(char field[][12], int& new_poz_hor, int& new_poz_ver, int& poz_hor, int& poz_ver, int size, int turn_of_the_more, int& col_vo_white, int& col_vo_black, int AIturn, char evil_pawn, char evil_queen);//может ли пешка бить еще раз
void check_a_new_position(bool& exit_the_str_cucle, int& new_poz_ver, int& new_poz_hor, int& poz_ver, int& poz_hor, char filed[][12], char black, char queen_black, char white, char queen_white, int AIturn);//проверка новой позиции
void can_the_queen_beat_more( int& new_poz_ver, int& new_poz_hor, int& poz_ver, int& poz_hor, bool& exit_the_str_cucle, char field[][12], int& col_vo_white, int& col_vo_black, int turn_of_the_more, int size, int AIturn);//может ли королева бить еще раз
void who_needs_to_take_away_figure(int turn_of_the_more, int& col_vo_black, int& col_vo_white);//кому отнаять количество фигур
void the_queen_repeat_bets(char field[][12], int& new_poz_ver, int& new_poz_hor, int& poz_ver, int& poz_hor, char own_pawn, char own_queen, char alien_pawn, char alien_queen, int AIturn, int k, int j);//королева бьет еще раз
void queen_beat(char field[][12], int& new_poz_hor, int& new_poz_ver, int& poz_hor, int& poz_ver, int turn_of_the_more, int& col_vo_white, int& col_vo_blakc, bool& exit_the_str_cucle, int AIturn, int k, int j);//королева бьёт
void can_a_queen_beat(int i, int j, int size, char filed[][12], char awn_pawn, char own_queen, char enemy_pawn, char enemy_queen, int pawn_beat_hor[], int pawn_beat_ver[], int& col_vo_voz_beat);//Может королева бить?
void turning_a_pawn(int hor, int ver, char field[][12], char queen_white, char queen_black, int turn_of_the_more);//Превращение пешки в дамку если она дошла до границы
void process_of_eating_pawn(char field[][12], int& hor, int& ver, int& new_hor, int& new_ver, int turn_of_the_more, int& col_vo_black, int& col_vo_white, int i, int j);//процесс бития пешки