#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include "Dichuyen.h"
#include "Checkwin.h"
#include "Thongso.h"
#include "Ve.h"
#include "Dungchung.h"
#include "Save.h"
#include "Menu.h"
#include "Console.h"

void MoveUp(position& a)
{
	if (a.y > 0) {
		a.y--;
	}
	GotoXY(a.x * 4 + 2 , a.y * 2 + 1);
}

void MoveDown(position& a)
{
	if (a.y < BOARD_SIZE - 1) {
		a.y++;
	}
	GotoXY(a.x * 4 + 2  , a.y*2+1);
}

void MoveLeft(position& a)
{
	if (a.x > 0) {
		a.x--;
	}
	GotoXY(a.x * 4 +2, a.y*2+1);
}

void MoveRight(position& a) 
{
	if (a.x < BOARD_SIZE-1) {
		a.x++;
	}
	GotoXY(a.x * 4 +2, a.y*2+1);
}

void Nhapnutdichuyen(position& a, int b[BOARD_SIZE][BOARD_SIZE], Nguoichoi d)
{
	std::string C[50];
	int _COMMAND;
	bool validEnter = true;
	Thongtinbangdiem(a, b,d);
	Trangtri(a.c);
	while (1)
	{
		GotoXY(a.x * 4 + 2, a.y * 2 + 1);
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27)
		{
			system("cls");
			GotoXY(45, 25);
			// Ham Menu
			ShowCur(0);
			std::string menu[] = { "Save","Exit" };
			int pointer = 0;
			GotoXY(45, 21);
			SetColor(15, 3);
			std::cout << "Your game is not save";
			while (1) {
				//in menu ra man hinh
				for (int i = 0; i < 2; i++)
				{
					if (pointer == i) {
						SetColor(15, 4);
						GotoXY(50, 22 + i);
						std::cout << "    " << menu[i] << std::endl;
					}
					else {
						SetColor(15, 3);
						GotoXY(50, 22 + i);
						std::cout << "    " << menu[i] << std::endl;
					}
				}
				while (1) {
					if (_kbhit()) {
						char key = _getch();
						if (key == 72 || key == 'w' || key == 'W') {
							if (pointer > 0) {
								pointer--;
							}
							else {
								pointer = 2 - 1;
							}
							break;
						}
						if (key == 80 || key == 's' || key == 'S') {
							if (pointer < 2 - 1) {
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
								DSluu(-11, d, b);
								break;
							case 1:
								Menu();
								break;
							}
						}
					}
				}
				Sleep(100);
			}
			_getch();
			return;
		}
		else
		{
			if (_COMMAND == 'A')
			{
				MoveLeft(a);
				PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (_COMMAND == 'W')
			{
				MoveUp(a);
				PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (_COMMAND == 'S')
			{
				MoveDown(a);
				PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (_COMMAND == 'D')
			{
				MoveRight(a);
				PlaySound(TEXT("dichuyen.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (_COMMAND == 'T') DSluu(-11, d,b);
			else if (_COMMAND == 'L') DSluu(-10,d,b);
			else if (_COMMAND == 13) {
				DanhXO(a, b);
				Thongtinbangdiem(a, b,d);
				Trangtri(a.c);
			}
		}
		if (Xetwinhangdoc(a, b) == 1 || Xetwinhangngang(a, b) == 1 || Xetwinhangcheo1(a, b) == 1 || Xetwinhangcheo2(a, b) == 1 ) {
			HienthiwinX(d);
			break;
		}
		else if (Xetwinhangdoc(a, b) == -1 || Xetwinhangngang(a, b) == -1 || Xetwinhangcheo1(a, b) == -1 || Xetwinhangcheo2(a, b) == -1)
		{
			HienthiO(d);
			break;
		}
		else if (Xethoa(a, b) == 1)
		{
			Hienthihoa(d);
			break;
		}
	}
}

void DanhXO(position& a, int b[BOARD_SIZE][BOARD_SIZE])
{
	if (b[a.x][a.y] == 0)
	{
		b[a.x][a.y] = a.c; 
		if (a.c == 1) {
			PlaySound(TEXT("danhco.wav"), NULL, SND_FILENAME | SND_ASYNC);
			SetColor(15, 1);
			std::cout << "X";
			a.c = -1;
		}
		else if (a.c == -1) {
			SetColor(15, 4);
			PlaySound(TEXT("danhco.wav"), NULL, SND_FILENAME | SND_ASYNC);
			std::cout << "O";
			a.c = 1;
		}
	}
}