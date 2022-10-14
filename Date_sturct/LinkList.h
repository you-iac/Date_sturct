#pragma once
#pragma once

typedef struct LNode {		//栈
	Node* Head;				//节点指针
	int Size;
} List;

List* List_Init();
int  List_InEmpty(List* list);	//判断是否空
int  List_Append (List* list, ElemNodeType X);
int  List_Deal	 (List* list, ElemNodeType X);	//删除
void List_Print  (List* list);					//输出
