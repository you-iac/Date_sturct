#pragma once
#include"Data_Struct.h"        

void BinTree_InorderTraversal(BinTree* BT)
{
    if (BT) {
        BinTree_InorderTraversal(BT->Left);
        /* �˴������BT���ķ��ʾ��Ǵ�ӡ���� */
        printf("%d ", BT->Data); /* ��������Ϊ���� */
        BinTree_InorderTraversal(BT->Right);
    }
}

void BinTree_PreorderTraversal(BinTree* BT)
{
    if (BT) {
        printf("%d ", BT->Data);
        BinTree_PreorderTraversal(BT->Left);
        BinTree_PreorderTraversal(BT->Right);
    }
}

void BinTree_PostorderTraversal(BinTree* BT)
{
    if (BT) {
        BinTree_PostorderTraversal(BT->Left);
        BinTree_PostorderTraversal(BT->Right);
        printf("%d ", BT->Data);
    }
}

void BinTree_LevelorderTraversal(BinTree* BT)
{
    Queue* Q = Queue_Init();
    ElemNodeType X; X.Point = BT;
    BinTree* T = NULL;
    if (!BT) return; /* ���ǿ�����ֱ�ӷ��� */
    
    Queue_Push(Q, X);
    while ( Queue_InEmpty(Q)) {
        Queue_Pop(Q, &X);
        T = X.Point;
        printf("%d ", T->Data); /* ����ȡ�����еĽ�� */
        
        if (T->Left) {
            X.Point = T->Left;
            Queue_Push(Q, X);
        }
        if (T->Right) {
            X.Point = T->Right;
            Queue_Push(Q, X);
        }
    }
}

void BinTree_PreorderTraversal_ByStack(BinTree* BT)
{
    Stack* stack = Stack_Init();
    ElemNodeType X; X.Point = BT;
    BinTree* T = NULL;

    if (!BT) return;
    Stack_Push(stack, X);

    while ( Stack_InEmpty(stack) ) {
        Stack_Pop(stack, &X);
        T = X.Point;
        printf("%d ", T->Data);

        if (T->Right) {
            X.Point = T->Right;
            Stack_Push(stack, X);
        }
        if (T->Left) {
            X.Point = T->Left;
            Stack_Push(stack, X);
        }
    }
}

void BinTree_visualization(BinTree* BT)//��������������Ŀ��ӻ����
{
    Queue* Q = Queue_Init();
    ElemNodeType X;
    X.Point = BT;
    BinTree* T = NULL;
    if (!BT) return; /* ���ǿ�����ֱ�ӷ��� */

    Queue_Push(Q, X);
    while (Queue_InEmpty(Q)) {
        //
        Queue_Pop(Q, &X);
        T = X.Point;
        printf("%d ", T->Data); /* ����ȡ�����еĽ�� */

        if (BinTreeNode_IsRight(BT, T)) printf("\n");

        if (T->Left) {
            X.Point = T->Left;
            Queue_Push(Q, X);
        }
        if (T->Right) {
            X.Point = T->Right;
            Queue_Push(Q, X);
        }
    }
}
//�ж����ڵ��Ƿ����������Ҳ�
int BinTreeNode_IsRight(BinTree* BST, BinTree* Node)
{
    while (BST) {
        if (BST == Node) {
            return 1;
        }
        else {
            BST = BST->Right;
        }
    }
    return 0;
}

BinTree* BinTree_Find(BinTree* BST, ElementTreeType X)
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


/// <summary>
/// ��������������root
/// </summary>
/// <param name="BST*"></param>
/// <param name="int"></param>
/// <returns></returns>
BinTree* BinTree_Insert(BinTree* BST, ElementTreeType X)
{
    if (!BST) { /* ��ԭ��Ϊ�գ����ɲ�����һ�����Ķ��������� */
        BST = (BinTree*)malloc(sizeof(struct TNode));
        if (!BST)return NULL;
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else { /* Find Loaction of insert */
        if (X < BST->Data)
            BST->Left = BinTree_Insert(BST->Left, X);   /*�ݹ����������*/
        else  if (X > BST->Data)
            BST->Right = BinTree_Insert(BST->Right, X); /*�ݹ����������*/
        /* else X�Ѿ����ڣ�ʲô������ */
    }
    return BST;
}

BinTree* BinTree_Delete(BinTree* BST, ElementTreeType X)
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

BinTree* BinTree_BanlaceInsert(BinTree* BST, ElementTreeType X)
{
    if (BST) {

        if (X <= BST->Data) {
            BST->Left = BinTree_BanlaceInsert(BST->Left, X);
        }
        else {
            BST->Right = BinTree_BanlaceInsert(BST->Right, X);
        }

        int hight = BinTree_Hight(BST->Left) - BinTree_Hight(BST->Right);

        if (hight == 2) {		//�������ĸ߶� ��  ������ �� 2 

            if (X <= BST->Left->Data) {	// RR ��ת
                return Single_Right_Rotation(BST);
            }
            else {		//LR��ת			
                return Double_LeftRight_Rotation(BST);
            }
        }
        else if (hight == -2) {		//�������ĸ߶� ��  ������ �� -2 

            if (X > BST->Right->Data) {	// LL ��ת
                return Single_Left_Rotation(BST);
            }
            else {		//RL��ת			
                return Double_RightLeft_Rotation(BST);
            }
        }
        else {
            return BST;
        }

    }
    else {		//���Ϊ NULL 
        BST = (BinTree*)malloc(sizeof(BinTree));
        if (!BST)return NULL;
        BST->Data = X;
        BST->Left = BST->Right = NULL;
        return BST;
    }
}

BinTree* Single_Left_Rotation(BinTree* BST)		//������ת 
{
    BinTree* Parent = BST;
    BinTree* Child = BST->Right;

    Parent->Right = Child->Left;
    Child->Left = Parent;
    return Child;
}

BinTree* Single_Right_Rotation(BinTree* BST)		//������ת 
{
    BinTree* Parent = BST;
    BinTree* Child = BST->Left;

    Parent->Left = Child->Right;
    Child->Right = Parent;
    return Child;
}

BinTree* Double_RightLeft_Rotation(BinTree* BST)	//
{
    BST->Right = Single_Right_Rotation(BST->Right);

    return Single_Left_Rotation(BST);
}

BinTree* Double_LeftRight_Rotation(BinTree* BST)
{
    BST->Left = Single_Left_Rotation(BST->Left);

    return Single_Right_Rotation(BST);
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
        int Left = BinTree_Hight(BTS->Left);
        int Right = BinTree_Hight(BTS->Right);

        if (Left > Right) {
            return Left + 1;
        }
        else {
            return Right + 1;
        }
    }
    else {
        return 0;
    }
}

BinTree* CreatePrior_Tree()
{
    char X = getchar();

    if (X != '*') {
        BinTree* tree = (BinTree*)malloc(sizeof(BinTree));
        if (!tree)return NULL;
        tree->Data = X;
        tree->Left = CreatePrior_Tree();
        tree->Right = CreatePrior_Tree();
        return tree;
    }
    else {
        return NULL;
    }

}
/*�����������ָ�������*/
BinTree* CreateBinTree_By_InandPro()
{
    //���������������У��ֱ��������pa��pb 
    int n = 0, i = 0;
    char pa[100] = {0}, pb[100], X = 0;

    X = getchar();
    for (i = 0; i < n; i++) {		//����pa 
        pa[i] = getchar();
    }

    X = getchar();				//�Իس�  

    for (i = 0; i < n; i++) {		//����pb 
        pb[i] = getchar();
    }
    X = getchar();				//�Իس�
    
    return create(pa, 0, n - 1, pb, 0, n - 1);
}
/*�����������ָ�������*/
BinTree* create(char pa[], int low_a, int high_a, char pb[], int low_b, int high_b)
{     //��������㣬�ݹ鴴��T->lchild,T->rchild
    if (low_b > high_b) {
        return NULL;
    }
    else {
        BinTree* T = (BinTree*)malloc(sizeof(BinTree));
        if (!T) return NULL;        //��T  mallocʧ��
        int i = 0;
        char This = pa[low_a];
        T->Data = This;

        for (i = low_b; i <= high_b; i++) {			//����һ�����еĸ��ڵ�
            if (pb[i] == This) {
                break;
            }
        }
        int Len1 = i - low_b, Len2 = high_b - i;	//���ݸ��ڵ������ڵ��� �� �� �ڵ���

        T->Left  = create(pa, low_a + 1, low_a + Len1, pb, low_b, low_b + Len1 - 1);
        T->Right = create(pa, low_a + Len1 + 1, low_a + Len1 + Len2, pb, i + 1, i + Len2);
        return T;
    }
}