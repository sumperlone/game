#include"game2.h"
void game2()
{
	char mine[ROWS][COLS]={0};//��ҵ�
	char show[ROWS][COLS]={0};//�׵�
	//1.��ʼ������
	Init_(mine,ROWS,COLS,'*');
	Init_(show,ROWS,COLS,'0');
	//2.��ӡ����
	print(mine,ROW,COL);
	//3.����
	set(show,ROW,COL);
	//4.ɨ��
	find(mine,show,ROW,COL);
}
void test()//�˵�
{
	{	
	int input;
	do
	{
		printf("************************\n");
		printf("*********1.play*********\n");
		printf("*********0.exit*********\n");
		printf("************************\n");
		printf("��ѡ��0 / 1->");
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
				printf("ѡ�����������ѡ��\n");
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