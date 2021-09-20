#include"Date_Struct.h"
#include<stdio.h>

void BinTree_InorderTraversal(BinTree* BT)
{
    if (BT) {
        BinTree_InorderTraversal(BT->Left);
        /* �˴������BT���ķ��ʾ��Ǵ�ӡ���� */
        printf("%d\t", BT->Data); /* ��������Ϊ���� */
        BinTree_InorderTraversal(BT->Right);
    }
}

void BinTree_PreorderTraversal(BinTree* BT)
{
    if (BT) {
        printf("%d\t", BT->Data);
        BinTree_PreorderTraversal(BT->Left);
        BinTree_PreorderTraversal(BT->Right);
    }
}

void BinTree_PostorderTraversal(BinTree* BT)
{
    if (BT) {
        BinTree_PostorderTraversal(BT->Left);
        BinTree_PostorderTraversal(BT->Right);
        printf("%t ", BT->Data);
    }
}

void BinTree_LevelorderTraversal(BinTree* BT)
{
    Queue Q;
    BinTree* T;

    if (!BT) return; /* ���ǿ�����ֱ�ӷ��� */

    Queue_Init(&Q);   /* �����ն���Q */
    Queue_Push(&Q, BT);
    while ( !Queue_Empty(&Q)) {
        T = Queue_Pop(&Q);
        printf("%d ", T->Data); /* ����ȡ�����еĽ�� */
        
        if (T->Left) {
            Queue_Push(&Q, T->Left);
        }
        if (T->Right) {
            Queue_Push(&Q, T->Right);
        }
    }
}


BinTree* BinTree_Find(BinTree* BST, ElementType X)
{

    while (BST) {
        if (BST->Data == X) return BST;
        if (BST->Data < X) {
            BST = BST->Right;
        }
        else {
            BST = BST->Left;
        }
    }
    return NULL;
}


BinTree* BinTree_Insert(BinTree* BST, ElementType X)
{
    if (!BST) { /* ��ԭ��Ϊ�գ����ɲ�����һ�����Ķ��������� */
        BST = (BinTree*)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else { /* ��ʼ��Ҫ����Ԫ�ص�λ�� */
        if (X < BST->Data)
            BST->Left = BinTree_Insert(BST->Left, X);   /*�ݹ����������*/
        else  if (X > BST->Data)
            BST->Right = BinTree_Insert(BST->Right, X); /*�ݹ����������*/
        /* else X�Ѿ����ڣ�ʲô������ */
    }
    return BST;
}

BinTree* BinTree_Delete(BinTree* BST, ElementType X)
{
    BinTree* Tmp;

    if (!BST) {
        //printf("Ҫɾ����Ԫ��δ�ҵ�");
    }else {
        if (X < BST->Data)
            BST->Left = BinTree_Delete(BST->Left, X);   /* ���������ݹ�ɾ�� */
        else if (X > BST->Data)
            BST->Right = BinTree_Delete(BST->Right, X); /* ���������ݹ�ɾ�� */
        else { /* BST����Ҫɾ���Ľ�� */
            /* �����ɾ����������������ӽ�� */
            if (BST->Left && BST->Right) {
                /* ��������������С��Ԫ�����ɾ����� */
                Tmp = FindMin(BST->Right);
                BST->Data = Tmp->Data;
                /* ����������ɾ����СԪ�� */
                BST->Right = BinTree_Delete(BST->Right, BST->Data);
            }
            else { /* ��ɾ�������һ�������ӽ�� */
                Tmp = BST;
                if (!BST->Left)       /* ֻ���Һ��ӻ����ӽ�� */
                    BST = BST->Right;
                else                   /* ֻ������ */
                    BST = BST->Left;
                free(Tmp);
            }
        }
    }
    return BST;
}

BinTree* FindMin(BinTree* BTS)
{
    if (BTS) {
        return FindMin(BTS->Left);
    }
    else {
        return BTS;
    }
}

int BinTree_Hight(BinTree* BTS)
{
    if (BTS != NULL) {
        if (BinTree_Hight(BTS->Left) > BinTree_Hight(BTS->Right)) {
            return BinTree_Hight(BTS->Left) + 1;
        }
        else {
            return BinTree_Hight(BTS->Right) + 1;
        }
    }
    else {
        return 0;
    }
}