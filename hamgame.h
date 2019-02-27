#include <stdio.h>
#include <conio.h>
#include <windows.h>
// ham tang kich thuoc console 
void ResizeConsole(int width,int height){
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console,&r);
	MoveWindow(console,r.left,r.top,width,height,TRUE);
}
// ham to mau 
void TextColor(int x){
	HANDLE mau;
	mau=GetStdHandle
(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
// ham dich chuyen co tro toi toa do x,y
void gotoxy(int x,int y){
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos={x,y};
	hConsoleOutput=GetStdHandle
(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
// ham xoa mang hinh
void XoaMangHinh(){
	HANDLE hOut;
	COORD Position;
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X=0;
	Position.Y=0;
	SetConsoleCursorPosition(hOut,Position);
}

