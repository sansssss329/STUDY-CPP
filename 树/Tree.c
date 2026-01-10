#include"Tree.h"
pBTNode CreateBTTree() {
	pBTNode n1 = BuyBTNode(1);
	pBTNode n2 = BuyBTNode(2);
	pBTNode n3 = BuyBTNode(3);
	pBTNode n4 = BuyBTNode(4);
	pBTNode n5 = BuyBTNode(5);
	pBTNode n6 = BuyBTNode(6);
	pBTNode n7 = BuyBTNode(7);
	pBTNode n8 = BuyBTNode(8);
	pBTNode n9 = BuyBTNode(9);
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n4->right = n5;
	n3->right = n6;
	n6->left = n7;
	n7->left = n8;
	n7->right = n9;
	return n1;
}

void BTDestory(pBTNode* root) {
	if (!*root)	return;
	BTDestory(&((*root)->left));
	BTDestory(&((*root)->right));
	free(*root);
	root = NULL;
}

pBTNode BuyBTNode(DataTpyeTree data) {
	pBTNode newnode = (pBTNode)malloc(sizeof(BTNode));
	if (!newnode) {
		perror("malloc faoll");
		exit(1);
	}
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

void PreOrder(pBTNode root) {
	if (!root) {
		printf("N ");
		return;
	}
	
	printf("%d ", root->data);
	
	PreOrder(root->left);

	PreOrder(root->right);
}

void MidOrder(pBTNode root) {
	if (!root) {
		printf("N ");
		return;
	}
	
	MidOrder(root->left);
	
	printf("%d ", root->data);
	
	MidOrder(root->right);
}

void PostOrder(pBTNode root) {
	if (!root) {
		printf("N ");
		return;
	}

	PostOrder(root->left);

	PostOrder(root->right);

	printf("%d ", root->data);
}

int BTLeavesSize(pBTNode root) {
	if (!root) {
		return 0;
	}

	if (!root->left && !root->right) {
		return 1;
	}

	return BTLeavesSize(root->left) + BTLeavesSize(root->right);
}

int BTHight(pBTNode root) {
	if (!root) {
		return 0;
	}
	int LH = BTHight(root->left);
	int RH = BTHight(root->right);

	return LH > RH ? LH + 1 : RH + 1;
}

int BinaryTreeLevelKSize(pBTNode root, int k) {
	if (!root) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

pBTNode BinaryTreeFind(pBTNode root, DataTpyeTree x) {
	if (!root) {
		return NULL;
	}
	if (root->data == x) {
		return root;
	}
	pBTNode p1 = BinaryTreeFind(root->left, x);
	pBTNode p2 = BinaryTreeFind(root->right, x);
	return p1 ? p1 : p2;
}

pBTNode BinaryTreeCreate(DataTpyeTree* a, int n, int* pi) {
	if (*pi >= n) return NULL;
	char* p = a;
	if(p[*pi] == '#') {
		(*pi)++;
		return NULL;
	}
	pBTNode root = (pBTNode)malloc(sizeof(BTNode));
	if (!root) {
		perror("malloc fail");
		exit(1);
	}
	root->data = p[(*pi)++];
	root->left = BinaryTreeCreate(a, n, pi);
	root->right = BinaryTreeCreate(a, n, pi);
	return root;
}
//BFS遍历二叉树
void BinaryTreeLevelOrder(pBTNode root) {
	Queue Q;
	QueueInit(&Q);
	pQueue q = &Q;
	QueuePush(q, root);
	while (!QueueEmpty(q)) {
		pBTNode cur = QueueFront(q);
		QueuePop(q);
		if (!cur) {
			continue;
		}
		printf("%c ", cur->data);
		QueuePush(q, cur->left);
		QueuePush(q, cur->right);
	}
}
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(pBTNode root) {
	if(!root) return 1;
	Queue Q;
	QueueInit(&Q);
	pQueue q = &Q;
	QueuePush(q, root);
	while (!QueueEmpty(q)) {
		pBTNode cur = QueueFront(q);
		QueuePop(q); 
		if (!cur) {
			break;
		}
		QueuePush(q, cur->left);
		QueuePush(q, cur->right);
	}
	while (!QueueEmpty(q)) {
		pBTNode cur = QueueFront(q);
		QueuePop(q);
		if (cur) {
			return 0;
		}
	}
	return 1;
}