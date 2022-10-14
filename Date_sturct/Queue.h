#pragma once

typedef struct QNode {		//队列
	Node* Front, * Rears;	//节点指针
} Queue;

/*队列操作声明*/
Queue* Queue_Init();
int Queue_InEmpty(Queue* queue);	//，若栈S为空则返回
/// 销毁队列结构
int Queue_Destroy(Queue* queue);
int Queue_Push(Queue* queue, ElemNodeType X);
/// 出队列
int Queue_Pop(Queue* queue, ElemNodeType* X);
/// 获得队列的头元素
int Queue_GetTop(Queue* queue, ElemNodeType* X);	//读队列
/// <summary>
/// 优先队列入队列
/// </summary>
/// <param name="queue = 队列指针"></param>
/// <param name="Type = 优先队列类型 1 按 从小到大， 2 从大到小"></param>
/// <param name="X = 元素类型"></param>
/// <returns>入队操作是否成功</returns>
int Queue_priority_Push(Queue* queue, int Type, ElemNodeType X);
