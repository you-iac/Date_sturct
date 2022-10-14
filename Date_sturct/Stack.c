#include"Data_Struct.h"
//#include"Stack.h"

Stack* Stack_Init()
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack) {
		stack->node = NULL;
		stack->Size = 0;
		return stack;
	}
	else {
		return NULL;
	}
	
}
int Stack_InEmpty	(Stack* stack) 
{
	return stack->Size > 0 ? 1 : 0;
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
int Stack_Push	(Stack* stack, ElemNodeType X) 
{
	Node* P = (Node*)malloc(sizeof(Node));
	if (P) {
		P->Data = X;
		P->Next = stack->node;
		stack->node = P;
		stack->Size++;
		return 1;
	}
	else {
		return 0;
	}
}

int Stack_Pop(Stack* stack, ElemNodeType* X)		//Stack and Element's Point
{
	if ( Stack_InEmpty(stack) ) {
		Node* P = stack->node;
		stack->node = P->Next;
		*X = P->Data;
		stack->Size--;
		return 1;
	}else {
		return 0;
	}
}
int Stack_GetTop(Stack* stack, ElemNodeType* X)
{
	if ( Stack_InEmpty(stack) ) {
		Node* P = stack->node;
		*X = P->Data;
		return 1;
	}else {
		return 0;
	}
}