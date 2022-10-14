#pragma once


//联合类型数据，存储任意数据类型
typedef union MyUnion {
	int		Int;
	char	Char;
	//double	Double;
	void* Point;
} ElemNodeType;

//数据节点
typedef struct node {
	ElemNodeType Data;
	struct node* Next;
} Node;

void Node_Print(Node* L);

void ElemNode_Swap(ElemNodeType* a, ElemNodeType* b);
//a是否比b大？
bool ElemNode_compare(ElemNodeType a, ElemNodeType b);

//输入联合数据解封成数字
int		Get_IntElemNode(ElemNodeType X);
//输入联合数据解封成数字
char	Get_CharElemNode(ElemNodeType X);
//输入联合数据解封成数字
void* Get_VoidElemNode(ElemNodeType X);
//输入数字封装成联合数据
ElemNodeType In_IntElemNode(int X);
//输入字符封装成联合数据
ElemNodeType In_CharElemNode(char X);
//输入指针封装成联合数据
ElemNodeType In_VoidElemNode(void* X);