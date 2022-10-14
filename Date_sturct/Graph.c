#pragma once
#include"Data_Struct.h"

/// <summary>
/// 
/// </summary>
/// <param name="T是否有方向/ture&/false"></param>
/// <returns></returns>
MGraph* MGraph_Build    (Direction T)
{
    MGraph* graph;
    ENode E;        //建立边结点
    int Nv, i;

    scanf_s("%d", &Nv);					//读入顶点个数
    graph = MGraph_Init(Nv);			//初始化有Nv个顶无边的图
    scanf_s("%d", &(graph->Ne));   		//读入边数
    MGraph_AddData(graph);              //读入数据
    if (graph->Ne != 0) { 				//如果有边
        
        for (i = 0; i < graph->Ne; i++) {
            /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
            scanf_s("%d %d %d", &E.V1, &E.V2, &E.Weight);
            
            /* 注意：如果权重不是整型，Weight的读入格式要改 */
            MGraph_InsertEdge(graph, &E, T);
        }
    }

    /* 如果顶点有数据的话，读入数据 */
    return graph;
}
MGraph* MGraph_Init     (int VertexNum)
{
    Vertex V, W;
    MGraph* graph = NULL;

    graph = (MGraph*)malloc(sizeof(struct GNode)); /* 建立图 */
    if (!graph) return NULL;
    else {
        graph->Nv = VertexNum;
        graph->Ne = 0;
        /* 初始化邻接矩阵 */
        /* 注意：这里默认顶点编号从0开始，到(graph->Nv - 1) */
        for (V = 0; V < graph->Nv; V++)
            for (W = 0; W < graph->Nv; W++)
                graph->Matrix[V][W] = 0;

        return graph;
    }

}
void MGraph_AddData     (MGraph* graph)
{
    if (graph) {
        int i = 0;
        ElemGType* P = graph->Data;
        for (i = 0; i < graph->Nv; i++) {
        
            do {

                P[i] = getchar();

            } while (P[i] == '\n');
        
        }
    }


}
void MGraph_InsertEdge  (MGraph* graph, ENode* E, Direction T)
{
    /* 插入边 <V1, V2> */
    graph->Matrix[E->V1][E->V2] = E->Weight;
    /* 若是无向图，还要插入边<V2, V1> */
    if (T == false) {
        graph->Matrix[E->V2][E->V1] = E->Weight;
    }
}
void MGraph_BFS   (MGraph* graph)
{   
    Queue* queue = Queue_Init();	//创建队列
    Vertex flage = 0;   //从图的第一个元素开始遍历
    Vertex neighbor = 0;
    Vertex Visited[MaxVertexNum] = { 0 };
    ElemNodeType X;
    int i = 0, j = 0;

    for (j = 0; j < graph->Nv; j++)
    {
        if (Visited[j] != 0) continue;              

        Queue_Push(queue, In_IntElemNode(j));		//一次BFS遍历的开始处 
        Visited[j] = 1;

        while (Queue_InEmpty(queue)) {

            Queue_Pop(queue, &X);			//使用X接受
            flage = Get_IntElemNode(X);		//转换成int

            printf("%c ", graph->Data[flage]);

            //获取当前顶点的邻居并且加入到队列
            for (i = 0; i < graph->Nv; i++) {
                neighbor = graph->Matrix[flage][i];

                if (neighbor != 0 && Visited[i] == 0) {		//要求是有连接，而且是没有访问过的
                    Queue_Push(queue, In_IntElemNode(i));
                    Visited[i] = 1;						//记录节点已经访问了
                }
            }
        }
    }
    printf("\n");
}
void MGraph_DFS   (MGraph* graph){
    
    static Vertex Visited[MaxVertexNum] = { 0 };    //静态局部变量
    Stack* stack = Stack_Init();	                //创建队列
    Vertex flage = 0;	                            //从图的第一个元素开始遍历
    Vertex neighbor = 0;
    ElemNodeType X;

    int i = 0, j = 0;
    for (j = 0; j < graph->Nv; j++)
    {
        if (Visited[j] != 0) continue;

        Stack_Push(stack, In_IntElemNode(j));		//一次BFS遍历的开始处 0
        printf("%c ", graph->Data[j]);
        Visited[j] = 1;
        flage = j;

        while (Stack_InEmpty(stack)) {

            for (i = 0; i < graph->Nv; i++)
            {
                if (IsEdge(graph, flage, i) && Visited[i] == 0) {		//要求是有连接，而且是没有访问过的
                    Stack_Push(stack, In_IntElemNode(i));
                    flage = i;                                          //
                    printf("%c ", graph->Data[flage]);
                    Visited[i] = 1;						                //记录节点为已访问
                    break;
                }
            }
            if (i == graph->Nv) {
                Stack_Pop(stack, &X);
                Stack_GetTop(stack, &X);
                flage = Get_IntElemNode(X);
            }
        }
    }
}
void MGraph_Print (MGraph* graph)
{
    int i = 0, j = 0;
    for (i = 0; i < graph->Nv; i++) {
        for (j = 0; j < graph->Nv; j++) {
            printf("%d ", graph->Matrix[i][j]);
        }
        printf("\n");
    }
}
Vertex FindMinDist(int Nv, int Route_plan[2][MaxVertexNum])
{ /* 返回未被收录顶点中dist最小者 */
    Vertex MinV, V, dist = 0;
    WeightType MinDist = MaxAddress;

    for (V = 0; V < Nv; V++) {
        if (Route_plan[dist][V] != 0 && Route_plan[dist][V] < MinDist) {
            //若V未被收录，且dist[V]为最大值
            MinDist = Route_plan[dist][V]; /* 更新最小距离 */
            MinV = V; /* 更新对应顶点 */
        }
    }
    //若找到最小dist 
    if (MinDist < MaxAddress) {
        return MinV; //返回对应的顶点下标
    }
    else return -1;  //若这样的顶点不存在，返回-1作为标记
}
int  Find_Elenment(MGraph* graph, ElemGType X)
{
    ElemGType* P = graph->Data;
    int i = 0;
    for (i = 0; i < graph->Nv; i++) {
        if (P[i] == X) return i;
    }
    return -1;
}
bool IsEdge       (MGraph* Graph, Vertex V, Vertex W){
    return Graph->Matrix[V][W] != 0 ? true : false;
}

/// <summary>
/// 
/// </summary>
/// <param name="T 是否有方向 ture & false"></param>
/// <returns></returns>
LGraph* LGraph_Build(Direction T){
    LGraph* graph;
    ENode* E = (ENode*)malloc(sizeof(struct ENode));    //建立边结点
    if (!E)return NULL;
    Vertex V;
    int Nv, i;

    scanf_s("%d", &Nv);                                 //读入顶点个数
    graph = LGraph_Init(Nv);                            //初始化有Nv个顶点但没有边的图

    scanf_s("%d", &(graph->Ne));                        //读入边数
    
    //如果顶点有数据的话，读入数据 */
    for (V = 0; V < graph->Nv; V++) {
        char X = getchar();
        graph->G[V].Data = getchar();
    }
        
    if (graph->Ne != 0) { //如果有边 */
        
        //读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
        for (i = 0; i < graph->Ne; i++) {
            scanf_s("%d %d %d", &E->V1, &E->V2, &E->Weight);
            //注意：如果权重不是整型，Weight的读入格式要改 */
            LGraph_InsertEdge(graph, E, T);
        }
    }
    return graph;
}
LGraph* LGraph_Init (int VertexNum)
{ //初始化一个有VertexNum个顶点但没有边的图 */
    Vertex V;
    LGraph* graph;

    graph = (LGraph*)malloc(sizeof(struct GNode)); //建立图 */

    if (graph) {
        graph->Nv = VertexNum;
        graph->Ne = 0;
        //初始化邻接表头指针 */
        //注意：这里默认顶点编号从0开始，到(graph->Nv - 1) */
        for (V = 0; V < graph->Nv; V++)
            graph->G[V].FirstEdge = NULL;

        return graph;
    }
    else return NULL;


}
void LGraph_InsertEdge  (LGraph* graph, ENode* E, Direction T)   //插入边 <V1, V2> */
{
    PtrToAdjVNode NewNode;

    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));//为V2建立新的邻接点 */
    if (!NewNode)return NULL;
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    
    NewNode->Next = graph->G[E->V1].FirstEdge;      //将V2插入V1的表头 */
    graph->G[E->V1].FirstEdge = NewNode;

    //若是无向图，还要插入边 <V2, V1> */
    
    if (T == false) {
        NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));   //为V1建立新的邻接点 */
        if (!NewNode)return NULL;
        NewNode->AdjV = E->V1;
        NewNode->Weight = E->Weight;

        NewNode->Next = graph->G[E->V2].FirstEdge;      //将V1插入V2的表头 */
        graph->G[E->V2].FirstEdge = NewNode;
    }
}
//邻接表存储 - 无权图的单源最短路算法
void LGraph_UW_path(LGraph* LGraph, int Route_plan[][MaxVertexNum], Vertex S)
{
    int dist = 0, path = 1;
    Queue* Q = NULL;
    Vertex V;
    PtrToAdjVNode W;
    ElemNodeType X;

    Q = Queue_Init(); /* 创建空队列, MaxSize为外部定义的常数 */
    Route_plan[dist][S] = 0; //初始化源点


    Queue_Push(Q, In_IntElemNode(S));       //源顶点

    while (Queue_InEmpty(Q)) {
        Queue_Pop(Q, &X);           //一次出队列用联合数据类型接收
        V = Get_IntElemNode(X);
        printf("%c", LGraph->G[V].Data);

        //对V的每个邻接点W->AdjV
        for (W = LGraph->G[V].FirstEdge; W; W = W->Next) {
            if (Route_plan[dist][W->AdjV] == -1) {          //若W->AdjV未被访问过
                Route_plan[dist][W->AdjV] = Route_plan[dist][V] + 1;//W->AdjV到S的距离更新 */
                Route_plan[path][W->AdjV] = V;                      //将V记录在S到W->AdjV的路径上
                Queue_Push(Q, In_IntElemNode(W->AdjV));
            }
        }
    }
}
void LGraph_HW_path(LGraph* LGraph, int Route_plan[][MaxVertexNum], Vertex S)
{
    int dist = 0, path = 1;
    Vertex V;
    PtrToAdjVNode W;
    ElemNodeType X;
    Vertex Vist[MaxVertexNum] = { 0 };
    int i = 0;
    for (i = 0; i < MaxVertexNum; i++) {
        Route_plan[dist][i] = MaxAddress;
        Route_plan[path][i] = -1;
    }

    //初始化源头
    Route_plan[dist][S] = 0;
    Route_plan[path][S] = -1;
    V = S;

    while (1)
    {
        //发现最小dist的顶点
        int Min = MaxAddress;
        for (i = 0; i < LGraph->Nv; i++) {
            //如果是已经被Vist记录了的跳过
            if (Vist[i] == 0) {
                if (Route_plan[dist][i] < Min) {
                    Min = Route_plan[dist][i];
                    V = i;
                }
            }
        }

        //如果找到最后都没有找到说明已经全部找完了    
        if (Min == MaxAddress) break;
        Vist[V] = 1;    //标记V 为已记录

        //对于V 的全部可达路径
        for (W = LGraph->G[V].FirstEdge; W; W = W->Next) {
            //  从源点 S 经过 V 到达 邻居的距离
            int ThisDist = Route_plan[dist][V] + W->Weight;
            // 如果邻居 未访问 并且从V 到 邻居路径花费更小 （如果邻居还没有可行路径到达，默认其距离长度为最大路径长度）
            if (Vist[W->AdjV] == 0 && Route_plan[dist][W->AdjV] > ThisDist) {
                Route_plan[dist][W->AdjV] = ThisDist;       //更新邻居的距离花费
                Route_plan[path][W->AdjV] = V;              //更新邻居的路径
            }
        }
    }
}

int  MGraph_Prim(MGraph* Graph, MGraph* MST)
{ /* 将最小生成树保存为邻接表存储的图MST，返回最小权重和 */
/*找出 N - 1 条权值最小的边,普里姆算法的实现思路是：
将连通网中的所有顶点分为两类（假设为 A 类和 B 类）。初始状态下，所有顶点位于 B 类；
选择任意一个顶点，将其从 B 类移动到 A 类；
从 B 类的所有顶点出发，找出一条连接着 A 类中的某个顶点且权值最小的边，将此边连接着的 A 类中的顶点移动到 B 类；
重复执行第 3  步，直至 B 类中的所有顶点全部移动到 A 类，恰好可以找到 N - 1 条边。*/
    int Route_plan[2][MaxVertexNum], dist = 0, path = 1;
    WeightType TotalWeight;
    Vertex  V, W;

    int VCount;
    ENode E;            /* 建立空的边结点 */

    //初始化。默认初始点下标是0 */
    for (V = 0; V < Graph->Nv; V++) {
        /*这里假设若V到W没有直接的边，则Graph->G[V][W]定义为INFINITY */
        if (Graph->Matrix[0][V] == 0) Route_plan[dist][V] = MaxAddress;
        else Route_plan[dist][V] = Graph->Matrix[0][V];
        Route_plan[path][V] = 0; /*暂且定义所有顶点的父结点都是初始点0*/
    }
    TotalWeight = 0; //初始化权重和
    VCount = 0;      //初始化收录的顶点数
    //创建包含所有顶点但没有边的图。注意用邻接表版本

    //将初始点0收录进MST
    Route_plan[dist][0] = 0;
    VCount++;
    Route_plan[path][0] = -1; /* 当前树根是0 */

    while (1) {
        V = FindMinDist(Graph->Nv, Route_plan);
        //V = 未被收录顶点中dist最小者
        if (V == -1) //若这样的V不存在 说明已经没有未录入的
            break;

        //将V及相应的边<path[V], V>收录进MST
        E.V1 = Route_plan[path][V];
        E.V2 = V;
        E.Weight = Route_plan[dist][V];
        MGraph_InsertEdge(MST, &E, false);
        TotalWeight += Route_plan[dist][V];
        Route_plan[dist][V] = 0;
        VCount++;

        //寻找V的邻居
        for (W = 0; W < Graph->Nv; W++)
            //且未被收录
            if (Route_plan[dist][W] != 0 && Graph->Matrix[V][W] != 0) {

                if (Graph->Matrix[V][W] <= Route_plan[dist][W]) {
                    //若收录V使得dist[W]变小 更新dist 和 path
                    Route_plan[dist][W] = Graph->Matrix[V][W];
                    Route_plan[path][W] = V;
                }
            }
    } /* while结束*/
    if (VCount < Graph->Nv) //MST中收的顶点不到|V|个 说明图是非联通
        TotalWeight = -1;
    return TotalWeight;   //算法执行完毕，返回最小权重和或错误标记 */
}


//无权重有向图
/*
10 13
0
1
2
3
4
5
6
7
8
9
0 1 1
0 2 1
0 3 1
2 5 1
3 2 1
3 4 1
4 8 1
5 6 1
6 1 1
8 7 1
8 9 1
9 6 1
8 5 1

*/

//有权重有向图
/*
10 13
0
1
2
3
4
5
6
7
8
9
0 1 1
0 2 2
0 3 3
2 5 2
3 2 2
3 4 3
4 8 2
5 6 3
6 1 4
8 7 5
8 9 4
9 6 8
8 5 3 
4 5 6

*/