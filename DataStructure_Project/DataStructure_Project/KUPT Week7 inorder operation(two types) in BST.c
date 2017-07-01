//KUPT Week7 'inorder operation(two types) in BST'

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
typedef struct NodeType
{
	BTree* data;
	struct NodeType* pNext;
}Node;
typedef struct StackType
{
	int cnt;
	Node* Top;
}Stack;

void Push(Stack* pStack, BTree* dataInput)
{
	Node* newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = dataInput;
	newNode->pNext = pStack->Top;

	pStack->Top = newNode;
	pStack->cnt++;
}

bool isEmpty(Stack* pStack)
{
	if (pStack->cnt == 0)
		return true;
	else
		return false;
}
BTree* Pop(Stack* pStack)
{
	if (isEmpty(pStack))
	{
		printf("Stack is Empty, Pop Error\n");
		return NULL;
	}
	else
	{
		Node* pNode = pStack->Top;
		BTree* rTree = pNode->data;
		pStack->Top = pNode->pNext;
		pStack->cnt--;
		free(pNode);
		return rTree;
	}
}

void inorder_iter(BTree* root)
{
	Stack* pStack = NULL;
	pStack = (Stack*)malloc(sizeof(Stack));
	pStack->cnt = 0;
	pStack->Top = NULL;

	BTree* pTree = root;
	while (!isEmpty(pStack) || pTree != NULL)
	{
		if (pTree != NULL)
		{
			Push(pStack, pTree);
			pTree = pTree->left;
		}
		else
		{
			pTree = Pop(pStack);
			printf("%d, ", pTree->data);
			pTree = pTree->right;
		}
	}
}

void print_by_inorder_recursion(BTree* root)
{
	BTree* pNode = root;
	if (pNode == NULL)
		return;

	print_by_inorder_recursion(pNode->left);
	printf("%d\n", pNode->data);
	print_by_inorder_recursion(pNode->right);

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
	
	inorder_iter(root);

	return 0;
}