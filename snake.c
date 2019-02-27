#include <stdio.h>
#include <conio.h>
#include "hamgame.h"
#include <windows.h>
#include <time.h>
#define consolewidth 120
#define consoleheight 32
enum trangthai{
	right,left,up,down
};
typedef struct {
	int x,y;
}toado;
typedef struct {
	toado dot[30];
	int n;
	trangthai tt=down;
	int diem=0;
}Snake;
typedef struct {
	toado td;
}hoaqua;
void khoitao(Snake &snake,hoaqua &hq){
	snake.n=1;
	snake.dot[0].x=0;
	snake.dot[0].y=0;
	snake.tt=right;
	hq.td.x=20;
	hq.td.y=20;
}
int hienthi(Snake snake,hoaqua hq){
	int diem=0;
	//xoa mang hinh
	system("cls");
	TextColor(13);
	gotoxy(hq.td.x,hq.td.y);
	putchar('b');
	TextColor(10);
	gotoxy(snake.dot[0].x,snake.dot[0].y);
	putchar(232);
	TextColor(7);
	for(int i=1;i<snake.n;i++){
		gotoxy(snake.dot[i].x,snake.dot[i].y);
		printf("*");
	}
	gotoxy(40,10);
	printf("diem = %d",snake.diem);
	
}
void dieukhienvaduychuyen(Snake &snake){
	// cai duoi theo sau
	for(int i=snake.n-1;i>0;i--){
		snake.dot[i]=snake.dot[i-1];
	}
	//cai dau duy chuyen
	if(kbhit()){
		char key=_getch();
		if(key=='a'||key=='A')
			snake.tt=left;
		else if(key=='f'||key=='F')
			snake.tt=right;
		else if(key=='w'||key=='W')
			snake.tt=up;
		else if(key=='s'||key=='S')
			snake.tt=down;
	}
	if(snake.tt==up)
		snake.dot[0].y--;
	else if(snake.tt==down)
		snake.dot[0].y++;
	else if(snake.tt==left)
		snake.dot[0].x--;
	else if(snake.tt==right)
		snake.dot[0].x++;
}
void xuly(Snake &snake,hoaqua &hq,int &tangtoc){int diem=0;
	if(snake.dot[0].x==hq.td.x&&snake.dot[0].y==hq.td.y){
		// an dc
		for(int i=snake.n;i>0;i--){
			snake.dot[i]=snake.dot[i-1];
		}snake.n++;
		if(snake.tt==up)
		snake.dot[0].y--;
		else if(snake.tt==down)
		snake.dot[0].y++;
		else if(snake.tt==left)
		snake.dot[0].x--;
		else if(snake.tt==right)
		snake.dot[0].x++;
		hq.td.x=rand()%consolewidth;
		hq.td.y=rand()%consoleheight;
		if(tangtoc>30)
		tangtoc-=20;
		snake.diem++;
	}
	
}
int xulygamethua(Snake snake){
	if(snake.dot[0].x<0||snake.dot[0].x>=consolewidth||snake.dot[0].y<0||snake.dot[0].y>=consoleheight){
		return -1;
	}
	for(int i=1;i<snake.n;i++){
		if(snake.dot[0].x==snake.dot[i].x&&snake.dot[0].y==snake.dot[i].y)
		return -1;
	}
	
}

int main(){
	int tangtoc=100;
	srand(time(NULL));// khoi tao bo sinh so ngau nhien
	Snake snake;
	hoaqua hq;
	khoitao(snake,hq);
	int ok;
	while(true){
		//hien thi con ran
		hienthi(snake,hq);
		//dieu khien
		dieukhienvaduychuyen(snake);
		//xu ly 
		xuly(snake,hq,tangtoc);
		//thua game
		ok=xulygamethua(snake);
		if(ok==-1){
		gotoxy(20,20);
		printf("ban bi thua roi\n");
		while (_getch()!=13);break;// khi gap phim nhap vao la enter thi moi ngat
		}
		// dung mang hinh
		Sleep(tangtoc);
	}	
	
	
}
