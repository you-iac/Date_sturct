#include"Date_Struct.h"

int Queue_Init(Queue* queue)			//初始化 - 个空队列 S。
{
	Node* P = (Node*)malloc(sizeof(Node));
	P->Data = 0;
	P->Next = NULL;
	queue->Front = queue->Rears = P;

	 return 0;
}
int Queue_Empty(Queue* queue)			//判断一一个队列是否为空，若队列为空则返回true
{
	return queue->Front == queue->Rears ? 1 : 0;
}
int Queue_Destroy(Queue* queue)			//销毁队列
{
	Node* P = NULL, *Q = NULL;
	for (P = queue->Front; P != NULL; ) {
		Q = P;
		P = P->Next;
		free(Q);
	}
	free(queue);
}
int Queue_Push(Queue* queue, ElemType X)		//进栈，若栈S未满，则将x加入使之成为新栈顶
{
	Node* P = (Node*)malloc(sizeof(Node));
	P->Data = X;
	P->Next = NULL;

	queue->Rears->Next = P;
	queue->Rears = P;
	return 0;
}
ElemType Queue_Pop(Queue* queue)			//出栈，若栈S非空，则弹出栈顶元素，并用x返回。
{
	if ( !Queue_Empty(queue) ) {
		Node* P = queue->Front;
		queue->Front = queue->Front->Next;
		ElemType X = queue->Front->Data;
		free(P);
		return X;
	}
	else {
		return 0;
	}
	
}
ElemType Queue_GetTop(Queue* queue)		//读栈顶元素，若栈S非空，则用x返回栈顶元素。
{
	ElemType X = queue->Front->Data;
	return X;
}