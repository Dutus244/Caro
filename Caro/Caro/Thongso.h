#ifndef _THONG_SO_H_
#define _THONG_SO_H_
#include "Dungchung.h"
#include "Save.h"
void Thongtinbangdiem(position& a, int b[BOARD_SIZE][BOARD_SIZE], Nguoichoi d); // Hien thi ten, so lan thang, so nuoc di cua 2 nguoi choi
void Thongtinbanghuongdan();// Hien thi chi dan
int XetnuocdiX(position& a, int b[BOARD_SIZE][BOARD_SIZE]);// Tinh so nuoc da di cua nguoi choi X
int XetnuocdiO(position& a, int b[BOARD_SIZE][BOARD_SIZE]);// Tinh so nuoc da di cua nguoi choi O
void Trangtri(int); // Hien thi den luot danh cua ai
#endif // !_THONG_SO_H_

