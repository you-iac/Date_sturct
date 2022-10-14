#include"Data_Struct.h"

List* List_Init() {
	List* list = (List*)malloc(sizeof(List));
	Node* P = (Node*)malloc(sizeof(Node));
	if (list && P) {
		P->Next = NULL;
		list->Head = P;
		list->Size = 0;

		return list;
	}
	else {
		return NULL;
	}
}

int List_InEmpty(List* list) {
	return list->Size > 0 ? 1 : 0;
}

int List_Append(List* list, ElemNodeType X) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p) {
		p->Data = X;
		p->Next = NULL;

		Node* P = list->Head;

		while (P->Next) {
			if (P->Next->Data.Int > p->Data.Int) {
				break;
			}
			P = P->Next;
		}

		p->Next = P->Next;
		P->Next = p;
		return 1;
	}
	else {
		return 0;
	}
	
}

int List_Deal(List* list, ElemNodeType X) {
	Node* P = list->Head;

	while (P->Next) {
		if (P->Next->Data.Int == X.Int) {
			Node* p = P->Next;
			P->Next = P->Next->Next;
			free(p);
			return 1;
		}
	}

	return 0;
}

void List_Print(List* list) {
	Node* P = list->Head->Next;
	while (P) {
		printf("%d ", P->Data.Int);
		P = P->Next;
	}
}