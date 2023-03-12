#ifndef _DICHUYEN_H_
#define _DICHUYEN_H_
#include "Dungchung.h"
#include "Save.h"
void MoveUp(position& a); // Di chuyen len
void MoveDown(position& a); // Di chuyen xuong
void MoveLeft(position& a); // Di chuyen sang trai
void MoveRight(position& a); // Di chuyen sang phai
void Nhapnutdichuyen(position& a, int b[BOARD_SIZE][BOARD_SIZE], Nguoichoi d); // Nhan nut tu ban phim cu nguoi choi de di chuyen
void DanhXO(position& a, int b[BOARD_SIZE][BOARD_SIZE]); // Danh XO
#endif // !_DICHUYEN_H_

