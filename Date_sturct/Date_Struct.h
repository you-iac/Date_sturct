#pragma once
#include<stdlib.h>
#include<stdlib.h>

#define ElemType int
#define ElementType int

typedef struct node {			//数据节点
	ElemType Data;
	struct node* Next;
} Node;

typedef struct SNode {			//栈
	Node* node;					//节点指针
	int Size;
} Stack;

typedef struct QNode {			//队列
	Node* Front, *Rears;					//节点指针
} Queue;

typedef struct TNode {			//二叉树
	char Data;
	Node* Left, *Right;		//节点指针
} BinTree;


int Stack_Init	(Stack* stack);			//初始化 - 个空栈 S。
int Stack_Empty	(Stack* stack);			//判断一一个栈是否为空，若栈S为空则返回true
int Stack_Destroy	(Stack* stack);			//销毁
int Stack_Push	(Stack* stack, ElemType X);		//进栈，若栈S未满，则将x加入使之成为新栈顶
ElemType Stack_Pop	(Stack* stack);			//出栈，若栈S非空，则弹出栈顶元素，并用x返回。
ElemType Stack_GetTop	(Stack* stack);		//读栈顶元素，若栈S非空，则用x返回栈顶元素。

int Queue_Init	(Queue* queue);			//初始化 - 个空队列 S。
int Queue_Empty	(Queue* queue);			//判断一一个队列是否为空，若栈S为空则返回true
int Queue_Destroy	(Queue* queue);			//销毁队列
int Queue_Push		(Queue* queue, ElemType X);		//进队列，
ElemType Queue_Pop	(Queue* queue);			//出队列
ElemType Queue_GetTop	(Queue* queue);		//读队列

void BinTree_InorderTraversal	(BinTree* BT);	//中序遍历
void BinTree_PreorderTraversal	(BinTree* BT);	//前序遍历
void BinTree_PostorderTraversal	(BinTree* BT);	//后序遍历
void BinTree_LevelorderTraversal(BinTree* BT);	//
BinTree* BinTree_Find(BinTree* BST, ElementType X);
BinTree* BinTree_Insert(BinTree* BST, ElementType X);
BinTree* BinTree_Delete(BinTree* BST, ElementType X);
BinTree* FindMin(BinTree* BTS);
int BinTree_Hight(BinTree* BTS);
