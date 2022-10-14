#pragma once
#include"Data_Struct.h"

void Node_Print(Node* L)
{
	L = L->Next;
	while (L) {
		printf("%d ", L->Data.Int);
		L = L->Next;
	}
}

bool ElemNode_compare(ElemNodeType a, ElemNodeType b)
{
	return (Get_IntElemNode(a) > Get_IntElemNode(b));
}
int	Get_IntElemNode(ElemNodeType X)
{
	return X.Int;
}
char Get_CharElemNode(ElemNodeType X)
{
	return X.Char;
}
void* Get_VoidElemNode(ElemNodeType X)
{
	return X.Point;
}

ElemNodeType In_IntElemNode(int X)
{
	ElemNodeType x;
	x.Int = X;
	return x;
}
ElemNodeType In_CharElemNode(char X)
{
	ElemNodeType x;
	x.Char = X;
	return x;
}
ElemNodeType In_VoidElemNode(void* X)
{
	ElemNodeType x;
	x.Point = X;
	return x;
}


void ElemNode_Swap(ElemNodeType* a, ElemNodeType* b)
{
	ElemNodeType* P = (ElemNodeType*)malloc(sizeof(ElemNodeType));

	if (P) {
		*P = *a;
		*a = *b;
		*b = *P;
		free(P);
	}
	else {

	}
}