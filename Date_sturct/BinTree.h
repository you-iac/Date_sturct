#pragma once

#define ElementTreeType int

typedef struct TNode {				//二叉树
	ElementTreeType Data;
	struct TNode* Left, * Right;		//节点指针
} BinTree;

/*二叉树基本操作声明*/
//中序遍历（递归）
void BinTree_InorderTraversal(BinTree* BT);		
//前序遍历（递归）
void BinTree_PreorderTraversal(BinTree* BT);		
//后序遍历（递归）
void BinTree_PostorderTraversal(BinTree* BT);		
//层序遍历（队列）
void BinTree_LevelorderTraversal(BinTree* BT);		
//前序遍历（栈）
void BinTree_PreorderTraversal_ByStack(BinTree* BT);
//查找（递归）
BinTree* BinTree_Find(BinTree* BST, ElementTreeType X);		
//插入（递归）
BinTree* BinTree_Insert(BinTree* BST, ElementTreeType X);		
//删除（递归）
BinTree* BinTree_Delete(BinTree* BST, ElementTreeType X);		
/// <summary>
/// 广度优先搜索树的可视化输出
/// </summary>
/// <param name="BT = 二叉树指针"></param>
void BinTree_visualization(BinTree* BT);
//判断树节点是否在树的最右侧
int	 BinTreeNode_IsRight(BinTree* BST, BinTree* Node);

/// <summary>
/// 平衡二叉树数据插入  
/// </summary>
/// <param name="BST = 二叉树指针"></param>
/// <param name="X = 数据元素"></param>
/// <returns>平衡二叉树指针</returns>
BinTree* BinTree_BanlaceInsert(BinTree* BST, ElementTreeType X);
//单左旋转 
BinTree* Single_Left_Rotation(BinTree* BST);		
//单右旋转 
BinTree* Single_Right_Rotation(BinTree* BST);		
//右左旋转
BinTree* Double_RightLeft_Rotation(BinTree* BST);	
//左右旋转
BinTree* Double_LeftRight_Rotation(BinTree* BST);	
//计算树高（递归）
int BinTree_Hight(BinTree* BTS);
//找最小（递归）
BinTree* FindMin(BinTree* BTS);
/// <summary>
/// 据前序遍历创建二叉树
/// </summary>
/// <returns>平衡二叉树指针</returns>
BinTree* CreatePrior_Tree();

/// <summary>
/// 由中序和先序恢复二叉树
/// </summary>
/// <returns>平衡二叉树指针</returns>
BinTree* CreateBinTree_By_InandPro();
BinTree* create(char pa[], int low_a, int high_a, char pb[], int low_b, int high_b);