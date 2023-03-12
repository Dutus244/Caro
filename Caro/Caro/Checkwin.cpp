#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <string>
#include <mmsystem.h>
#include "Menu.h"
#include "Checkwin.h"
#include "Dungchung.h"
#include "Console.h"
#include "Save.h"

int Xetwinhangdoc(position& a, int b[BOARD_SIZE][BOARD_SIZE])
{
	int y = 0;
	int kt = 0;
	int dem = 0;
	int dung = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (b[a.x][i] == -a.c)
		{
			dem++;
			y = i; // Luu diem cuoi trong chuoi thang de hien thi win
		}
		else
		{
			if (b[a.x][i] == a.c)
			{
				if (dem >= 5 && b[a.x][i - (5 + 1)] != a.c) // Kiem tra chan 2 dau
				{
					dung = 1;
				}			
				else
				{
					dem = 0;
				}
			}
			if (b[a.x][i] == 0)
				if (dem >= 5)
					dung = 1;
				else
					dem = 0;
		}
		if (dung == 1) // Thang thi dung lai
		{
			break;
		}
	}
	if (dem >= 5)
	{
		if (a.c == -1) {
			kt = 1;
			Winhangdoc(a, b, a.x, y, kt, dem); // Hien thi win
		}
		else if (a.c == 1){
			kt = -1;
			Winhangdoc(a, b, a.x, y, kt, dem); // Hien thi win
		}
	}
	return kt;
}

int Xetwinhangngang(position& a, int b[BOARD_SIZE][BOARD_SIZE])
{
	int y = 0;
	int kt = 0;
	int dem = 0;
	int dung = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (b[i][a.y] == -a.c)
		{
			dem++;
			y = i; // Luu diem cuoi trong chuoi thang de hien thi win
		}
		else
		{
			if (b[i][a.y] == a.c)
			{
				if (dem >= 5 && b[i - (5 + 1)][a.y] != a.c) // Kiem tra chan 2 dau
				{
					dung = 1;
				}
				else
				{
					dem = 0;
				}
			}
			if (b[i][a.y] == 0)
				if (dem >= 5)
				{
					dung = 1;
				}
				else
				{
					dem = 0;
				}
		}
		if (dung == 1)
		{
			break;
		}
	}
	if (dem >= 5)
	{
		if (a.c == -1) {
			kt = 1;
			Winhangngang(a, b, y, a.y, kt, dem); // Hien thi win
		}
		else {
			kt = -1;
			Winhangngang(a, b, y, a.y, kt, dem);
		}
	}
	return kt;
}

int Xetwinhangcheo1(position& a, int b[BOARD_SIZE][BOARD_SIZE])
{
	int y = 0;
	int kt = 0;
	int dem = 0;
	int dung = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (b[i][i - (a.x - a.y)] == -a.c)
		{
			dem++;
			y = i; // Luu diem cuoi trong chuoi thang de hien thi win
		}
		else
		{
			if (b[i][i - (a.x - a.y)] == a.c)
			{
				if (dem >= 5 && b[i - (5 + 1)][i - (5 + 1) - (a.x - a.y)] != a.c) // Kiem tra chan 2 dau
				{
					dung = 1;
				}
				else
				{
					dem = 0;
				}
			}
			if (b[i][i - (a.x - a.y)] == 0)
				if (dem >= 5)
					dung = 1;
				else
					dem = 0;
		}
		if (dung == 1)
		{
			break;
		}
	}
	if (dem >= 5)
	{
		if (a.c == -1) {
			kt = 1;
			Winhangcheo1(a, b, y, y - (a.x - a.y), kt, dem); // Hien thi win
		}
		else {
			kt = -1;
			Winhangcheo1(a, b, y, y - (a.x - a.y), kt, dem);
		}
	}
	return kt;
}

int Xetwinhangcheo2(position& a, int b[BOARD_SIZE][BOARD_SIZE])
{
	int y = 0;
	int kt = 0;
	int dem = 0;
	int dung = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (b[i][a.x + a.y - i] == -a.c)
		{
			y = i;// Luu diem cuoi trong chuoi thang de hien thi win
			dem++;
		}
		else
		{
			if (b[i][a.x + a.y - i] == a.c)
			{
				if (dem >= 5 && b[i - (5 + 1)][a.x + a.y - (i - (5 + 1))] != a.c) // Kiem tra chan 2 dau
				{
					dung = 1;
				}
				else
				{
					dem = 0;
				}
			}
			if (b[i][a.x + a.y - i] == 0)
				if (dem >= 5)
					dung = 1;
				else
					dem = 0;
		}
		if (dung == 1)
		{
			break;
		}
	}
	if (dem >= 5)
	{
		if (a.c == -1) {
			kt = 1;
			Winhangcheo2(a, b, y, a.x + a.y - y, kt, dem); // Hien thi win
		}
		else {
			kt = -1;
			Winhangcheo2(a, b, y, a.x + a.y - y, kt, dem);
		}
	}
	return kt;
}

int Xethoa(position& a, int b[BOARD_SIZE][BOARD_SIZE])
{
	int kt = 0;
	int dem = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (b[i][j] == 1 || b[i][j] == -1)
			{
				dem++;
			}
		}
	}
	if (dem == BOARD_SIZE * BOARD_SIZE) // Day ban co thi hoa
	{
		kt = 1;
	}
	return kt;
}

void Winhangdoc(position& a, int b[BOARD_SIZE][BOARD_SIZE], int x, int y, int kt, int dem)
{
	PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
	for (int i = 0; i < dem; i++)
	{
		GotoXY(x * 4 + 2, (y - i) * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 13);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 13);
			std::cout << "O";
		}
	}
	for (int i = 0; i < dem; i++)
	{
		GotoXY(x * 4 + 2, (y - i) * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 12);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 12);
			std::cout << "O";
		}
	}
	for (int i = 0; i < dem; i++)
	{
		GotoXY(x * 4 + 2, (y - i) * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 11);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 11);
			std::cout << "O";
		}
	}
	for (int i = 0; i < dem; i++)
	{
		GotoXY(x * 4 + 2, (y - i) * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 10);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 10);
			std::cout << "O";
		}
	}
}

void Winhangngang(position& a, int b[BOARD_SIZE][BOARD_SIZE], int x, int y, int kt, int dem)
{
	PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
	for (int i = 0; i < dem; i++)
	{
		GotoXY((x - i) * 4 + 2, y * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 13);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 13);
			std::cout << "O";
		}
	}
	for (int i = 0; i < dem; i++)
	{
		GotoXY((x - i) * 4 + 2, y * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 12);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 12);
			std::cout << "O";
		}
	}
	for (int i = 0; i < dem; i++)
	{
		GotoXY((x - i) * 4 + 2, y * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 11);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 11);
			std::cout << "O";
		}
	}
	for (int i = 0; i < dem; i++)
	{
		GotoXY((x - i) * 4 + 2, y * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 10);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 10);
			std::cout << "O";
		}
	}
}

void Winhangcheo1(position& a, int b[BOARD_SIZE][BOARD_SIZE], int x, int y, int kt, int dem)
{
	PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
	for (int i = 0; i < dem; i++)
	{
		GotoXY((x - i) * 4 + 2, (y - i) * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 13);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 13);
			std::cout << "O";
		}
	}
	for (int i = 0; i < dem; i++)
	{
		GotoXY((x - i) * 4 + 2, (y - i) * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 12);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 12);
			std::cout << "O";
		}
	}
	for (int i = 0; i < dem; i++)
	{
		GotoXY((x - i) * 4 + 2, (y - i) * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 11);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 11);
			std::cout << "O";
		}
	}
	for (int i = 0; i < dem; i++)
	{
		GotoXY((x - i) * 4 + 2, (y - i) * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 10);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 10);
			std::cout << "O";
		}
	}
}

void Winhangcheo2(position& a, int b[BOARD_SIZE][BOARD_SIZE], int x, int y, int kt, int dem)
{
	PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
	for (int i = 0; i < dem; i++)
	{
		GotoXY((x - i) * 4 + 2, (y + i) * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 13);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 13);
			std::cout << "O";
		}
	}
	for (int i = 0; i < dem; i++)
	{
		GotoXY((x - i) * 4 + 2, (y + i) * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 12);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 12);
			std::cout << "O";
		}
	}
	for (int i = 0; i < dem; i++)
	{
		GotoXY((x - i) * 4 + 2, (y + i) * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 11);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 11);
			std::cout << "O";
		}
	}
	for (int i = 0; i < dem; i++)
	{
		GotoXY((x - i) * 4 + 2, (y + i) * 2 + 1);
		Sleep(75);
		if (kt == 1)
		{
			SetColor(15, 10);
			std::cout << "X";
		}
		else if (kt == -1)
		{
			SetColor(15, 10);
			std::cout << "O";
		}
	}
}

void HienthiwinX(Nguoichoi d)
{
	int i = 10, j = 8;
	int color = 1;
	for (int i = 0; i < 15; i++)
	{
		GotoXY(10, 5+i);
		SetColor(14,14);              
		std::cout << "                                                                                                      " << std::endl;
	}
	while (color < 5)
	{
		ShowCur(0);
		SetColor(14, color);
		GotoXY(23, 7); std::cout << "XX          XX    XX               XX    XXXXXXXXXXXXXX    XXX           XX";
		GotoXY(23, 8); std::cout << "  XX      XX      XX               XX          XX          XX XX         XX";
		GotoXY(23, 9); std::cout << "    XX  XX        XX               XX          XX          XX   XX       XX";
		GotoXY(23, 10); std::cout<< "      XX          XX               XX          XX          XX     XX     XX";
		GotoXY(23,11); std::cout << "    XX  XX        XX       XX      XX          XX          XX       XX   XX";
		GotoXY(23, 12); std::cout<< "  XX      XX        XX   XX  XX  XX            XX          XX         XX XX";
		GotoXY(23, 13); std::cout<< "XX          XX        XX       XX        XXXXXXXXXXXXXX    XX           XXX";
		color++;
		Sleep(200);
	}
	GotoXY(45, 25); 
	// Ham Menu
	ShowCur(0);
	std::string menu[] = { "Restart","Exit" };
	int pointer = 0;
	while (1) {
		//in menu ra man hinh
		for (int i = 0; i < Max_List_Menu; i++)
		{
			if (pointer == i) {
				SetColor(14, 4);
				GotoXY(50, 17 + i);
				std::cout << "    " << menu[i] << std::endl;
			}
			else {
				SetColor(14, 3);
				GotoXY(50, 17 + i);
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
						SetColor(15, 15);
						Restart(1,d);
						break;
					case 1:
						SetColor(15,15);
						Menu();
						break;
				}
			}
		}
		}
		Sleep(100);
	}
	_getch();
}

void HienthiO(Nguoichoi d)
{
	int i = 18, j = 10;
	int color = 1;
	for (int i = 0; i < 15; i++)
	{
		GotoXY(10, 5 + i);
		SetColor(14, 14);
		std::cout << "                                                                                                      " << std::endl;
	}
	while (color < 6)
	{
		ShowCur(0);
		SetColor(14, color);
		GotoXY(23, 7); std::cout << "  OOOOOOOO      OO              OO    OOOOOOOOOOOO    OOO           OO";
		GotoXY(23, 8); std::cout << "OO        OO    OO              OO         OO         OO OO         OO";
		GotoXY(23, 9); std::cout << "OO        OO    OO              OO         OO         OO   OO       OO";
		GotoXY(23, 10); std::cout << "OO        OO    OO              OO         OO         OO     OO     OO ";
		GotoXY(23, 11); std::cout << "OO        OO    OO      OO      OO         OO         OO       OO   OO";
		GotoXY(23, 12); std::cout << "OO        OO      OO  OO  OO  OO           OO         OO         OO OO";
		GotoXY(23, 13); std::cout << "  OOOOOOOO          OO      OO        OOOOOOOOOOOO    OO           OOO";
		color++;
		Sleep(200);
	}
	GotoXY(45, 25);
	// Ham Menu
	ShowCur(0);
	std::string menu[] = { "Restart","Exit" };
	int pointer = 0;
	while (1) {
		//in menu ra man hinh
		for (int i = 0; i < Max_List_Menu; i++)
		{
			if (pointer == i) {
				SetColor(14, 4);
				GotoXY(50, 17 + i);
				std::cout << "    " << menu[i] << std::endl;
			}
			else {
				SetColor(14, 3);
				GotoXY(50, 17 + i);
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
						SetColor(15, 15);
						Restart(-1, d);
						break;
					case 1:
						SetColor(15, 15);
						Menu();
						break;
					}
				}
			}
		}
		Sleep(100);
	}
	_getch();
}

void Hienthihoa(Nguoichoi d)
{
	int i = 18, j = 10;
	int color = 2;
	for (int i = 0; i < 15; i++)
	{
		GotoXY(10, 5 + i);
		SetColor(14, 14);
		std::cout << "                                                                                                      " << std::endl;
	}
	while (color < 6)
	{
		ShowCur(0);
		SetColor(14, color);
		GotoXY(30, 7); std::cout <<  "DDDDDDDD        DDDDDDDD         DDDDDD      DD              DD";
		GotoXY(30, 8); std::cout <<  "DD      DD      DD      DD     DD      DD    DD              DD";
		GotoXY(30, 9); std::cout <<  "DD        DD    DD      DD     DD      DD    DD              DD";
		GotoXY(30, 10); std::cout << "DD        DD    DDDDDDDD       DDDDDDDDDD    DD              DD";
		GotoXY(30, 11); std::cout << "DD        DD    DD     DD      DD      DD    DD      DD      DD";
		GotoXY(30, 12); std::cout << "DD      DD      DD      DD     DD      DD      DD  DD  DD  DD";
		GotoXY(30, 13); std::cout << "DDDDDDDD        DD       DD    DD      DD        DD      DD";
		color++;
		Sleep(200);
	}
	GotoXY(45, 25);
	// Ham Menu
	ShowCur(0);
	std::string menu[] = { "Restart","Exit" };
	int pointer = 0;
	while (1) {
		//in menu ra man hinh
		for (int i = 0; i < Max_List_Menu; i++)
		{
			if (pointer == i) {
				SetColor(14, 4);
				GotoXY(50, 17 + i);
				std::cout << "    " << menu[i] << std::endl;
			}
			else {
				SetColor(14, 3);
				GotoXY(50, 17 + i);
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
						SetColor(15, 15);
						Restart(0,d);
						break;
					case 1:
						SetColor(15, 15);
						Menu();
						break;
					}
				}
			}
		}
		Sleep(100);
	}
	_getch();
}