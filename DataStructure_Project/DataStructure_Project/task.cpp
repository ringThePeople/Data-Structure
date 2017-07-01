//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//typedef int Element;
//
//typedef struct TreeType
//{
//	Element data;
//	struct TreeType* left;
//	struct TreeType* right;
//}Tree;
//
//Tree* CreateTree(Element dataInput)
//{
//	Tree* newTree = (Tree*)malloc(sizeof(Tree));
//	newTree->data = dataInput;
//	newTree->left = NULL;
//	newTree->right = NULL;
//
//	return newTree;
//}
//
//Tree* BST(Tree* root, Element dataInput)
//{
//	if (root == NULL)
//	{
//		return CreateTree(dataInput);
//	}
//
//	if (root->data > dataInput)
//	{
//		root->left = BST(root->left, dataInput);
//	}
//	else
//	{
//		root->right = BST(root->right, dataInput);
//	}
//
//	return root;
//}
//
//void print_inorder_by_recursion(Tree* root)
//{
//	if (root == NULL)
//		return;
//	print_inorder_by_recursion(root->left);
//	printf("%d, ", root->data);
//	print_inorder_by_recursion(root->right);
//}
//
//typedef struct NodeType
//{
//	Tree* data;
//	struct NodeType* pNext;
//}Node;
//typedef struct StackType
//{
//	int cnt;
//	Node* Top;
//}Stack;
//
//Stack* CreateStack()
//{
//	Stack* rStack = NULL;
//	rStack = (Stack*)malloc(sizeof(Stack));
//	rStack->Top = NULL;
//	rStack->cnt = 0;
//
//	return rStack;
//}
//void Push(Stack* pStack, Tree* dataInput)
//{
//	Node* newNode = NULL;
//	newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = dataInput;
//	newNode->pNext = pStack->Top;
//
//	pStack->Top = newNode;
//	pStack->cnt++;
//}
//bool isEmpty(Stack* pStack)
//{
//	if (pStack->cnt <= 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//Tree* Pop(Stack* pStack)
//{
//	if (isEmpty(pStack))
//	{
//		printf("error, can't pop\n");
//		return NULL;
//	}
//	else
//	{
//		Node* pNode = pStack->Top;
//		Tree* rTree = pNode->data;
//
//		pStack->Top = pNode->pNext;
//		pStack->cnt--;
//
//		free(pNode);
//		return rTree;
//	}
//}
//
//void inorder_iter(Tree* root)
//{
//	Tree* pTree = root;
//	Stack* pStack = CreateStack();
//
//	while (!isEmpty(pStack) || pTree != NULL)
//	{
//		if (pTree != NULL)
//		{
//			Push(pStack, pTree);
//			pTree = pTree->left;
//		}
//		else
//		{
//			pTree = Pop(pStack);
//			printf("%d , ", pTree->data);
//			pTree = pTree->right;
//		}
//	}
//}
//int main()
//{
//	Tree* root = NULL;
//	root = BST(root, 8);
//	root = BST(root, 3);
//	root = BST(root, 1);
//	root = BST(root, 6);
//	root = BST(root, 10);
//	root = BST(root, 14);
//	root = BST(root, 13);
//	root = BST(root, 12);
//
//	//print_inorder_by_recursion(root);
//	inorder_iter(root);
//}