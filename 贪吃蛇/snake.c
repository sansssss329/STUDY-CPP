#include"snake.h"
#define WALL L'墙'
#define BODY L'●'
#define FOOD L'▲'//▲
#define ONE L'赵'
#define TWO L'二'
#define THREE L'炮'
#define POS_X 24
#define POS_Y 5
#define KEY_PRESS(VK)  ( (GetAsyncKeyState(VK) & 0x1) ? 1 : 0 )
//基础设置
//1.光标点设置
void SetPos(int x, int y)
{
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x , y };
	SetConsoleCursorPosition(houtput, pos);
}
//2.颜色设置
void SetWideCharColor(int foreColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD colorAttr; // 颜色属性（Windows 用 DWORD 存储）
	switch (foreColor) 
	{
		case 1: colorAttr = FOREGROUND_RED | FOREGROUND_INTENSITY; break;//红
		case 2: colorAttr = FOREGROUND_GREEN | FOREGROUND_INTENSITY; break;//绿
		case 3: colorAttr = FOREGROUND_BLUE | FOREGROUND_INTENSITY; break;//蓝
		case 4: colorAttr = FOREGROUND_RED | FOREGROUND_GREEN; break; //咖啡色
		default: colorAttr = 7; // 默认白字黑底（FOREGROUND_RED|GREEN|BLUE）
	}
	SetConsoleTextAttribute(hConsole, colorAttr);
}


//二、初始化游戏
void WelcomeToGame()
{
	SetPos(40, 14);
	wprintf(L"欢迎来到游戏\n");
	SetPos(40, 20);
	system("pause");
	system("cls");
	SetPos(31, 14);
	wprintf(L"用←.→.↑.↓控制蛇，F3加速，F4减速\n");
	SetPos(43, 17);
	wprintf(L"加速分更高\n");
	SetPos(40, 20);
	system("pause");
	system("cls");
}

void CreateMap()
{
	SetWideCharColor(1);//红色
	//上
	for (int i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}

	SetPos(0, 26);
	//下
	for (int i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}
	//左
	for (int i = 0; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	//右
	for (int i = 0; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
	//help部分
	SetWideCharColor(3);
	SetPos(64, 15);
	wprintf(L"%ls", L"保护");
	SetPos(64, 16);
	wprintf(L"%ls", L"不能咬到自己");
	SetPos(64, 17);
	wprintf(L"%ls", L"用←.→.↑.↓控制，F3加速，F4减速");
	SetPos(64, 18);
	wprintf(L"%ls", L"speed up == score up!!!!");
	SetPos(64, 19);
	wprintf(L"%ls", L"ESC退出，SPACE暂停");
}

void InitSnake(pSnake ps)
{
	int i = 0;
	pSnakeNode cur = NULL;
	//初始化蛇身
	for (i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake()::malloc");
			return;
		}
		cur->next = NULL;
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;
		if (ps->_pSnake == NULL)
		{
			ps->_pSnake = cur;
		}
		else
		{
			cur->next = ps->_pSnake;
			ps->_pSnake = cur;
		}
	}
	//打印蛇
	SetWideCharColor(2);
	int tmp = 0;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		if (tmp == 0)
		{
			wprintf(L"%lc", ONE);
			tmp++;
		}
		else if (tmp == 1)
		{
			wprintf(L"%lc", TWO);
			tmp++;
		}
		else if (tmp == 2)
		{
			wprintf(L"%lc", THREE);
			tmp++;
		}
		else
		{
			wprintf(L"%lc", BODY);
		}
		cur = cur->next;
	}
	//初始化其他信息
	ps->_dir = RIGHT;
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;
	ps->_status = OK;
}

void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;
	
again:
	do
	{
		x = rand() % 54 + 2;
		y = rand() % 24 + 1;
	} while (x % 2 != 0);
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		if (cur->x == x && cur->y == y)
		{
			goto again;
		}
		cur = cur->next;
	}
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood::malloc");
		return;
	}
	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;
	SetPos(x, y);
	SetWideCharColor(4);
	wprintf(L"%lc", FOOD);
	SetWideCharColor(2);
	ps->_pFood = pFood;
}
	//MAIN
void GameStart(pSnake ps)
{
	//0.基础设置
	system("mode con cols=100 lines=30");//窗口大小
	system("title 贪吃蛇");//窗口名
	//隐藏光标
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput, &CursorInfo);
	CursorInfo.bVisible = 0;
	SetConsoleCursorInfo(houtput, &CursorInfo);

	//1.打印环境与功能介绍
	WelcomeToGame();

	//2.打印地图
	CreateMap();
	
	//3.创建蛇
	InitSnake(ps);

	//4.创建食物
	CreateFood(ps);
	
}


//三、运行游戏
	//0.食物判断
void IsFood(pSnakeNode pn, pSnake ps)
{
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;

	pSnakeNode cur = ps->_pSnake;
	
	int tmp = 0;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		if (tmp == 0)
		{
			wprintf(L"%lc", ONE);
			tmp++;
		}
		else if (tmp == 1)
		{
			wprintf(L"%lc", TWO);
			tmp++;
		}
		else if (tmp == 2)
		{
			wprintf(L"%lc", THREE);
			tmp++;
		}
		else
		{
			wprintf(L"%lc", BODY);
		}
		cur = cur->next;
	}
	ps->_score += ps->_food_weight;
	CreateFood(ps);
}

void NoFood(pSnakeNode pn, pSnake ps)
{
	
	//增长头部
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;
	//销毁尾部
	int tmp = 0;
	pSnakeNode cur = ps->_pSnake;
	while (cur->next->next)
	{
		SetPos(cur->x, cur->y);
		if (tmp == 0)
		{
			wprintf(L"%lc", ONE);
			tmp++;
		}
		else if (tmp == 1)
		{
			wprintf(L"%lc", TWO);
			tmp++;
		}
		else if (tmp == 2)
		{
			wprintf(L"%lc", THREE);
			tmp++;
		}
		else
		{
			wprintf(L"%lc", BODY);
		}
		cur = cur->next;
	}
	SetPos(cur->next->x, cur->next->y);
	printf("  ");
	free(cur->next);
	cur->next = NULL;
}

	//死亡判断
//void KillByWall(pSnake ps)
//{
//	if (ps->_pSnake->x == 0 || ps->_pSnake->x == 56 || ps->_pSnake->y == 0 || ps->_pSnake->y == 26)
//	{
//		ps->_status = KILL_BY_WALL;
//	}
//}

void KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->_pSnake->next;
	while (cur)
	{
		if (cur->x == ps->_pSnake->x && cur->y == ps->_pSnake->y)
		{
			ps->_status = KILL_BY_SELF;
		}
		cur = cur->next;
	}
}
	//1.暂停
void Pause()
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE)) { break; }
	}
}
	//2.蛇移动
void SnakeMove(pSnake ps)
{
	pSnakeNode NextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (NextNode == NULL)
	{
		perror("SnakeMove::malloc");
		return;
	}
	switch (ps->_dir)
	{
	case UP:
		NextNode->x = ps->_pSnake->x;
		if (ps->_pSnake->y == 1)
		{
			NextNode->y = 25;
		}
		else 
		{
			NextNode->y = ps->_pSnake->y - 1;
		}
		break;
	case DOWN:
		NextNode->x = ps->_pSnake->x;
		if (ps->_pSnake->y == 25)
		{
			NextNode->y = 1;
		}
		else
		{
			NextNode->y = ps->_pSnake->y + 1;
		}
		break;
	case LEFT:
		if (ps->_pSnake->x == 2)
		{
			NextNode->x = 54;
		}
		else
		{
			NextNode->x = ps->_pSnake->x - 2;
		}
		NextNode->y = ps->_pSnake->y;
		break;
	case RIGHT:
		if (ps->_pSnake->x == 54)
		{
			NextNode->x = 2;
		}
		else
		{
			NextNode->x = ps->_pSnake->x + 2;
		}
		NextNode->y = ps->_pSnake->y;
		break;
	}
	if ((ps->_pFood->x == NextNode->x) && (ps->_pFood->y == NextNode->y))
	{
		IsFood(NextNode, ps);
	}
	else
	{
		NoFood(NextNode, ps);
	}
	NextNode = NULL;
	/*KillByWall(ps);*/
	KillBySelf(ps);
}
	//MAIN
void GameRun(pSnake ps)
{
	do
	{
		SetPos(64, 10);
		printf("总分数：%d", ps->_score);
		SetPos(64, 11);
		printf("当前史的分数：%d", ps->_food_weight);
		if (KEY_PRESS(VK_UP) && ps->_dir != DOWN)
		{
			//上
			ps->_dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->_dir != UP)
		{
			//下
			ps->_dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_dir != RIGHT)
		{
			//左
			ps->_dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_dir != LEFT)
		{
			//右
			ps->_dir = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			//暂停
			Pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			//退出
			ps->_status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_F3))
		{
			//加速
			if (ps->_sleep_time > 80)
			{
				ps->_sleep_time -= 40;
				ps->_food_weight += 2;
			}
		}
		else if (KEY_PRESS(VK_F4))
		{
			//减速
			if (ps->_food_weight > 6)
			{
				ps->_sleep_time += 40;
				ps->_food_weight -= 2;
			}
		}
		//蛇移动
		SnakeMove(ps);
		Sleep(ps->_sleep_time);
	} while (ps->_status == OK);
}

//四、游戏结束
	//MAIN
void GameOver(pSnake ps)
{
	SetWideCharColor(1);
	SetPos(24, 12);
	switch (ps->_status)
	{
	case END_NORMAL:
		printf("自己退了，FW");
		break;
	/*case KILL_BY_WALL:
		printf("666日到墙了，FW");
		break;*/
	case KILL_BY_SELF:
		printf("666磕到甲沟炎了，FW");
		break;
	}
	SetPos(0, 27);
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
}