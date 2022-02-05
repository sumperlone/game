#include"game3.h"
enum DIR//表示蛇的方向
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
struct food
{
	int x;
	int y;
	int r;
	DWORD color;//
	bool flag;//判断吃了食物没
}food;
struct snake
{
	int num;//蛇的节数
	POINT coor[SNAKE_NUM];//坐标
	int speed;//蛇的速度
	int dir;//蛇的方向
	int score;//蛇的分数
}snake;
int fault()
{
	for(int i=1;i<=snake.num;i++)
		if(snake.coor[0].x==snake.coor[i].x&&snake.coor[0].y==snake.coor[i].y)
			return 1;
	return 0;
}
void setfood()
{
	while(!food.flag)
	{
		food.x=rand()%(WIDE-1)+1;//初始化食物
		food.y=rand()%(HIGH-1)+1;
		if(food.x%5!=0||food.y%5!=0)
			continue;
		food.r=snake.speed/2;
		food.flag=1;
	}
}
void eatfood()
{
	if(snake.coor[0].x>=food.x-5&&snake.coor[0].x<=food.x+5&&snake.coor[0].y>=food.y-5&&snake.coor[0].y<=food.y+5)
	{
		food.flag=0;
		snake.score+=10;
		snake.num++;
	}
}
void keycontrol()
{
	if(_kbhit())
	{
	switch(_getch())
		{
		case 'w':
		case 'W':
		case 72 :
			if(snake.dir!=DOWN)
			snake.dir=UP;
			break;
		case 's':
		case 'S':
		case 80 :
			if(snake.dir!=UP)
			snake.dir=DOWN;
			break;
		case 'a':
		case 'A':
		case 75 :
			if(snake.dir!=RIGHT)
			snake.dir=LEFT;
			break;
		case 'd':
		case 'D':
		case 77 :
			if(snake.dir!=LEFT)
			snake.dir=RIGHT;
			break;
		case' ':
			while(_getch()!=' ');
		}
	}
}
void gamegraw()
{
	BeginBatchDraw();
	cleardevice();
	setfillcolor(RGB(187,100,28));
	game_score_bk();
	for(int i=0;i<snake.num;i++)
	solidcircle(snake.coor[i].x,snake.coor[i].y,5);//绘制蛇
	if(food.flag)
	{
		food.color=(BLACK);
	solidcircle(food.x,food.y,food.r);
	}
	EndBatchDraw();
}
void snakemove()
{
	for(int i=snake.num;i>0;i--)
		{
		snake.coor[i]=snake.coor[i-1];
		}
	switch(snake.dir)
	{
	case UP:
		if(snake.coor[0].y<=0)
			{
				snake.coor[0].y=HIGH-1;
				break;
			}
		snake.coor[0].y-=snake.speed;
		break;
	case DOWN:
		if(snake.coor[0].y>=HIGH)
			{
				snake.coor[0].y=1;
				break;
			}
		snake.coor[0].y+=snake.speed;
		break;
	case RIGHT:
		if(snake.coor[0].x>=WIDE)
			{
				snake.coor[0].x=1;
				break;
			}
		snake.coor[0].x+=snake.speed;
		break;
	case LEFT:
		if(snake.coor[0].x<=0)
			{
				snake.coor[0].x=WIDE-1;
				break;
			}
		snake.coor[0].x-=snake.speed;
		break;
	}
}
void initgame()
{
	initsnake();//初始化蛇
	food.flag=0;//初始化食物属性
}
void initsnake()
{
	snake.num=3;//蛇的节数
	snake.speed=10;
	snake.dir=RIGHT;
	snake.score=0;
	for(int i=0;i<snake.num;i++)
	{
		snake.coor[i].x=10*(snake.num-i);
		snake.coor[i].y=10;
	}
	
}
void initgraw()
{
	initgamegraph();//初始化游戏界面
	game_score_bk();//初始化设置得分画面
}
void initgamegraph()
{
	initgraph(WIDE,HIGH,SHOWCONSOLE);
	setbkcolor(RGB(181,198,234));
	cleardevice();
}
 void game_score_bk()
{
int rec_x=WIDE-100;
int rec_y=10;
int rec_w=WIDE-30;
int rec_h=40;
char arr[]={"分数："};
char grade[100]={""};
sprintf(grade,"%d",snake.score);
setlinecolor(RGB(187,100,28));
settextcolor(RED);
rectangle(rec_x,rec_y,rec_w,rec_h);
heart(rec_x,rec_y,rec_w,rec_h,arr);
outtextxy((rec_w-rec_x)/2+rec_x+18,18,grade);
}
void game()
{
	initgame();//初始化游戏数据
	initgraw();//初始化游戏画面
	while(1)
	{
		HWND hnd=GetHWnd();//修改window窗口标题
		SetWindowText(hnd,"贪吃蛇");
		gamegraw();
		snakemove();
		keycontrol();
		Sleep(80);
		setfood();
		eatfood();
		if(fault())
			break;
	}
	settextstyle(20,0,"楷体");
	settextcolor(RED);
	heart(0,0,WIDE,HIGH/2,"游戏结束！");
	heart(0,HIGH/2,WIDE,HIGH,"最终分数：");
	char grade[100]={""};
	sprintf(grade,"%d",snake.score);
	outtextxy(WIDE/2+38,HIGH*3/4-10,grade);//输出最终分数
	getchar();
}