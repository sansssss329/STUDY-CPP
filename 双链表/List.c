#include"List.h"


int main()
{
	LTNode* head = LTBuyNode(-1);
	LTPushBack(head, 1);
	LTPushBack(head, 2);
	LTPushBack(head, 3);
	LTPushBack(head, 4);
	LTNode* find = LTFind(head, 3);
	LTInsert(find, 11);
	LTPrint(head);
	return 0;
}