#include"Tree.h"
#include"Queue.h"

int main() {
	pBTNode node = CreateBTTree();
	PreOrder(node);
	printf("\n");
	MidOrder(node);
	printf("\n");
	PostOrder(node);
	printf("\n");
	printf("leaves size = %d\n", BTLeavesSize(node));
	printf("high size = %d\n", BTHight(node));


	printf("the 3 level nodes sizes = %d\n", BinaryTreeLevelKSize(node, 3));
	pBTNode find = BinaryTreeFind(node, 7);
	if (find) {
		printf("find->data = %d", find->data);
	}
	BTDestory(&node);
	
	
	//BinaryTreeLevelOrder(node);
	//printf("%d", BinaryTreeComplete(node));


	/*char a[] = "ABC#D###E#FG##H##";
	int i = 0;
	pBTNode root = BinaryTreeCreate(a, sizeof(a) / sizeof(a[0]), &i);
	BinaryTreeLevelOrder(root);*/
	return 0;
}