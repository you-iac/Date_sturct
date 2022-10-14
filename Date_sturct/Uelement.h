#pragma once


//�����������ݣ��洢������������
typedef union MyUnion {
	int		Int;
	char	Char;
	//double	Double;
	void* Point;
} ElemNodeType;

//���ݽڵ�
typedef struct node {
	ElemNodeType Data;
	struct node* Next;
} Node;

void Node_Print(Node* L);

void ElemNode_Swap(ElemNodeType* a, ElemNodeType* b);
//a�Ƿ��b��
bool ElemNode_compare(ElemNodeType a, ElemNodeType b);

//�����������ݽ�������
int		Get_IntElemNode(ElemNodeType X);
//�����������ݽ�������
char	Get_CharElemNode(ElemNodeType X);
//�����������ݽ�������
void* Get_VoidElemNode(ElemNodeType X);
//�������ַ�װ����������
ElemNodeType In_IntElemNode(int X);
//�����ַ���װ����������
ElemNodeType In_CharElemNode(char X);
//����ָ���װ����������
ElemNodeType In_VoidElemNode(void* X);