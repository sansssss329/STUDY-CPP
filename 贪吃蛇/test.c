#include"snake.h"
#include<locale.h>
void test()
{
	//一、初始化蛇
	Snake snake = { 0 };
	//二、初始化游戏
	GameStart(&snake);
	//三、运行游戏
	GameRun(&snake);
	//四、游戏结束
	GameOver(&snake);
}



int main()
{
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));
	test();
	return 0;
}