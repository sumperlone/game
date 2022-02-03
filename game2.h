#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define num 10//雷数量
//函数声明
void Init_(char A[ROWS][COLS],int row,int col,char a);//初始化棋盘函数
void print(char mine[ROWS][COLS],int row,int col);//打印棋盘函数
void set(char show[ROWS][COLS],int row,int col);//设置雷函数
void find(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);//扫雷函数
int watch(char show[ROWS][COLS],int x,int y);//显示雷数函数
int win(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);//判断胜负函数
void con(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y,int bt);//检测
