#include"Date_Struct.h"

int Stack_Init	(Stack* stack) 
{
	stack->node = NULL;
	stack->Size = 0;
}
int Stack_Empty	(Stack* stack) 
{
	return stack->Size == 0 ? 1 : 0;
}
int Stack_Destroy(Stack* stack) 
{
	Node* P = NULL, *Q = NULL;
	P = Q = stack->node;
	for (; P != NULL;) {
		Q = P;
		P = P->Next;
		free(Q);
	}
	free(stack);
	return 0;
}
int Stack_Push	(Stack* stack, ElemType X) 
{
	Node* P = (Node*)malloc(sizeof(Node));
	P->Data = X;
	P->Next = stack->node;
	stack->node = P;
	stack->Size++;
}

ElemType Stack_Pop(Stack* stack)
{
	if (stack->Size > 0) {
		Node* P = stack->node;
		stack->node = P->Next;
		ElemType X = P->Data;
		stack->Size--;
		return X;
	}else {
		return 0;
	}
}
ElemType Stack_GetTop(Stack* stack)
{
	if (stack->Size > 0) {
		Node* P = stack->node;
		ElemType X = P->Data;
		return X;
	}else {
		return 0;
	}
}