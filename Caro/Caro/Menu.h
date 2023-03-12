#ifndef _MENU_H_
#define _MENU_H_
#include "Save.h"
void Menu(); // Menu tro choi
void Start(); // Bat dau tro choi
void Information(); // Thong tin tro choi
void Howtoplay(); // HUong dan tro choi
void Exit(); // Thoat tro choi
void Restart(int kt, Nguoichoi d); // Tiep tuc tro choi sau khi co nguoi thang
#define Max_List_Menu 5 // So lua chon cua Menu
static int flag;
#endif // !_MENU_H_
