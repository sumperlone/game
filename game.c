#include"game.h"
void pan(char c)
{
	if(c=='#')	printf("电脑胜利\n");
	if(c=='*')	printf("玩家胜利\n");
	if(c=='1')	printf("平局\n");
}
int win(char sanziqi[ROW][COL],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		if(sanziqi[i][0]==sanziqi[i][1]&&sanziqi[i][2]==sanziqi[i][1]&&sanziqi[i][0]!=' ')
			{
				return sanziqi[i][0];
			}
	}
	for(i=0;i<col;i++)
	{
		if(sanziqi[0][i]==sanziqi[1][i]&&sanziqi[2][i]==sanziqi[1][i]&&sanziqi[0][i]!=' ')
			{
				return sanziqi[0][i];
			}
	}
		if(sanziqi[0][0]==sanziqi[1][1]&&sanziqi[2][2]==sanziqi[1][1]&&sanziqi[0][0]!=' ')
			{
				return sanziqi[0][0];
			}
		if(sanziqi[0][2]==sanziqi[1][1]&&sanziqi[0][2]==sanziqi[2][0]&&sanziqi[2][0]!=' ')
			{
				return sanziqi[0][2];
			}
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
			{
				if(sanziqi[i][j]==' ')
				return '0';
			}
		return '1';
}
void initialization (char sanziqi[ROW][COL],int row,int col)//初始化棋盘函数
{	
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		sanziqi[i][j]=' ';
	}
}
void computermove(char sanziqi[ROW][COL],int row,int col)
{
	int x,y;
	printf("电脑走\n");
	while(1)
	{
		x=rand()%row;
		y=rand()%col;
		if(sanziqi[x][y]==' ')
		{
			sanziqi[x][y]='#';
			break;
		}
	}
}
void playmove(char sanziqi[ROW][COL],int row,int col)//玩家棋盘
	{
		int x,y;
		printf("玩家走\n");
		while(1)
		{
			printf("请输入要下的坐标->\n");
			scanf("%d%d",&x,&y);
			if(x>=1 && x<=row && y>=1 && y<=col)
			{
				if(sanziqi[x-1][y-1]==' ')
				{
					sanziqi[x-1][y-1]='*';
					break;
				}
				else
				{
					printf("该坐标已被占用，请重新输入！\n");
				}
			}
			else
			{
				printf("请输入正确的坐标！\n");
			}
		}
	}
void input(char sanziqi[ROW][COL],int row,int col)//打印棋盘
{	int i;
	for(i=0;i<row;i++)
	{
		int j=0;
		for(j=0;j<col;j++)
		{	
			printf(" %c ",sanziqi[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		if(i<row-1)
		{	
			for(j=0;j<col;j++)
			{
				printf("---");
				if(j<col-1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void menu()
{	
	int i;
	do 
	{
		printf("****************************\n");
		printf("****1.进入三子棋  0.退出****\n");
		printf("****************************\n");
		printf("请选择->");
		scanf("%d",&i);
		switch(i)
		{case 1:	
			game();
			break;
		 case 0:
			break;
		 default:
			printf("错误，请重输：\n");
			break;
		}
	}while(i);
}
void game()
{
	char c='0';
	initialization (sanziqi,ROW,COL);
	input(sanziqi,ROW,COL);//初始化棋盘
	while(1)
	{
		playmove(sanziqi,ROW,COL);//玩家移动
		input(sanziqi,ROW,COL);//打印棋盘
		c=win(sanziqi,ROW,COL);
		pan(c);
		if(c!='0')
			break;
		computermove(sanziqi,ROW,COL);//电脑移动
		input(sanziqi,ROW,COL);//打印棋盘
		c=win(sanziqi,ROW,COL);
		pan(c);
		if(c!='0')
			break;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	menu();
	return 0;
}