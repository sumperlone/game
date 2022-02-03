#include"game2.h"
void game2()
{
	char mine[ROWS][COLS]={0};//玩家的
	char show[ROWS][COLS]={0};//雷的
	//1.初始化棋盘
	Init_(mine,ROWS,COLS,'*');
	Init_(show,ROWS,COLS,'0');
	//2.打印棋盘
	print(mine,ROW,COL);
	//3.放雷
	set(show,ROW,COL);
	//4.扫雷
	find(mine,show,ROW,COL);
}
void test()//菜单
{
	{	
	int input;
	do
	{
		printf("************************\n");
		printf("*********1.play*********\n");
		printf("*********0.exit*********\n");
		printf("************************\n");
		printf("请选择0 / 1->");
		scanf("%d",&input);
		switch(input)
		{
		case 0:	break;
		case 1:	
			{
				game2();
				break;
			}
		default : 
			{
				printf("选择错误，请重新选择！\n");
				break;
			}
		}
	}while(input);
}
}
int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}