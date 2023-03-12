#ifndef _CONSOLE_H_
#define _CONSOLE_H_
void SetWindowSize(SHORT width, SHORT height);// Thay doi Console Window Size
void SetScreenBufferSize(SHORT width, SHORT height); // Thay doi Screen Buffer Size
void DisableResizeWindow();// Vo hieu hoa kich thuoc man hinh
void DisableControlButon(bool Close, bool Min, bool Max);// Vo hieu hoa cac nut Manimize, Maximize va Close
void ShowScrollBar(BOOL Show);// An/hien thanh cuon
void ShowCur(bool CursorVisibility);// An/hien con tro 
#endif // !_CONSOLE_H_

