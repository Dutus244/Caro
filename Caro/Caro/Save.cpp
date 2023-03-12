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

void Nhaptennguoichoi(Nguoichoi& d)
{
	system("cls");
	PrintCaro(1);
	GotoXY(40, 20);
	SetColor(15, 1);
	std::cout << "Name Player 1:  ";
	std::cin >> d.Ngchoi1;
	system("cls");
	PrintCaro(2);
	GotoXY(40, 20);
	SetColor(15, 4);
	std::cout << "Name Player 2:  ";
	std::cin >> d.Ngchoi2;
}

void Savegame(int b[BOARD_SIZE][BOARD_SIZE],Nguoichoi d,std::string ten)
{
	std::ofstream f;
	f.open(ten);
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (b[i][j] == -1)
			{
				b[i][j] = 2;
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			f << b[i][j];
		}
	}
	f << std::endl;
	f << d.Ngchoi1;
	f << std::endl;
	f << d.Lanthang1;
	f << std::endl;
	f << d.Luotdi1;
	f << std::endl;
	f << d.Ngchoi2;
	f << std::endl;
	f << d.Lanthang2;
	f << std::endl;
	f << d.Luotdi2;
	f.close();
}

void Loadgame(int b[BOARD_SIZE][BOARD_SIZE], Nguoichoi d, std::string ten)
{
	int dem = 0;
	std::ifstream f;
	std::string h;
	f.open(ten);
	f >> h;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			b[i][j] = h[dem] - int('0');
			dem++;
		}
	}
	f >> d.Ngchoi1;
	f >> d.Lanthang1;
	f >> d.Luotdi1;
	f >> d.Ngchoi2;
	f >> d.Lanthang2;
	f >> d.Luotdi2;
	f.close();
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (b[i][j] == 2)
			{
				b[i][j] = -1;
			}
		}
	}
	system("cls");
	ShowCur(1);
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
			if (b[i][j] == 1)
			{
				GotoXY(i * 4 + 2, j * 2 + 1);
				SetColor(15, 1);
				std::cout << "X";
			}
			else if (b[i][j] == -1)
			{
				GotoXY(i * 4 + 2, j * 2 + 1);
				SetColor(15, 4);
				std::cout << "O";
			}
		}
	}
	if (XetnuocdiO(a, b) == XetnuocdiX(a, b))
	{
		a.c = 1;
	}
	else
	{
		a.c = -1;
	}
	Vebangdiemso();
	Vebanghuongdan();
	GotoXY(2, 1);
	Nhapnutdichuyen(a, b, d);
	Sleep(100000);
}

void DSluu(int kt, Nguoichoi d, int b[BOARD_SIZE][BOARD_SIZE])
{
	std::string C[50];
	ShowCur(0);
	int pointer = 0;
	Savegame(b, d, "Temp.txt");
	int color = 0;
	while (1) {
		//xoa man hinh
		system("cls");
		ShowScrollBar(0);
		if (kt == -10 || kt == -100)
		{
			GotoXY(52, 18);
			SetColor(15, 9);
			std::cout << "LOAD GAME ";
		}
		else
		{
			GotoXY(52, 18);
			SetColor(15, 12);
			std::cout << "SAVE GAME";
		}
		GotoXY(72, 24);
		SetColor(15, 5);
		std::cout << "ESC to return";
		PrintCaro(color);
		color++;
		//in menu ra man hinh
		LaytenfileSave(C);
		for (int i = 0; i < 10; i++)
		{
			if (pointer == i) {
				SetColor(15, 4);
				GotoXY(50, 19 + i);
				if (C[i] == "")
				{
					std::cout << "This file is empty" << std::endl;
				}
				else
				{
					std::cout << "    " << C[i] << std::endl;
				}
			}
			else {
				SetColor(15, 3);
				GotoXY(50, 19 + i);
				if (C[i] == "")
				{
					std::cout << "This file is empty" << std::endl;
				}
				else
				{
					std::cout << "    " << C[i] << std::endl;
				}
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
						pointer = 10 - 1;
					}
					break;
				}
				if (key == 80 || key == 's' || key == 'S') {
					PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (pointer < 10 - 1) {
						pointer++;
					}
					else {
						pointer = 0;
					}
					break;
				}
				if (key == 27)
				{
					if (kt == -100)
					{
						Menu();
					}
					else if (kt == -11 || kt == -10)
					{
						Loadgame(b, d, "Temp.txt");
					}
				}
					if (key == 13) {
						
							if (kt == -10 || kt == -100)
							{
								if (C[pointer] == "")
								{
									system("cls");
									GotoXY(50, 15);
									std::cout << "This file is empty" << std::endl;
									Sleep(2000);
									DSluu(-10, d, b);
								}
								else
								{
									std::cout << C[pointer];
									Loadgame(b, d, C[pointer]);
									break;
								}
							}
							else if (kt == -11)
							{
								SetColor(15, 13);
								std::cout << "Name file save: ";
								std::cin >> C[pointer];
								LuutenfileSave(C);
								Savegame(b, d, C[pointer]);
								DSluu(-11, d, b);
								break;
							}
					}
				}
			}
		}
	}

void LuutenfileSave(std::string C[50])
	{
		std::ofstream f;
		f.open("Tenfilesave.txt");
		for (int i = 0; i < 10; i++)
		{
			f << C[i];
			f << std::endl;
		}
		f.close();
	}

void LaytenfileSave(std::string C[50])
	{
		std::ifstream f;
		f.open("Tenfilesave.txt");
		for (int i = 0; i < 10; i++)
		{
			f >> C[i];
		}
		f.close();
	}
