#pragma once

typedef struct QNode {		//����
	Node* Front, * Rears;	//�ڵ�ָ��
} Queue;

/*���в�������*/
Queue* Queue_Init();
int Queue_InEmpty(Queue* queue);	//����ջSΪ���򷵻�
/// ���ٶ��нṹ
int Queue_Destroy(Queue* queue);
int Queue_Push(Queue* queue, ElemNodeType X);
/// ������
int Queue_Pop(Queue* queue, ElemNodeType* X);
/// ��ö��е�ͷԪ��
int Queue_GetTop(Queue* queue, ElemNodeType* X);	//������
/// <summary>
/// ���ȶ��������
/// </summary>
/// <param name="queue = ����ָ��"></param>
/// <param name="Type = ���ȶ������� 1 �� ��С���� 2 �Ӵ�С"></param>
/// <param name="X = Ԫ������"></param>
/// <returns>��Ӳ����Ƿ�ɹ�</returns>
int Queue_priority_Push(Queue* queue, int Type, ElemNodeType X);
