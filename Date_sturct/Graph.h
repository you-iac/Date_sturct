#pragma once
#include"Data_Struct.h"


#define MaxAddress 65535
#define MaxVertexNum 100        //��󶥵�����Ϊ100
#define ElemGType char
typedef int Vertex;             //�ö����±��ʾ����,Ϊ����
typedef int WeightType;         //�ߵ�Ȩֵ��Ϊ����
typedef char DataType;          //����洢������������Ϊ�ַ���
typedef bool Direction;

//�ߵĶ���
typedef struct ENode {
    Vertex V1, V2;      /*�����<V1, V2>*/
    WeightType Weight;  //Ȩ�� */
} ENode;

//����ͼ���Ķ���
typedef struct GNode {
    int Nv;         //������
    int Ne;         //����
    WeightType Matrix[MaxVertexNum][MaxVertexNum];  //�ڽӾ���
    ElemGType Data[MaxVertexNum];                   //�涥�������
} MGraph;

MGraph* MGraph_Build(Direction T);                  //����һ������洢��ͼ
MGraph* MGraph_Init   (int VertexNum);              //��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
void MGraph_AddData   (MGraph* graph);              //��Ӷ�������
void MGraph_InsertEdge(MGraph* graph, ENode* E, Direction T);    //��ӱ�
void MGraph_Print     (MGraph* graph);              //���ͼ
void MGraph_BFS       (MGraph* graph);
int  MGraph_Prim(MGraph* Graph, MGraph* MST);
Vertex FindMinDist(int Nv, int Route_plan[2][MaxVertexNum]);
int  Find_Elenment    (MGraph* graph, ElemGType X); 
bool IsEdge(MGraph* Graph, Vertex V, Vertex W);
/*ͼ���ڽӱ��ʾ*/
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode {               //�ڽӵ�Ķ���
    Vertex AdjV;                //�ڽӵ��±�
    WeightType Weight;          //��Ȩ��
    PtrToAdjVNode Next;         //ָ����һ���ڽӵ��ָ��
};
typedef struct Vnode {              //�����ͷ���Ķ���
    DataType Data;                  //�涥�������
    PtrToAdjVNode FirstEdge;        //�߱�ͷָ��
} AdjList[MaxVertexNum];            //AdjList���ڽӱ�����

 typedef struct  {          //ͼ���Ķ���
    int Nv;                 //������
    int Ne;                 //����
    AdjList G;              //�ڽӱ�
} LGraph;

LGraph* LGraph_Build   (Direction T);                     //����һ���ڽӱ�洢��ͼ
LGraph* LGraph_Init    (int VertexNum);            //��ʼ��һ���ޱ߿�ͼ
void LGraph_InsertEdge (LGraph* graph, ENode* E, Direction T);  //�����aW
void LGraph_UW_path    (LGraph* LGraph, int Route_plan[][MaxVertexNum], Vertex S);
void LGraph_HW_path    (LGraph* LGraph, int Route_plan[][MaxVertexNum], Vertex S);