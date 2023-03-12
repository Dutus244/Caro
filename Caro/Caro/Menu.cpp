#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <string>
#include <mmsystem.h>
#include "Menu.h"
#include "Dungchung.h"
#include "Console.h"
#include "Ve.h"
#include "Thongso.h"
#include "Dichuyen.h"
#include "Save.h"


void Menu()
{
	int b[BOARD_SIZE][BOARD_SIZE];
	std::string C[50];
	Nguoichoi d;
	// Ham Menu
	ShowCur(0);
	std::string menu[] = { "Start","Load Game","Information","How to play","Exit" };
	int pointer = 0;
	int color = 0;
	while (1) {
		//xoa man hinh
		system("cls");
		PrintCaro(color);
		color++;
		//in menu ra man hinh
		for (int i = 0; i < Max_List_Menu; i++)
		{
			if (pointer == i) {
				SetColor(15, 4);
				GotoXY(50 , 20 + i);
				std::cout << "    " << menu[i] << std::endl;
			}
			else {
				SetColor(15, 3);
				GotoXY(50, 20 + i);
				std::cout << "    " << menu[i] << std::endl;
			}

		}
		while (1) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 72 || key == 'w' || key == 'W') {
					PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (pointer > 0) {
						pointer--;
					}
					else {
						pointer = Max_List_Menu - 1;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (pointer < Max_List_Menu - 1) {
						pointer++;
					}
					else {
						pointer = 0;
					}
					break;
				}
				if (key == 13) {
					switch (pointer) {
					case 0:
						Start();
						break;
					case 1:
						DSluu(-100,d,b);
						break;
					case 2:
						Information();
						break;
					case 3:
						Howtoplay();
						break;
					case 4:
						Exit();
						flag = -1;
						std::cout << "Goodbye" << std::endl;
						break;
					default:
						std::cout << "Erorr" << std::endl;
					}
					break;
				}
			}
		}
		if (flag == -1) {
			break;
		}
		Sleep(100);
	}
	std::cout << "Thank you very much. Bye!" << std::endl;
	Sleep(100);
	_getch();
}

void Start()
{
	ShowScrollBar(0);
	Nguoichoi d;
	d.Lanthang1 = 0;
	d.Lanthang2 = 0;
	Nhaptennguoichoi(d);
	system("cls");
	ShowCur(1);
	int b[BOARD_SIZE][BOARD_SIZE];
	position a;
	a.x = 0;
	a.y = 0;
	a.c = 1;
	SetColor(15, 13);
	Vebanco(BOARD_SIZE, BOARD_SIZE);
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			b[i][j] = 0;
		}
	}
	Vebangdiemso();
	Vebanghuongdan();
	GotoXY(2, 1);
	Nhapnutdichuyen(a, b,d);
	Sleep(100000);
}

void Restart(int kt, Nguoichoi d)
{
	if (kt == 1)
	{
		d.Lanthang1++;
	}
	else if (kt == -1)
	{
		d.Lanthang2++;
	}
	system("cls");
	ShowCur(1);
	int b[BOARD_SIZE][BOARD_SIZE];
	position a;
	a.x = 0;
	a.y = 0;
	a.c = 1;
	SetColor(15, 13);
	Vebanco(BOARD_SIZE, BOARD_SIZE);
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			b[i][j] = 0;
		}
	}
	Vebangdiemso();
	Vebanghuongdan();
	GotoXY(2, 1);
	Nhapnutdichuyen(a, b, d);
	Sleep(100000);
}

void Information()
{
	system("cls");
	GotoXY(36, 8);
	SetColor(15, 4);
	std::cout << static_cast<char>(201);
	for (int i = 0; i < 47; i++)
	{
		std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(187) << std::endl;
	for (int i = 0; i < 17; i++)
	{
		GotoXY(36, 9 + i);
		std::cout << static_cast<char>(186) << "                                               " << static_cast<char>(186) << std::endl;
	}
	GotoXY(36, 25);
	std::cout << static_cast<char>(200);
	for (int i = 0; i < 47; i++)
	{
		std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(188);
	GotoXY(38, 9);
	SetColor(15, 9);
	std::cout << static_cast<char>(201);
	for (int i = 0; i < 42; i++)
	{
		std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(187) << std::endl;
	for (int i = 0; i < 14; i++)
	{
		GotoXY(38, 10 + i);
		std::cout << static_cast<char>(186) << "                                          " << static_cast<char>(186) << std::endl;
	}
	GotoXY(38, 24);
	std::cout << static_cast<char>(200);
	for (int i = 0; i < 42; i++)
	{
		std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(188);
	int _COMMAND;
	GotoXY(41, 10);
	SetColor(15, 4);
	std::cout << "Project of Introduction to Programming" << std::endl;
	GotoXY(41, 12);
	SetColor(15, 2);
	std::cout << "                CARO GAME" << std::endl;
	GotoXY(41, 13);
	SetColor(15, 3);
	std::cout << "Class: 20CLC11                 Team: 1" << std::endl;
	GotoXY(41, 15);
	SetColor(15, 4);
	std::cout << "     Instructor: Truong Toan Thinh" << std::endl;
	GotoXY(41, 17);
	SetColor(15, 10);
	std::cout << "     20127576 - Nguyen Truc Nguyen" << std::endl;
	GotoXY(41, 18);
	SetColor(15,10);
	std::cout << "     20127013 - Dang Nguyen Duy" << std::endl;
	GotoXY(41, 19);
	SetColor(15, 10);
	std::cout << "     20127001 - Ha Quoc Anh" << std::endl;
	GotoXY(41, 20);
	SetColor(15, 10);
	std::cout << "     20127370 - Mai Quy Trung" << std::endl;
	GotoXY(41, 21);
	SetColor(15, 10);
	std::cout << "     20127610 - Truong Samuel" << std::endl;
	GotoXY(41, 23);
	SetColor(15, 13);
	std::cout << "            ESC to exit " << std::endl;
	_COMMAND = toupper(_getch());
	if (_COMMAND == 27)
	{
		Menu();
	}
}

void Howtoplay()
{
	int _COMMAND;
	system("cls");
	GotoXY(34, 8);
	SetColor(15, 4);
	std::cout << static_cast<char>(218);
	for (int i = 0; i < 50; i++)
	{
		std::cout << static_cast<char>(196);
	}
	std::cout << static_cast<char>(191) << std::endl;
	for (int i = 0; i < 15; i++)
	{
		GotoXY(34, 9 + i);
		std::cout << static_cast<char>(179) << "                                                  " << static_cast<char>(179) << std::endl;
	}
	GotoXY(34, 24);
	std::cout << static_cast<char>(192);
	for (int i = 0; i < 50; i++)
	{
		std::cout << static_cast<char>(196);
	}
	std::cout << static_cast<char>(217);
	GotoXY(35, 10);
	SetColor(15, 4);
	std::cout << "                   How to play" << std::endl;
	GotoXY(35, 12);
	SetColor(15, 2);
	std::cout << "                    CARO GAME" << std::endl;
	GotoXY(35, 14);
	SetColor(15, 3);
	std::cout << "         The chessboard measures 14 x 14." << std::endl;
	GotoXY(35, 15);
	SetColor(15, 3);
	std::cout << "         A W S D to Move. Enter to Choose." << std::endl;
	GotoXY(35, 16);
	SetColor(15, 3);
	std::cout << "         Whoever gets 5 first wins." << std::endl;
	GotoXY(35, 17);
	SetColor(15, 3);
	std::cout << "         There is a 2-headed block rule." << std::endl;
	GotoXY(35, 19);
	SetColor(15, 11);
	std::cout << "               Wish you happy gaming ^^" << std::endl;
	GotoXY(35, 21);
	SetColor(15, 13);
	std::cout << "                   ESC to exit " << std::endl;
	_COMMAND = toupper(_getch());
	if (_COMMAND == 27)
	{
		Menu();
	}
}

void Exit()
{
	exit(0);
}

int main()
{
	SetWindowSize(100, 60);
	SetScreenBufferSize(100, 60);
	DisableControlButon(0, 1, 1);
	ShowScrollBar(0);
	DisableResizeWindow();
	Menu();
	return 0;
}