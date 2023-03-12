#include <iostream>
#include "Ve.h"
#include "Dungchung.h"
#include "Thongso.h"

void PrintCaro(int color)
{
	int x = 25, y = 1;
	SetColor(15,color % 4);
	GotoXY(x, y);				 std::cout << "ooooooooooooo";
	GotoXY(x - 3, y + 1);			std::cout << "oooooooooooooooo";
	GotoXY(x - 5, y + 2);  std::cout << "oooooooooooooooooo";
	GotoXY(x - 6, y + 3); std::cout << "ooooooooooooooooooo";
	SetColor(15, color % 4);
	GotoXY(x - 7, y + 4);std::cout << "ooooooo";
	GotoXY(x - 8, y + 5);std::cout << "ooooooo";
	GotoXY(x - 8, y + 6);std::cout << "ooooooo";
	GotoXY(x - 8, y + 7);std::cout << "ooooooo";
	GotoXY(x - 8, y + 8);std::cout << "ooooooo";
	GotoXY(x - 8, y + 9);std::cout << "ooooooo";
	SetColor(15, color % 4);
	GotoXY(x - 8, y + 10);std::cout << "ooooooo";
	GotoXY(x - 7, y + 11);std::cout << "ooooooo";
	GotoXY(x - 6, y + 12);std::cout << "ooooooooooooooooooo";
	GotoXY(x - 5, y + 13); std::cout << "oooooooooooooooooo";
	SetColor(15, color % 4);
	GotoXY(x - 3, y + 14);		std::cout << "oooooooooooooooo";
	GotoXY(x, y + 15);			 std::cout << "ooooooooooooo";
	SetColor(15, color % 4 + 1);
	GotoXY(x - 4 + 22, y + 4);				  std::cout << "ooooooooooo";
	GotoXY(x - 4 + 22 - 2, y + 5);		    std::cout << "ooooooooooooooo";
	GotoXY(x - 4 + 22 - 3, y + 6);		   std::cout << "ooooooooooooooooo";
	SetColor(15, color % 4 + 1);
	GotoXY(x - 4 + 22 - 3, y + 7);			std::cout << "ooooooooooooooooo";
	GotoXY(x - 4 + 22 - 3, y + 8);			std::cout << "oooooo     oooooo";
	GotoXY(x - 4 + 22 - 3, y + 9);			std::cout << "oooooo     oooooo";
	SetColor(15, color % 4 + 1);
	GotoXY(x - 4 + 22 - 3, y + 10);		std::cout << "oooooo     oooooo";
	GotoXY(x - 4 + 22 - 3, y + 11);		std::cout << "ooooooooooooooooo";
	GotoXY(x - 4 + 22 - 3, y + 12);		std::cout << "oooooo     oooooo";
	SetColor(15, color % 4 + 1);
	GotoXY(x - 4 + 22 - 3, y + 13);		std::cout << "oooooo     oooooo";
	GotoXY(x - 4 + 22 - 3, y + 14);		std::cout << "oooooo     oooooo";
	GotoXY(x - 4 + 22 - 3, y + 15);		std::cout << "oooooo     oooooo";

	SetColor(15, color % 4 + 2);

	GotoXY(x + 33, y + 4);			std::cout << "ooooo   ooooooooo";
	GotoXY(x + 33, y + 5);			std::cout << "oooooooooooooooooo";
	GotoXY(x + 33, y + 6);			std::cout << "ooooooooooooooooooo";
	SetColor(15, color % 4 + 2);
	GotoXY(x + 33, y + 7);			std::cout << "oooooooooooooooooooo";
	GotoXY(x + 1 + 33, y + 8);			std::cout << "ooooooo     ooooooo";
	GotoXY(x + 1 + 33, y + 9);			std::cout << "ooooooo     ooooooo";
	SetColor(15, color % 4 + 2);
	GotoXY(x + 1 + 33, y + 10);		std::cout << "ooooooo";
	GotoXY(x + 1 + 33, y + 11);		std::cout << "ooooooo";
	GotoXY(x + 1 + 33, y + 12);		std::cout << "ooooooo";
	SetColor(15, color % 4 + 2);
	GotoXY(x + 1 + 33, y + 13);		std::cout << "ooooooo";
	GotoXY(x + 1 + 33, y + 14);		std::cout << "ooooooo";
	GotoXY(x + 1 + 33, y + 15);		std::cout << "ooooooo";

	SetColor(15, color % 4 + 3);
	GotoXY(x + 57, y + 4);					std::cout << "ooooooooooo";
	GotoXY(x + 57 - 2, y + 5);			std::cout << "ooooooooooooooo";
	GotoXY(x + 57 - 3, y + 6);			std::cout << "ooooooooooooooooo";
	GotoXY(x + 57 - 3, y + 7);			std::cout << "ooooooooooooooooo";
	SetColor(15, color % 4 + 3);
	GotoXY(x + 57 - 3, y + 8);			std::cout << "oooooo     oooooo";
	GotoXY(x + 57 - 3, y + 9);			std::cout << "oooooo     oooooo";
	GotoXY(x + 57 - 3, y + 10);		std::cout << "oooooo     oooooo";
	GotoXY(x + 57 - 3, y + 11);		std::cout << "oooooo     oooooo";
	SetColor(15, color % 4 + 3);
	GotoXY(x + 57 - 3, y + 12);		std::cout << "ooooooooooooooooo";
	GotoXY(x + 57 - 3, y + 13);		std::cout << "ooooooooooooooooo";
	SetColor(15, color % 4 + 3);
	GotoXY(x + 57 - 2, y + 14);		std::cout << "ooooooooooooooo";
	GotoXY(x + 57, y + 15);				std::cout << "ooooooooooo";
}

void Vebanco(int m, int n)
{
	int i, j;
	std::cout << static_cast<char>(218);
	for (i = 0; i < n - 1; i++)
	{
		std::cout << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(194);
	}
	std::cout << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
	std::cout << static_cast<char>(191) << std::endl;
	for (i = 0; i < m - 1; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			std::cout << static_cast<char>(179) << "   ";
		}
		std::cout << std::endl;
		std::cout << static_cast<char>(195);
		for (j = 0; j < n - 1; j++)
		{
			std::cout << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(197);
		}
		std::cout << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
		std::cout << static_cast<char>(180) << std::endl;
	}
	for (j = 0; j < n + 1; j++)
	{
		std::cout << static_cast<char>(179) << "   ";
	}
	std::cout << std::endl;
	std::cout << static_cast<char>(192);
	for (i = 0; i < n - 1; i++)
	{
		std::cout << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(193);
	}
	std::cout << static_cast<char>(196) << static_cast<char>(196) << static_cast<char>(196);
	std::cout << static_cast<char>(217);
	GotoXY(2, 1);
}

void Vebangdiemso()
{
	// BangX
	GotoXY(80, 1);
	SetColor(15, 9);
	std::cout << static_cast<char>(201);
	for (int i = 0; i < 35; i++)
	{
		std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(187) << std::endl;
	for (int i = 0; i < 6; i++)
	{
		GotoXY(80, 2 + i);
		std::cout << static_cast<char>(186) << "                                   " << static_cast<char>(186) << std::endl;
	}
	GotoXY(80, 8);
	std::cout << static_cast<char>(200);
	for (int i = 0; i < 35; i++)
	{
		std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(188);

	// BangO
	GotoXY(80, 10);
	SetColor(15, 4);
	std::cout << static_cast<char>(201);
	for (int i = 0; i < 35; i++)
	{
		std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(187) << std::endl;
	for (int i = 0; i < 6; i++)
	{
		GotoXY(80, 11 + i);
		std::cout << static_cast<char>(186) << "                                   " << static_cast<char>(186) << std::endl;
	}
	GotoXY(80, 17);
	std::cout << static_cast<char>(200);
	for (int i = 0; i < 35; i++)
	{
		std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(188);

}

void Vebanghuongdan()
{
	GotoXY(80, 19);
	SetColor(15, 13);
	std::cout << static_cast<char>(201);
	for (int i = 0; i < 35; i++)
	{
		std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(187) << std::endl;
	for (int i = 0; i < 8; i++)
	{
		GotoXY(80, 20 + i);
		std::cout << static_cast<char>(186) << "                                   " << static_cast<char>(186) << std::endl;
	}
	GotoXY(80, 28);
	std::cout << static_cast<char>(200);
	for (int i = 0; i < 35; i++)
	{
		std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(188);
	Thongtinbanghuongdan();
}