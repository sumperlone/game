//1.�����˵�
//��1������������ʾ������heart��
//��2���������Ժ�����seting��
#include"game3.h"
void initsetting()
{
setbkmode(TRANSPARENT);
settextcolor(YELLOW);
setfillcolor(RGB(195,195,195));
setlinecolor(RGB(255,255,128));
settextstyle(20,0,"����");
setfillstyle(BS_SOLID,HS_FDIAGONAL);
}
void heart(int x,int y,int w,int h,char *arr)
{
	int width=(w-x)/2-textwidth(arr)/2;
	int hight=(h-y)/2-textheight(arr)/2;
	outtextxy(width+x,hight+y,arr);
}
void menu()
{
	int rec_x=WIDE/2-60;	int rec2_x=WIDE/2-60;				
	int rec_y=HIGH/2+20;	int rec2_y=HIGH/2-50;	
	int rec_w=WIDE/2+60;	int rec2_w=WIDE/2+60;
	int rec_h=HIGH/2+50;	int rec2_h=HIGH/2-20;
	int flag=1;
	while(flag)
	{
			BeginBatchDraw();				
			setbkcolor(RGB(181,198,234));	
			cleardevice();
			HWND hnd=GetHWnd();
			SetWindowText(hnd,"�˵�");//�޸�window���ڱ���
			initsetting();			
		fillrectangle(rec_x,rec_y,rec_w,rec_h);	//�����˳�ѡ��
		fillrectangle(rec2_x,rec2_y,rec2_w,rec2_h);//������ʼ��Ϸѡ��
		char arr[]={"�˳�"};
		char arr2[]={"��ʼ��Ϸ"};
		heart(rec_x,rec_y,rec_w,rec_h,arr);
		heart(rec2_x,rec2_y,rec2_w,rec2_h,arr2);
		FlushBatchDraw();
		EndBatchDraw();
		ExMessage mse;
		if(peekmessage(&mse,EM_MOUSE))
		{
			switch(mse.message)
				{	
					case WM_LBUTTONDOWN:
					{
						if(mse.x>=rec2_x&&mse.x<=rec2_w&&mse.y>=rec2_y&&mse.y<=rec2_h)
						{
						game();
						initgraph(WIDE,HIGH,SHOWCONSOLE);
						break;
						}
						if(mse.x>=rec_x&&mse.x<=rec_w&&mse.y>=rec_y&&mse.y<=rec_h)
						{
						flag=0;
						}
					}
					default :break;
				}
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));//�����������
	initgraph(WIDE,HIGH,SHOWCONSOLE);//��ʼ��ͼ��
	setbkcolor(RGB(181,198,234));
	cleardevice();
	initsetting();//��ʼ��ͼ������
	menu();
	return 0;
}



