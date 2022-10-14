#include"Data_Struct.h"

PrefectTree* PrefectTree_Init()
{
	PrefectTree* PFTree = (PrefectTree*)malloc(sizeof(PrefectTree));
	if (!PFTree) return NULL;
	
	PFTree->Data[0] = In_IntElemNode(-1);//�ڱ��ڵ�
	PFTree->Size = 0;					//��ȫ�������Ĵ�С
	PFTree->Capacity = MaxSize;			//�������

	return PFTree;
}

PrefectTree* Heap_Init()
{
	return PrefectTree_Init();
}

bool Heap_IsFull(MaxHeap *H)
{
	return (H->Size == H->Capacity);
}
bool Heap_IsEmpty(MaxHeap *H)
{
	return !(H->Size == 0);
}
bool MinHeap_Insert(MaxHeap* heap, ElemNodeType X)
{
	if (heap)
	{
		int buff = 0, parent = 0, buffdata = 0, parentdata = 0;

		heap->Data[++heap->Size] = X;
		
		buff = heap->Size;
		parent = buff / 2;

		buffdata = heap->Data[buff].Int;
		parentdata = heap->Data[parent].Int;

		while (parent) {
			if (parentdata > buffdata) {		//��� ���ӽڵ� С�� ��ĸ�ڵ�
				X = heap->Data[parent];
				heap->Data[parent] = heap->Data[buff];
				heap->Data[buff] = X;

				buff = parent;
				parent = buff / 2;
				buffdata = heap->Data[buff].Int;
				parentdata = heap->Data[parent].Int;
			}
		}
		return true;
	}
	else return false;
}

bool MinHeap_Delete(MaxHeap *H, ElemNodeType *X)
{ /* ������H��ȡ����ֵΪ����Ԫ�أ���ɾ��һ����� */
	int Parent, Child;

	if (!Heap_IsEmpty(H)) {
		printf("������Ϊ��");
		return false;
	}

	*X = H->Data[1]; /* ȡ��������ŵ���Сֵ */
	
	/* �����������һ��Ԫ�شӸ���㿪ʼ���Ϲ����²��� */

	H->Data[1] = H->Data[H->Size--]; /* ע�⵱ǰ�ѵĹ�ģҪ��С */

	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && ElemNode_compare(H->Data[Child], H->Data[Child + 1]))
			Child++;  /* Childָ�������ӽ��Ľ�С�� */
		
		if (ElemNode_compare(H->Data[Child], H->Data[Parent])) break; /* �ҵ��˺���λ�� */
		else  /* ����X */
			ElemNode_Swap(&H->Data[Parent] , &H->Data[Child]);
			
	}
	
	return true;
}

void PrefectTree_Print(PrefectTree* PFTree)
{
	if (PFTree) {
		int i = 0;
		for (i = 0; i <= PFTree->Size; i++) {
			int data = Get_IntElemNode(PFTree->Data[i]);
			printf("%d ", data);
		}
		printf("\n");
	}
}