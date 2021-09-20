#include"Date_Struct.h"

int Queue_Init(Queue* queue)			//��ʼ�� - ���ն��� S��
{
	Node* P = (Node*)malloc(sizeof(Node));
	P->Data = 0;
	P->Next = NULL;
	queue->Front = queue->Rears = P;

	 return 0;
}
int Queue_Empty(Queue* queue)			//�ж�һһ�������Ƿ�Ϊ�գ�������Ϊ���򷵻�true
{
	return queue->Front == queue->Rears ? 1 : 0;
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
}
int Queue_Push(Queue* queue, ElemType X)		//��ջ����ջSδ������x����ʹ֮��Ϊ��ջ��
{
	Node* P = (Node*)malloc(sizeof(Node));
	P->Data = X;
	P->Next = NULL;

	queue->Rears->Next = P;
	queue->Rears = P;
	return 0;
}
ElemType Queue_Pop(Queue* queue)			//��ջ����ջS�ǿգ��򵯳�ջ��Ԫ�أ�����x���ء�
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
ElemType Queue_GetTop(Queue* queue)		//��ջ��Ԫ�أ���ջS�ǿգ�����x����ջ��Ԫ�ء�
{
	ElemType X = queue->Front->Data;
	return X;
}