#ifndef _CHECK_WIN_H_
#define _CHECK_WIN_H_
#include "Dungchung.h"
#include "Save.h"
#define Max_List_Menu 2
int Xetwinhangdoc(position& a, int b[BOARD_SIZE][BOARD_SIZE]);
int Xetwinhangngang(position& a, int b[BOARD_SIZE][BOARD_SIZE]);
int Xetwinhangcheo1(position& a, int b[BOARD_SIZE][BOARD_SIZE]);
int Xetwinhangcheo2(position& a, int b[BOARD_SIZE][BOARD_SIZE]);
int Xethoa(position& a, int b[BOARD_SIZE][BOARD_SIZE]);
void Winhangdoc(position& a, int b[BOARD_SIZE][BOARD_SIZE], int x, int y, int kt, int dem);
void Winhangngang(position& a, int b[BOARD_SIZE][BOARD_SIZE], int x, int y, int kt, int dem);
void Winhangcheo1(position& a, int b[BOARD_SIZE][BOARD_SIZE], int x, int y, int kt, int dem);
void Winhangcheo2(position& a, int b[BOARD_SIZE][BOARD_SIZE], int x, int y, int kt, int dem);
void HienthiwinX(Nguoichoi d);
void HienthiO(Nguoichoi d);
void Hienthihoa(Nguoichoi d);
#endif // !_CHECK_WIN_H_

