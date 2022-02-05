#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#define WIDE 640//页面长
#define HIGH 480//页面宽
#define SNAKE_NUM 500//蛇的最大节数
void initsetting();//初始化菜单中图表设置
void menu();
void game();
void heart(int x,int y,int w,int h,char *arr);//居中函数
void game_score_bk();//显示分数函数
void initsnake();//初始化蛇数据函数
void initgraw();//初始化图表
void initgamegraph();//初始化图表背景
void gamegraw();//游戏图表
void keycontrol();//按键控制函数
void setfood();//放置食物函数
int fault();//判断是否结束函数
void snakemove();//移动函数
void eatfood();//判断是否吃了食物
void initgame();//初始化属性数据
