#include <iostream>
#include "Thongso.h"
#include "Checkwin.h"
#include "Dungchung.h"
#include "Ve.h"
#include "Save.h"

void Thongtinbangdiem(position& a, int b[BOARD_SIZE][BOARD_SIZE], Nguoichoi d)
{
	GotoXY(65, 10);
	SetColor(15, 0);
	std::cout << "C A R O";
	// Thong tin bang X
	GotoXY(92, 2);
	SetColor(15, 4);
	std::cout << " Player 1" << std::endl;
	GotoXY(89, 4);
	SetColor(15, 2);
	std::cout << "Ten nguoi choi: " << d.Ngchoi1 << std::endl;
	GotoXY(89, 5);
	SetColor(15, 1);
	std::cout << "So van thang: " << d.Lanthang1 << std::endl;
	GotoXY(89, 6);
	SetColor(15, 4);
	std::cout << "So nuoc da di:  " << XetnuocdiX(a, b) << std::endl;
	// Thong tin bang O
	GotoXY(92, 11);
	SetColor(15, 1);
	std::cout << " Player 2" << std::endl;
	GotoXY(89, 13);
	SetColor(15, 2);
	std::cout << "Ten nguoi choi: " << d.Ngchoi2 << std::endl;
	GotoXY(89, 14);
	SetColor(15, 1);
	std::cout << "So van thang: " << d.Lanthang2 << std::endl;
	GotoXY(89, 15);
	SetColor(15, 4);
	std::cout << "So nuoc da di:  " << XetnuocdiO(a, b) << std::endl;
}

void Thongtinbanghuongdan()
{
	GotoXY(90, 21);
	SetColor(15, 4);
	std::cout << "  How to play" << std::endl;
	GotoXY(90, 23);
	SetColor(15, 10);
	std::cout << "A D W S to Move" << std::endl;
	GotoXY(90, 24);
	SetColor(15, 3);
	std::cout << "T to Save game" << std::endl;
	GotoXY(90, 25);
	SetColor(15, 12);
	std::cout << "L to Load game" << std::endl;
	GotoXY(90, 26);
	SetColor(15, 5);
	std::cout << "ESC to Exit" << std::endl;
}

int XetnuocdiX(position& a, int b[BOARD_SIZE][BOARD_SIZE])
{
	int demX = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (b[i][j] == 1)
			{
				demX++;
			}
		}
	}
	return demX;
}

int XetnuocdiO(position& a, int b[BOARD_SIZE][BOARD_SIZE])
{
	int demO = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (b[i][j] == -1)
			{
				demO++;
			}
		}
	}
	return demO;
}

void Trangtri(int kt)
{
	if (kt == 1)
	{
		SetColor(15, 1);
		GotoXY(61, 12); std::cout << "Den luot X danh";
	}
	else if (kt == -1)
	{
		SetColor(15, 4);
		GotoXY(61, 12); std::cout << "Den luot O danh";
	}
}