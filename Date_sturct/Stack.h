#pragma once

/// <summary>
/// 栈
/// </summary>
typedef struct SNode {		//栈
	Node* node;				//节点指针
	int Size;
} Stack;

/*栈操作声明*/
Stack* Stack_Init	();					//初始化 - 个空栈 S。
int Stack_InEmpty	(Stack* stack);		//判断一一个栈是否为空，若栈S为空则返回true
int Stack_Destroy	(Stack* stack);		//销毁
int Stack_Push	(Stack* stack, ElemNodeType X);		//进栈，若栈S未满，则将x加入使之成为新栈顶
int Stack_Pop	(Stack* stack, ElemNodeType* X);	//出栈，若栈S非空，则弹出栈顶元素，并用x返回。
int Stack_GetTop(Stack* stack, ElemNodeType* X);	//读栈顶元素，若栈S非空，则用x返回栈顶元素。