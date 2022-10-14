#pragma once

#define MaxSize 1000
#define OVERFLAGE '*'

typedef struct HNode PrefectTree; /* �ѵ����Ͷ��� */
typedef struct HNode Heap; /* �ѵ����Ͷ��� */

struct HNode {
    ElemNodeType Data[MaxSize + 1];    /* �洢Ԫ�ص����� */
    int Size;       /* ���е�ǰԪ�ظ��� */
    int Capacity;   /* �ѵ�������� */
};
typedef Heap MaxHeap; /* ���� */
typedef Heap MinHeap; /* ��С�� */

PrefectTree* PrefectTree_Init();
PrefectTree* Heap_Init();
bool Heap_IsFull    (MaxHeap* H);
bool Heap_IsEmpty   (MaxHeap* H);
bool MinHeap_Insert (MaxHeap* heap, ElemNodeType X);
bool MinHeap_Delete (MaxHeap* H, ElemNodeType* X);
void PrefectTree_Print(PrefectTree* PFTree);
//int PrefectTreePrior_Creat(PrefectTree* PreTree);
