#ifndef _SAVE_H_
#define _SAVE_H_
#include "Dungchung.h"
struct Nguoichoi // Struc luu thong tin nguoi choi
{
	std::string Ngchoi1;
	int Lanthang1;
	int Luotdi1;
	std::string Ngchoi2;
	int Lanthang2;
	int Luotdi2;
};
void Nhaptennguoichoi(Nguoichoi& d); // Nhap ten nguoi choi khi bat dau
void Savegame(int b[BOARD_SIZE][BOARD_SIZE], Nguoichoi d, std::string ten); // Save game
void Loadgame(int b[BOARD_SIZE][BOARD_SIZE], Nguoichoi d, std::string ten); // Load game
void DSluu(int kt, Nguoichoi d, int b[BOARD_SIZE][BOARD_SIZE]); // Danh sach save,load game
void LuutenfileSave(std::string C[50]); // Luu ten file save do nguoi choi dat
void LaytenfileSave(std::string C[50]); // Lay ten file save do nguoi choi dat
#endif // !_SAVE_H_

