#pragma once
#include"Data_Struct.h"


#define MaxAddress 65535
#define MaxVertexNum 100        //最大顶点数设为100
#define ElemGType char
typedef int Vertex;             //用顶点下标表示顶点,为整型
typedef int WeightType;         //边的权值设为整型
typedef char DataType;          //顶点存储的数据类型设为字符型
typedef bool Direction;

//边的定义
typedef struct ENode {
    Vertex V1, V2;      /*有向边<V1, V2>*/
    WeightType Weight;  //权重 */
} ENode;

//矩阵图结点的定义
typedef struct GNode {
    int Nv;         //顶点数
    int Ne;         //边数
    WeightType Matrix[MaxVertexNum][MaxVertexNum];  //邻接矩阵
    ElemGType Data[MaxVertexNum];                   //存顶点的数据
} MGraph;

MGraph* MGraph_Build(Direction T);                  //构建一个矩阵存储的图
MGraph* MGraph_Init   (int VertexNum);              //初始化一个有VertexNum个顶点但没有边的图
void MGraph_AddData   (MGraph* graph);              //添加顶点数据
void MGraph_InsertEdge(MGraph* graph, ENode* E, Direction T);    //添加边
void MGraph_Print     (MGraph* graph);              //输出图
void MGraph_BFS       (MGraph* graph);
int  MGraph_Prim(MGraph* Graph, MGraph* MST);
Vertex FindMinDist(int Nv, int Route_plan[2][MaxVertexNum]);
int  Find_Elenment    (MGraph* graph, ElemGType X); 
bool IsEdge(MGraph* Graph, Vertex V, Vertex W);
/*图的邻接表表示*/
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode {               //邻接点的定义
    Vertex AdjV;                //邻接点下标
    WeightType Weight;          //边权重
    PtrToAdjVNode Next;         //指向下一个邻接点的指针
};
typedef struct Vnode {              //顶点表头结点的定义
    DataType Data;                  //存顶点的数据
    PtrToAdjVNode FirstEdge;        //边表头指针
} AdjList[MaxVertexNum];            //AdjList是邻接表类型

 typedef struct  {          //图结点的定义
    int Nv;                 //顶点数
    int Ne;                 //边数
    AdjList G;              //邻接表
} LGraph;

LGraph* LGraph_Build   (Direction T);                     //构建一个邻接表存储的图
LGraph* LGraph_Init    (int VertexNum);            //初始化一个无边空图
void LGraph_InsertEdge (LGraph* graph, ENode* E, Direction T);  //插入边aW
void LGraph_UW_path    (LGraph* LGraph, int Route_plan[][MaxVertexNum], Vertex S);
void LGraph_HW_path    (LGraph* LGraph, int Route_plan[][MaxVertexNum], Vertex S);