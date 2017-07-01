//KUPT Week9 'Balanced Tree Check(two types)'

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef int Element;


typedef struct BinaryTreeType
{
	Element data;
	struct BinaryTreeType* left;
	struct BinaryTreeType* right;
}BTree;

BTree* CreateTree(Element dataInput)
{
	BTree* rTree = NULL;
	rTree = (BTree*)malloc(sizeof(BTree));
	rTree->data = dataInput;
	rTree->right = NULL;
	rTree->left = NULL;

	return rTree;
}


int height(BTree* pTree)
{
	if (pTree == NULL)
	{
		return 0;
	}

	int Left_height = height(pTree->left);
	int Right_height = height(pTree->right);

	if (Left_height > Right_height)
		return Left_height + 1;
	else
		return Right_height + 1;
}


bool balanced_check_type1(BTree* pTree)
{
	if (pTree == NULL)
		return true;

	int Left_height = height(pTree->left);
	int Right_height = height(pTree->right);
	
	if (Left_height > Right_height)
	{
		if (Left_height - Right_height > 1)
			return false;
	}
	else
	{
		if (Right_height - Left_height > 1)
			return false;
	}

	return balanced_check_type1(pTree->left) || balanced_check_type1(pTree->right);
}


int balanced_check_type2(BTree* pTree)
{
	if (pTree == NULL)
		return 0;
	int Left = balanced_check_type2(pTree->left);
	int Right = balanced_check_type2(pTree->right);
	
	if (Left < 0 || Right < 0)
		return -1;
	if (Left > Right)
	{
		if (Left - Right > 1)
			return -1;
		else
			return Left + 1;
	}
	else
	{
		if (Right - Left > 1)
			return -1;
		else
			return Right + 1;
	}
}


int main()
{
	return 0;
}