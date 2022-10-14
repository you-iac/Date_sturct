#pragma once

#define ElementTreeType int

typedef struct TNode {				//������
	ElementTreeType Data;
	struct TNode* Left, * Right;		//�ڵ�ָ��
} BinTree;

/*������������������*/
//����������ݹ飩
void BinTree_InorderTraversal(BinTree* BT);		
//ǰ��������ݹ飩
void BinTree_PreorderTraversal(BinTree* BT);		
//����������ݹ飩
void BinTree_PostorderTraversal(BinTree* BT);		
//������������У�
void BinTree_LevelorderTraversal(BinTree* BT);		
//ǰ�������ջ��
void BinTree_PreorderTraversal_ByStack(BinTree* BT);
//���ң��ݹ飩
BinTree* BinTree_Find(BinTree* BST, ElementTreeType X);		
//���루�ݹ飩
BinTree* BinTree_Insert(BinTree* BST, ElementTreeType X);		
//ɾ�����ݹ飩
BinTree* BinTree_Delete(BinTree* BST, ElementTreeType X);		
/// <summary>
/// ��������������Ŀ��ӻ����
/// </summary>
/// <param name="BT = ������ָ��"></param>
void BinTree_visualization(BinTree* BT);
//�ж����ڵ��Ƿ����������Ҳ�
int	 BinTreeNode_IsRight(BinTree* BST, BinTree* Node);

/// <summary>
/// ƽ����������ݲ���  
/// </summary>
/// <param name="BST = ������ָ��"></param>
/// <param name="X = ����Ԫ��"></param>
/// <returns>ƽ�������ָ��</returns>
BinTree* BinTree_BanlaceInsert(BinTree* BST, ElementTreeType X);
//������ת 
BinTree* Single_Left_Rotation(BinTree* BST);		
//������ת 
BinTree* Single_Right_Rotation(BinTree* BST);		
//������ת
BinTree* Double_RightLeft_Rotation(BinTree* BST);	
//������ת
BinTree* Double_LeftRight_Rotation(BinTree* BST);	
//�������ߣ��ݹ飩
int BinTree_Hight(BinTree* BTS);
//����С���ݹ飩
BinTree* FindMin(BinTree* BTS);
/// <summary>
/// ��ǰ���������������
/// </summary>
/// <returns>ƽ�������ָ��</returns>
BinTree* CreatePrior_Tree();

/// <summary>
/// �����������ָ�������
/// </summary>
/// <returns>ƽ�������ָ��</returns>
BinTree* CreateBinTree_By_InandPro();
BinTree* create(char pa[], int low_a, int high_a, char pb[], int low_b, int high_b);