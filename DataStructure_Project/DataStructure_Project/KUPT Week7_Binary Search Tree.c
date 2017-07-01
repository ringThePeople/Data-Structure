//KUPT Week7 'Binary Search Tree'

#include <stdlib.h>
#include <stdio.h>

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

BTree* BST(BTree* root, Element dataInput)	//return top root;
{
	BTree* pTree = NULL;
	pTree = root;
	if (pTree == NULL)
	{
		pTree = CreateTree(dataInput);
		return pTree;
	}
	if (pTree->data > dataInput)
	{
		pTree->left = BST(pTree->left, dataInput);
	}
	else
	{
		pTree->right = BST(pTree->right, dataInput);
	}

	return root;
	
}
int main()
{
	BTree* root = NULL;
	root = BST(root, 8);
	root = BST(root, 3);
	root = BST(root, 1);
	root = BST(root, 6);
	root = BST(root, 10);
	root = BST(root, 14);
	root = BST(root, 13);
	root = BST(root, 12);
	printf("root %d\n", root->data);
	printf("left %d\n", root->left->left->data);
	printf("right %d\n", root->left->right->data);

}