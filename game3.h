#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#define WIDE 640//ҳ�泤
#define HIGH 480//ҳ���
#define SNAKE_NUM 500//�ߵ�������
void initsetting();//��ʼ���˵���ͼ������
void menu();
void game();
void heart(int x,int y,int w,int h,char *arr);//���к���
void game_score_bk();//��ʾ��������
void initsnake();//��ʼ�������ݺ���
void initgraw();//��ʼ��ͼ��
void initgamegraph();//��ʼ��ͼ����
void gamegraw();//��Ϸͼ��
void keycontrol();//�������ƺ���
void setfood();//����ʳ�ﺯ��
int fault();//�ж��Ƿ��������
void snakemove();//�ƶ�����
void eatfood();//�ж��Ƿ����ʳ��
void initgame();//��ʼ����������
