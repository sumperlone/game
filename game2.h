#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define num 10//������
//��������
void Init_(char A[ROWS][COLS],int row,int col,char a);//��ʼ�����̺���
void print(char mine[ROWS][COLS],int row,int col);//��ӡ���̺���
void set(char show[ROWS][COLS],int row,int col);//�����׺���
void find(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);//ɨ�׺���
int watch(char show[ROWS][COLS],int x,int y);//��ʾ��������
int win(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);//�ж�ʤ������
void con(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y,int bt);//���
