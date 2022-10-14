#pragma once
#include"Data_Struct.h"

/// <summary>
/// 
/// </summary>
/// <param name="T�Ƿ��з���/ture&/false"></param>
/// <returns></returns>
MGraph* MGraph_Build    (Direction T)
{
    MGraph* graph;
    ENode E;        //�����߽��
    int Nv, i;

    scanf_s("%d", &Nv);					//���붥�����
    graph = MGraph_Init(Nv);			//��ʼ����Nv�����ޱߵ�ͼ
    scanf_s("%d", &(graph->Ne));   		//�������
    MGraph_AddData(graph);              //��������
    if (graph->Ne != 0) { 				//����б�
        
        for (i = 0; i < graph->Ne; i++) {
            /* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
            scanf_s("%d %d %d", &E.V1, &E.V2, &E.Weight);
            
            /* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
            MGraph_InsertEdge(graph, &E, T);
        }
    }

    /* ������������ݵĻ����������� */
    return graph;
}
MGraph* MGraph_Init     (int VertexNum)
{
    Vertex V, W;
    MGraph* graph = NULL;

    graph = (MGraph*)malloc(sizeof(struct GNode)); /* ����ͼ */
    if (!graph) return NULL;
    else {
        graph->Nv = VertexNum;
        graph->Ne = 0;
        /* ��ʼ���ڽӾ��� */
        /* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(graph->Nv - 1) */
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
    /* ����� <V1, V2> */
    graph->Matrix[E->V1][E->V2] = E->Weight;
    /* ��������ͼ����Ҫ�����<V2, V1> */
    if (T == false) {
        graph->Matrix[E->V2][E->V1] = E->Weight;
    }
}
void MGraph_BFS   (MGraph* graph)
{   
    Queue* queue = Queue_Init();	//��������
    Vertex flage = 0;   //��ͼ�ĵ�һ��Ԫ�ؿ�ʼ����
    Vertex neighbor = 0;
    Vertex Visited[MaxVertexNum] = { 0 };
    ElemNodeType X;
    int i = 0, j = 0;

    for (j = 0; j < graph->Nv; j++)
    {
        if (Visited[j] != 0) continue;              

        Queue_Push(queue, In_IntElemNode(j));		//һ��BFS�����Ŀ�ʼ�� 
        Visited[j] = 1;

        while (Queue_InEmpty(queue)) {

            Queue_Pop(queue, &X);			//ʹ��X����
            flage = Get_IntElemNode(X);		//ת����int

            printf("%c ", graph->Data[flage]);

            //��ȡ��ǰ������ھӲ��Ҽ��뵽����
            for (i = 0; i < graph->Nv; i++) {
                neighbor = graph->Matrix[flage][i];

                if (neighbor != 0 && Visited[i] == 0) {		//Ҫ���������ӣ�������û�з��ʹ���
                    Queue_Push(queue, In_IntElemNode(i));
                    Visited[i] = 1;						//��¼�ڵ��Ѿ�������
                }
            }
        }
    }
    printf("\n");
}
void MGraph_DFS   (MGraph* graph){
    
    static Vertex Visited[MaxVertexNum] = { 0 };    //��̬�ֲ�����
    Stack* stack = Stack_Init();	                //��������
    Vertex flage = 0;	                            //��ͼ�ĵ�һ��Ԫ�ؿ�ʼ����
    Vertex neighbor = 0;
    ElemNodeType X;

    int i = 0, j = 0;
    for (j = 0; j < graph->Nv; j++)
    {
        if (Visited[j] != 0) continue;

        Stack_Push(stack, In_IntElemNode(j));		//һ��BFS�����Ŀ�ʼ�� 0
        printf("%c ", graph->Data[j]);
        Visited[j] = 1;
        flage = j;

        while (Stack_InEmpty(stack)) {

            for (i = 0; i < graph->Nv; i++)
            {
                if (IsEdge(graph, flage, i) && Visited[i] == 0) {		//Ҫ���������ӣ�������û�з��ʹ���
                    Stack_Push(stack, In_IntElemNode(i));
                    flage = i;                                          //
                    printf("%c ", graph->Data[flage]);
                    Visited[i] = 1;						                //��¼�ڵ�Ϊ�ѷ���
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
{ /* ����δ����¼������dist��С�� */
    Vertex MinV, V, dist = 0;
    WeightType MinDist = MaxAddress;

    for (V = 0; V < Nv; V++) {
        if (Route_plan[dist][V] != 0 && Route_plan[dist][V] < MinDist) {
            //��Vδ����¼����dist[V]Ϊ���ֵ
            MinDist = Route_plan[dist][V]; /* ������С���� */
            MinV = V; /* ���¶�Ӧ���� */
        }
    }
    //���ҵ���Сdist 
    if (MinDist < MaxAddress) {
        return MinV; //���ض�Ӧ�Ķ����±�
    }
    else return -1;  //�������Ķ��㲻���ڣ�����-1��Ϊ���
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
/// <param name="T �Ƿ��з��� ture & false"></param>
/// <returns></returns>
LGraph* LGraph_Build(Direction T){
    LGraph* graph;
    ENode* E = (ENode*)malloc(sizeof(struct ENode));    //�����߽��
    if (!E)return NULL;
    Vertex V;
    int Nv, i;

    scanf_s("%d", &Nv);                                 //���붥�����
    graph = LGraph_Init(Nv);                            //��ʼ����Nv�����㵫û�бߵ�ͼ

    scanf_s("%d", &(graph->Ne));                        //�������
    
    //������������ݵĻ����������� */
    for (V = 0; V < graph->Nv; V++) {
        char X = getchar();
        graph->G[V].Data = getchar();
    }
        
    if (graph->Ne != 0) { //����б� */
        
        //����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
        for (i = 0; i < graph->Ne; i++) {
            scanf_s("%d %d %d", &E->V1, &E->V2, &E->Weight);
            //ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
            LGraph_InsertEdge(graph, E, T);
        }
    }
    return graph;
}
LGraph* LGraph_Init (int VertexNum)
{ //��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
    Vertex V;
    LGraph* graph;

    graph = (LGraph*)malloc(sizeof(struct GNode)); //����ͼ */

    if (graph) {
        graph->Nv = VertexNum;
        graph->Ne = 0;
        //��ʼ���ڽӱ�ͷָ�� */
        //ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(graph->Nv - 1) */
        for (V = 0; V < graph->Nv; V++)
            graph->G[V].FirstEdge = NULL;

        return graph;
    }
    else return NULL;


}
void LGraph_InsertEdge  (LGraph* graph, ENode* E, Direction T)   //����� <V1, V2> */
{
    PtrToAdjVNode NewNode;

    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));//ΪV2�����µ��ڽӵ� */
    if (!NewNode)return NULL;
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    
    NewNode->Next = graph->G[E->V1].FirstEdge;      //��V2����V1�ı�ͷ */
    graph->G[E->V1].FirstEdge = NewNode;

    //��������ͼ����Ҫ����� <V2, V1> */
    
    if (T == false) {
        NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));   //ΪV1�����µ��ڽӵ� */
        if (!NewNode)return NULL;
        NewNode->AdjV = E->V1;
        NewNode->Weight = E->Weight;

        NewNode->Next = graph->G[E->V2].FirstEdge;      //��V1����V2�ı�ͷ */
        graph->G[E->V2].FirstEdge = NewNode;
    }
}
//�ڽӱ�洢 - ��Ȩͼ�ĵ�Դ���·�㷨
void LGraph_UW_path(LGraph* LGraph, int Route_plan[][MaxVertexNum], Vertex S)
{
    int dist = 0, path = 1;
    Queue* Q = NULL;
    Vertex V;
    PtrToAdjVNode W;
    ElemNodeType X;

    Q = Queue_Init(); /* �����ն���, MaxSizeΪ�ⲿ����ĳ��� */
    Route_plan[dist][S] = 0; //��ʼ��Դ��


    Queue_Push(Q, In_IntElemNode(S));       //Դ����

    while (Queue_InEmpty(Q)) {
        Queue_Pop(Q, &X);           //һ�γ������������������ͽ���
        V = Get_IntElemNode(X);
        printf("%c", LGraph->G[V].Data);

        //��V��ÿ���ڽӵ�W->AdjV
        for (W = LGraph->G[V].FirstEdge; W; W = W->Next) {
            if (Route_plan[dist][W->AdjV] == -1) {          //��W->AdjVδ�����ʹ�
                Route_plan[dist][W->AdjV] = Route_plan[dist][V] + 1;//W->AdjV��S�ľ������ */
                Route_plan[path][W->AdjV] = V;                      //��V��¼��S��W->AdjV��·����
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

    //��ʼ��Դͷ
    Route_plan[dist][S] = 0;
    Route_plan[path][S] = -1;
    V = S;

    while (1)
    {
        //������Сdist�Ķ���
        int Min = MaxAddress;
        for (i = 0; i < LGraph->Nv; i++) {
            //������Ѿ���Vist��¼�˵�����
            if (Vist[i] == 0) {
                if (Route_plan[dist][i] < Min) {
                    Min = Route_plan[dist][i];
                    V = i;
                }
            }
        }

        //����ҵ����û���ҵ�˵���Ѿ�ȫ��������    
        if (Min == MaxAddress) break;
        Vist[V] = 1;    //���V Ϊ�Ѽ�¼

        //����V ��ȫ���ɴ�·��
        for (W = LGraph->G[V].FirstEdge; W; W = W->Next) {
            //  ��Դ�� S ���� V ���� �ھӵľ���
            int ThisDist = Route_plan[dist][V] + W->Weight;
            // ����ھ� δ���� ���Ҵ�V �� �ھ�·�����Ѹ�С ������ھӻ�û�п���·�����Ĭ������볤��Ϊ���·�����ȣ�
            if (Vist[W->AdjV] == 0 && Route_plan[dist][W->AdjV] > ThisDist) {
                Route_plan[dist][W->AdjV] = ThisDist;       //�����ھӵľ��뻨��
                Route_plan[path][W->AdjV] = V;              //�����ھӵ�·��
            }
        }
    }
}

int  MGraph_Prim(MGraph* Graph, MGraph* MST)
{ /* ����С����������Ϊ�ڽӱ�洢��ͼMST��������СȨ�غ� */
/*�ҳ� N - 1 ��Ȩֵ��С�ı�,����ķ�㷨��ʵ��˼·�ǣ�
����ͨ���е����ж����Ϊ���ࣨ����Ϊ A ��� B �ࣩ����ʼ״̬�£����ж���λ�� B �ࣻ
ѡ������һ�����㣬����� B ���ƶ��� A �ࣻ
�� B ������ж���������ҳ�һ�������� A ���е�ĳ��������Ȩֵ��С�ıߣ����˱������ŵ� A ���еĶ����ƶ��� B �ࣻ
�ظ�ִ�е� 3  ����ֱ�� B ���е����ж���ȫ���ƶ��� A �࣬ǡ�ÿ����ҵ� N - 1 ���ߡ�*/
    int Route_plan[2][MaxVertexNum], dist = 0, path = 1;
    WeightType TotalWeight;
    Vertex  V, W;

    int VCount;
    ENode E;            /* �����յı߽�� */

    //��ʼ����Ĭ�ϳ�ʼ���±���0 */
    for (V = 0; V < Graph->Nv; V++) {
        /*���������V��Wû��ֱ�ӵıߣ���Graph->G[V][W]����ΪINFINITY */
        if (Graph->Matrix[0][V] == 0) Route_plan[dist][V] = MaxAddress;
        else Route_plan[dist][V] = Graph->Matrix[0][V];
        Route_plan[path][V] = 0; /*���Ҷ������ж���ĸ���㶼�ǳ�ʼ��0*/
    }
    TotalWeight = 0; //��ʼ��Ȩ�غ�
    VCount = 0;      //��ʼ����¼�Ķ�����
    //�����������ж��㵫û�бߵ�ͼ��ע�����ڽӱ�汾

    //����ʼ��0��¼��MST
    Route_plan[dist][0] = 0;
    VCount++;
    Route_plan[path][0] = -1; /* ��ǰ������0 */

    while (1) {
        V = FindMinDist(Graph->Nv, Route_plan);
        //V = δ����¼������dist��С��
        if (V == -1) //��������V������ ˵���Ѿ�û��δ¼���
            break;

        //��V����Ӧ�ı�<path[V], V>��¼��MST
        E.V1 = Route_plan[path][V];
        E.V2 = V;
        E.Weight = Route_plan[dist][V];
        MGraph_InsertEdge(MST, &E, false);
        TotalWeight += Route_plan[dist][V];
        Route_plan[dist][V] = 0;
        VCount++;

        //Ѱ��V���ھ�
        for (W = 0; W < Graph->Nv; W++)
            //��δ����¼
            if (Route_plan[dist][W] != 0 && Graph->Matrix[V][W] != 0) {

                if (Graph->Matrix[V][W] <= Route_plan[dist][W]) {
                    //����¼Vʹ��dist[W]��С ����dist �� path
                    Route_plan[dist][W] = Graph->Matrix[V][W];
                    Route_plan[path][W] = V;
                }
            }
    } /* while����*/
    if (VCount < Graph->Nv) //MST���յĶ��㲻��|V|�� ˵��ͼ�Ƿ���ͨ
        TotalWeight = -1;
    return TotalWeight;   //�㷨ִ����ϣ�������СȨ�غͻ������ */
}


//��Ȩ������ͼ
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

//��Ȩ������ͼ
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