#pragma once

#define MaxSize 1000
#define OVERFLAGE '*'

typedef struct HNode PrefectTree; /* 堆的类型定义 */
typedef struct HNode Heap; /* 堆的类型定义 */

struct HNode {
    ElemNodeType Data[MaxSize + 1];    /* 存储元素的数组 */
    int Size;       /* 堆中当前元素个数 */
    int Capacity;   /* 堆的最大容量 */
};
typedef Heap MaxHeap; /* 最大堆 */
typedef Heap MinHeap; /* 最小堆 */

PrefectTree* PrefectTree_Init();
PrefectTree* Heap_Init();
bool Heap_IsFull    (MaxHeap* H);
bool Heap_IsEmpty   (MaxHeap* H);
bool MinHeap_Insert (MaxHeap* heap, ElemNodeType X);
bool MinHeap_Delete (MaxHeap* H, ElemNodeType* X);
void PrefectTree_Print(PrefectTree* PFTree);
//int PrefectTreePrior_Creat(PrefectTree* PreTree);
