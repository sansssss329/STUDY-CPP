#pragma once
#include"Queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

//#define DataTpyeTree int
//
//typedef struct TreeNode {
//	DataTpyeTree data;
//	struct TreeNode *left;
//	struct TreeNode *right;
//} BTNode , * pBTNode;



pBTNode CreateBTTree();
pBTNode BuyBTNode(DataTpyeTree data);
void BTDestory(pBTNode* root);
void PreOrder(pBTNode root);
void MidOrder(pBTNode root);
void PostOrder(pBTNode root);
int BTLeavesSize(pBTNode root);
int BTHight(pBTNode root);
// 二叉树第k层结点个数
int BinaryTreeLevelKSize(pBTNode root, int k);
// 二叉树查找值为x的结点
pBTNode BinaryTreeFind(pBTNode root, DataTpyeTree x);


pBTNode BinaryTreeCreate(DataTpyeTree* a, int n, int* pi);

//BFS遍历二叉树
void BinaryTreeLevelOrder(pBTNode root);
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(pBTNode root);