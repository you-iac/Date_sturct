#include"Data_Struct.h"

Queue* Queue_Init()			//��ʼ�� - ���ն��� S��
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	Node*	P = (Node*)malloc(sizeof(Node));
	if (queue && P) {
		P->Next = NULL;
		queue->Front = queue->Rears = P;
		return queue;
	}
	else {
		return NULL;
	}
}
int Queue_InEmpty(Queue* queue)			//�ж�һһ�������Ƿ�Ϊ�գ�������Ϊ���򷵻�true
{
	return queue->Front == queue->Rears ? 0 : 1;
}
int Queue_Destroy(Queue* queue)			//���ٶ���
{
	Node* P = NULL, *Q = NULL;
	for (P = queue->Front; P != NULL; ) {
		Q = P;
		P = P->Next;
		free(Q);
	}
	free(queue);
	return 1;
}
int Queue_Push(Queue* queue, ElemNodeType X)		//��ջ����ջSδ������x����ʹ֮��Ϊ��ջ��
{
	Node* P = (Node*)malloc(sizeof(Node));
	if (P) {
		P->Data = X;
		P->Next = NULL;

		queue->Rears->Next = P;
		queue->Rears = P;
		return 1;
	}
	else {
		return 0;
	}
}
int Queue_priority_Push(Queue* queue, int Type, ElemNodeType X)
{
	Node* BUFF = (Node*)malloc(sizeof(Node));
	if (queue && BUFF) {
		Node* P = queue->Front;	//�ڵ�ָ��ָ��ͷ��
		BUFF->Data = X;

		while (P->Next) {
			if (Type == 1) {
				if (BUFF->Data.Int <= P->Next->Data.Int) break;
			}
			else if (Type == 2) {
				if (BUFF->Data.Int > P->Next->Data.Int) break;
			}
			P = P->Next;
		}

		BUFF->Next = P->Next;
		P->Next = BUFF;
		return 1;
	}
	else {
		return 0;
	}
}
int Queue_Pop(Queue* queue, ElemNodeType* X)			//��ջ����ջS�ǿգ��򵯳�ջ��Ԫ�أ�����x���ء�
{
	if ( Queue_InEmpty(queue) ) {
		Node* P = queue->Front;
		queue->Front = queue->Front->Next;
		*X = queue->Front->Data;
		free(P);
		return 1;
	}
	else {
		return 0;
	}
	
}
int Queue_GetTop(Queue* queue, ElemNodeType* X)		//��ջ��Ԫ�أ���ջS�ǿգ�����x����ջ��Ԫ�ء�
{
	if (Queue_InEmpty(queue)) {
		*X = queue->Front->Data;
		return 1;
	}
	else {
		return 0;
	}
}