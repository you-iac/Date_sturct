#include"Date_Struct.h"
#include<stdio.h>

void BinTree_InorderTraversal(BinTree* BT)
{
    if (BT) {
        BinTree_InorderTraversal(BT->Left);
        /* 此处假设对BT结点的访问就是打印数据 */
        printf("%d\t", BT->Data); /* 假设数据为整型 */
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

    if (!BT) return; /* 若是空树则直接返回 */

    Queue_Init(&Q);   /* 创建空队列Q */
    Queue_Push(&Q, BT);
    while ( !Queue_Empty(&Q)) {
        T = Queue_Pop(&Q);
        printf("%d ", T->Data); /* 访问取出队列的结点 */
        
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
    if (!BST) { /* 若原树为空，生成并返回一个结点的二叉搜索树 */
        BST = (BinTree*)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else { /* 开始找要插入元素的位置 */
        if (X < BST->Data)
            BST->Left = BinTree_Insert(BST->Left, X);   /*递归插入左子树*/
        else  if (X > BST->Data)
            BST->Right = BinTree_Insert(BST->Right, X); /*递归插入右子树*/
        /* else X已经存在，什么都不做 */
    }
    return BST;
}

BinTree* BinTree_Delete(BinTree* BST, ElementType X)
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