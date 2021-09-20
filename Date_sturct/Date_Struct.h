#pragma once
#include<stdlib.h>
#include<stdlib.h>

#define ElemType int
#define ElementType int

typedef struct node {			//���ݽڵ�
	ElemType Data;
	struct node* Next;
} Node;

typedef struct SNode {			//ջ
	Node* node;					//�ڵ�ָ��
	int Size;
} Stack;

typedef struct QNode {			//����
	Node* Front, *Rears;					//�ڵ�ָ��
} Queue;

typedef struct TNode {			//������
	char Data;
	Node* Left, *Right;		//�ڵ�ָ��
} BinTree;


int Stack_Init	(Stack* stack);			//��ʼ�� - ����ջ S��
int Stack_Empty	(Stack* stack);			//�ж�һһ��ջ�Ƿ�Ϊ�գ���ջSΪ���򷵻�true
int Stack_Destroy	(Stack* stack);			//����
int Stack_Push	(Stack* stack, ElemType X);		//��ջ����ջSδ������x����ʹ֮��Ϊ��ջ��
ElemType Stack_Pop	(Stack* stack);			//��ջ����ջS�ǿգ��򵯳�ջ��Ԫ�أ�����x���ء�
ElemType Stack_GetTop	(Stack* stack);		//��ջ��Ԫ�أ���ջS�ǿգ�����x����ջ��Ԫ�ء�

int Queue_Init	(Queue* queue);			//��ʼ�� - ���ն��� S��
int Queue_Empty	(Queue* queue);			//�ж�һһ�������Ƿ�Ϊ�գ���ջSΪ���򷵻�true
int Queue_Destroy	(Queue* queue);			//���ٶ���
int Queue_Push		(Queue* queue, ElemType X);		//�����У�
ElemType Queue_Pop	(Queue* queue);			//������
ElemType Queue_GetTop	(Queue* queue);		//������

void BinTree_InorderTraversal	(BinTree* BT);	//�������
void BinTree_PreorderTraversal	(BinTree* BT);	//ǰ�����
void BinTree_PostorderTraversal	(BinTree* BT);	//�������
void BinTree_LevelorderTraversal(BinTree* BT);	//
BinTree* BinTree_Find(BinTree* BST, ElementType X);
BinTree* BinTree_Insert(BinTree* BST, ElementType X);
BinTree* BinTree_Delete(BinTree* BST, ElementType X);
BinTree* FindMin(BinTree* BTS);
int BinTree_Hight(BinTree* BTS);
