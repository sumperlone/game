#include"game2.h"
void Init_(char A[ROWS][COLS],int row,int col,char a)
{
	int i,j;
	for(i=0;i<=row;i++)
		for(j=0;j<=col;j++)
		{
			A[i][j]=a;
		}
}
void print(char mine[ROWS][COLS],int row,int col)
{
	int i,j;
	for(i=0;i<=row;i++)
	printf("%d ",i);
	printf("\n");
	for(i=1;i<=row;i++)
		{
			printf("%d ",i);
			for(j=1;j<=col;j++)
			{
				printf("%c ",mine[i][j]);
			}
			printf("\n");
		}
}
void set(char show[ROWS][COLS],int row,int col)
{
	int x,y,i;
	for(i=1;i<=num;i++)
	{
		x=rand()%row+1;
		y=rand()%col+1;
		if(show[x][y]=='0')
		show[x][y]='1';
		else
		i--;
	}
}
void find(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int x,y,flag,flag2=0;
	while(1)
	{
		printf("请输入坐标->");
		scanf("%d%d",&x,&y);
		if(x>=1&&x<=row&&y>=1&&y<=col)
		{
			if(mine[x][y]!='*')
			{
				printf("坐标已被占用，请重输!\n");
				continue;
			}
			if(show[x][y]=='1')
			{
				printf("游戏结束\n");
				print(show,ROW,COL);
				break;
			}
			else 
			{
				int bt;
				bt=1;
				flag=watch(show,x,y);
				mine[x][y]=flag+'0';
				if(mine[x][y]=='0')
				{
					con(mine,show,x,y,bt);
				}
				print(mine,row,col);
				flag2=win(mine,show,row,col);
				if(flag2==1)
					break;
			}
		}
		else
		{
			printf("坐标错误，请重输！\n");
		}
	}
}
int watch(char show[ROWS][COLS],int x,int y)
{
	return show[x-1][y]+
		show[x+1][y]+
		show[x-1][y+1]+
		show[x-1][y-1]+
		show[x+1][y+1]+
		show[x+1][y-1]+
		show[x][y-1]+
		show[x][y+1]-8*'0';
}
int win(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int i,j,flag;
	flag=0;
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			if(mine[i][j]=='*')
				flag++;
			if(flag>num)
				return 0;
		}
	}
	if(flag==num)
	{
		printf("玩家胜利\n");
		print(show,ROW,COL);
		return 1;
	}
}
void con(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y,int bt)
{
	if(x>=1&&x<=ROW&&y>=1&&y<=COL)
	{
		if(bt==1||mine[x][y]=='*')
		{
			int flag,bt=0;
			flag=watch(show,x,y);
			mine[x][y]=flag+'0';
			if(flag==0)
			{
				con(mine,show,x+1,y,bt);
				con(mine,show,x+1,y-1,bt);
				con(mine,show,x+1,y+1,bt);
				con(mine,show,x-1,y-1,bt);
				con(mine,show,x-1,y+1,bt);
				con(mine,show,x-1,y,bt);
				con(mine,show,x,y+1,bt);
				con(mine,show,x,y-1,bt);
			}
		}
	}
}