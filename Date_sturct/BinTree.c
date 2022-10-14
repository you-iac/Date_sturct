#pragma once
#include"Data_Struct.h"        

void BinTree_InorderTraversal(BinTree* BT)
{
    if (BT) {
        BinTree_InorderTraversal(BT->Left);
        /* 此处假设对BT结点的访问就是打印数据 */
        printf("%d ", BT->Data); /* 假设数据为整型 */
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
    if (!BT) return; /* 若是空树则直接返回 */
    
    Queue_Push(Q, X);
    while ( Queue_InEmpty(Q)) {
        Queue_Pop(Q, &X);
        T = X.Point;
        printf("%d ", T->Data); /* 访问取出队列的结点 */
        
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

void BinTree_visualization(BinTree* BT)//广度优先搜索树的可视化输出
{
    Queue* Q = Queue_Init();
    ElemNodeType X;
    X.Point = BT;
    BinTree* T = NULL;
    if (!BT) return; /* 若是空树则直接返回 */

    Queue_Push(Q, X);
    while (Queue_InEmpty(Q)) {
        //
        Queue_Pop(Q, &X);
        T = X.Point;
        printf("%d ", T->Data); /* 访问取出队列的结点 */

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
//判断树节点是否在树的最右侧
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
/// 返回子树插入后的root
/// </summary>
/// <param name="BST*"></param>
/// <param name="int"></param>
/// <returns></returns>
BinTree* BinTree_Insert(BinTree* BST, ElementTreeType X)
{
    if (!BST) { /* 若原树为空，生成并返回一个结点的二叉搜索树 */
        BST = (BinTree*)malloc(sizeof(struct TNode));
        if (!BST)return NULL;
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else { /* Find Loaction of insert */
        if (X < BST->Data)
            BST->Left = BinTree_Insert(BST->Left, X);   /*递归插入左子树*/
        else  if (X > BST->Data)
            BST->Right = BinTree_Insert(BST->Right, X); /*递归插入右子树*/
        /* else X已经存在，什么都不做 */
    }
    return BST;
}

BinTree* BinTree_Delete(BinTree* BST, ElementTreeType X)
{
    BinTree* Tmp;

    if (!BST) {
        //printf("要删除的元素未找到");
    }else {
        if (X < BST->Data)
            BST->Left = BinTree_Delete(BST->Left, X);   /* 从左子树递归删除 */
        else if (X > BST->Data)
            BST->Right = BinTree_Delete(BST->Right, X); /* 从右子树递归删除 */
        else { /* BST就是要删除的结点 */
            /* 如果被删除结点有左右两个子结点 */
            if (BST->Left && BST->Right) {
                /* 从右子树中找最小的元素填充删除结点 */
                Tmp = FindMin(BST->Right);
                BST->Data = Tmp->Data;
                /* 从右子树中删除最小元素 */
                BST->Right = BinTree_Delete(BST->Right, BST->Data);
            }
            else { /* 被删除结点有一个或无子结点 */
                Tmp = BST;
                if (!BST->Left)       /* 只有右孩子或无子结点 */
                    BST = BST->Right;
                else                   /* 只有左孩子 */
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

        if (hight == 2) {		//左子树的高度 比  右子树 高 2 

            if (X <= BST->Left->Data) {	// RR 旋转
                return Single_Right_Rotation(BST);
            }
            else {		//LR旋转			
                return Double_LeftRight_Rotation(BST);
            }
        }
        else if (hight == -2) {		//左子树的高度 比  右子树 高 -2 

            if (X > BST->Right->Data) {	// LL 旋转
                return Single_Left_Rotation(BST);
            }
            else {		//RL旋转			
                return Double_RightLeft_Rotation(BST);
            }
        }
        else {
            return BST;
        }

    }
    else {		//如果为 NULL 
        BST = (BinTree*)malloc(sizeof(BinTree));
        if (!BST)return NULL;
        BST->Data = X;
        BST->Left = BST->Right = NULL;
        return BST;
    }
}

BinTree* Single_Left_Rotation(BinTree* BST)		//单左旋转 
{
    BinTree* Parent = BST;
    BinTree* Child = BST->Right;

    Parent->Right = Child->Left;
    Child->Left = Parent;
    return Child;
}

BinTree* Single_Right_Rotation(BinTree* BST)		//单右旋转 
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
/*由先序和中序恢复二叉树*/
BinTree* CreateBinTree_By_InandPro()
{
    //读入先序，中序序列，分别存入数组pa，pb 
    int n = 0, i = 0;
    char pa[100] = {0}, pb[100], X = 0;

    X = getchar();
    for (i = 0; i < n; i++) {		//读入pa 
        pa[i] = getchar();
    }

    X = getchar();				//吃回车  

    for (i = 0; i < n; i++) {		//读入pb 
        pb[i] = getchar();
    }
    X = getchar();				//吃回车
    
    return create(pa, 0, n - 1, pb, 0, n - 1);
}
/*由先序和中序恢复二叉树*/
BinTree* create(char pa[], int low_a, int high_a, char pb[], int low_b, int high_b)
{     //创建根结点，递归创建T->lchild,T->rchild
    if (low_b > high_b) {
        return NULL;
    }
    else {
        BinTree* T = (BinTree*)malloc(sizeof(BinTree));
        if (!T) return NULL;        //若T  malloc失败
        int i = 0;
        char This = pa[low_a];
        T->Data = This;

        for (i = low_b; i <= high_b; i++) {			//找这一段序列的根节点
            if (pb[i] == This) {
                break;
            }
        }
        int Len1 = i - low_b, Len2 = high_b - i;	//根据根节点计算左节点数 和 边 节点数

        T->Left  = create(pa, low_a + 1, low_a + Len1, pb, low_b, low_b + Len1 - 1);
        T->Right = create(pa, low_a + Len1 + 1, low_a + Len1 + Len2, pb, i + 1, i + Len2);
        return T;
    }
}