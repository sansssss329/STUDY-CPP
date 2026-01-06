#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include<math.h>
#include<time.h>

//变量部分
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

enum GAME_STATUS
{
	OK,//活的
	//KILL_BY_WALL//撞墙
	KILL_BY_SELF,//自杀
	END_NORMAL//退游
};

typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode, * pSnakeNode;

typedef struct Snake
{
	pSnakeNode _pSnake;//蛇头
	pSnakeNode _pFood;//食物
	int _food_weight;//食物分数
	enum DIRECTION _dir;//方向
	enum GAME_STATUS _status;//状态
	int _score;//分数
	int _sleep_time;//速度
}Snake, * pSnake;

void SetPos(int x, int y);//设点

void SetWideCharColor(int foreColor);//颜色


//二、初始化游戏
void GameStart(pSnake ps);
	//1.打印环境与功能介绍
void WelcomeToGame();
	//2.打印地图
void CreateMap();
	//3.创建蛇
void InitSnake(pSnake ps);
	//4.创建食物
void CreateFood(pSnake ps);

//三、运行游戏
void GameRun(pSnake ps);
	//1.暂停
void Pause();
	//2.蛇移动
void SnakeMove(pSnake ps);

//四、游戏结束

void GameOver(pSnake ps);