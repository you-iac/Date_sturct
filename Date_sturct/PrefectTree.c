#include"Data_Struct.h"

PrefectTree* PrefectTree_Init()
{
	PrefectTree* PFTree = (PrefectTree*)malloc(sizeof(PrefectTree));
	if (!PFTree) return NULL;
	
	PFTree->Data[0] = In_IntElemNode(-1);//哨兵节点
	PFTree->Size = 0;					//完全二叉树的大小
	PFTree->Capacity = MaxSize;			//最大容量

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
			if (parentdata > buffdata) {		//如果 孩子节点 小于 父母节点
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
{ /* 从最大堆H中取出键值为最大的元素，并删除一个结点 */
	int Parent, Child;

	if (!Heap_IsEmpty(H)) {
		printf("最大堆已为空");
		return false;
	}

	*X = H->Data[1]; /* 取出根结点存放的最小值 */
	
	/* 用最大堆中最后一个元素从根结点开始向上过滤下层结点 */

	H->Data[1] = H->Data[H->Size--]; /* 注意当前堆的规模要减小 */

	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && ElemNode_compare(H->Data[Child], H->Data[Child + 1]))
			Child++;  /* Child指向左右子结点的较小者 */
		
		if (ElemNode_compare(H->Data[Child], H->Data[Parent])) break; /* 找到了合适位置 */
		else  /* 下滤X */
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