#pragma once
#pragma once

typedef struct LNode {		//ջ
	Node* Head;				//�ڵ�ָ��
	int Size;
} List;

List* List_Init();
int  List_InEmpty(List* list);	//�ж��Ƿ��
int  List_Append (List* list, ElemNodeType X);
int  List_Deal	 (List* list, ElemNodeType X);	//ɾ��
void List_Print  (List* list);					//���
