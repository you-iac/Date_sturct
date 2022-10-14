#pragma once

/// <summary>
/// ջ
/// </summary>
typedef struct SNode {		//ջ
	Node* node;				//�ڵ�ָ��
	int Size;
} Stack;

/*ջ��������*/
Stack* Stack_Init	();					//��ʼ�� - ����ջ S��
int Stack_InEmpty	(Stack* stack);		//�ж�һһ��ջ�Ƿ�Ϊ�գ���ջSΪ���򷵻�true
int Stack_Destroy	(Stack* stack);		//����
int Stack_Push	(Stack* stack, ElemNodeType X);		//��ջ����ջSδ������x����ʹ֮��Ϊ��ջ��
int Stack_Pop	(Stack* stack, ElemNodeType* X);	//��ջ����ջS�ǿգ��򵯳�ջ��Ԫ�أ�����x���ء�
int Stack_GetTop(Stack* stack, ElemNodeType* X);	//��ջ��Ԫ�أ���ջS�ǿգ�����x����ջ��Ԫ�ء�