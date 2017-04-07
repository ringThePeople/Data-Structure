#include <stdio.h>
#include <stdlib.h>

typedef int Element;


typedef struct StackNodeType
{
	struct StackNodeType* pNext;
	Element data;
}Node;


typedef struct StackType
{
	Node* top;
	int count;
}Stack;


Stack* createStack()
{
	Stack* pReturn = NULL;
	pReturn = (Stack*)malloc(sizeof(Stack));
	if (pReturn != NULL)
	{
		pReturn->top = NULL;
		pReturn->count = 0;

		return pReturn;
	}
	else
		printf("createStack()_Memory allocation Error\n");
}


int Push(Stack* pStack, Element Ndata)
{
	Node* NewNode = NULL;
	NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode == NULL)
	{
		printf("Push()_Memory allocation Error\n");
		return -1;
	}
	NewNode->data = Ndata;
	NewNode->pNext = pStack->top;
	pStack->top = NewNode;
	pStack->count++;
	return 1;
}


Element Pop(Stack* pStack)
{
	if (pStack->count != 0)
	{
		Node* preNode = NULL;
		Element iReturn = pStack->top->data;
		preNode = pStack->top;
		pStack->top = pStack->top->pNext;
		pStack->count--;
		free(preNode);
		return iReturn;
	}
	else
	{
		printf("Stack underflow\n");
		return -1;
	}
}


Element StackTop(Stack* pStack)
{
	if (pStack->count != 0)
	{
		return pStack->top->data;
	}
	else
	{
		printf("Stack is Empty.\n");
		return -1;
	}
}


int DestroyStack(Stack* pStack)
{
	while (pStack->count != 0)
	{
		Pop(pStack);
	}
	free(pStack);
	return 1;
}


int CatStack(Stack* FirstStack, Stack* SecondStack)
{
	Stack* TempStack = NULL;
	TempStack = createStack();
	Element temp = 0;
	while (SecondStack->count != 0)
	{
		temp = Pop(SecondStack);
		Push(TempStack, temp);
	}
	while (TempStack->count != 0)
	{
		temp = Pop(TempStack);
		Push(FirstStack, temp);
	}

	return 1;
}
//if Stack 1	Stack 2
//		2			5		
//		1			4
//		0			3
//After CatStack Function
//	Stack1		Stack 2
//		5
//		4
//		3
//		2
//		1
//		0


void CheckStack(Stack* pStack)
{
	Node* pNode = NULL;
	int i = 0;
	pNode = pStack->top;
	if (pStack->count == 0)
	{
		printf("Stack is Empty\n");
		return;
	}
	while (1)
	{
		if (pNode == NULL)
			break;
		printf("[%d] : %d\n", ++i, pNode->data);
		pNode = pNode->pNext;
	}
}//Checking data of Stack from Top to bottom, print


int main()
{
	Stack* StackA = NULL;
	Stack* StackB = NULL;

	StackA = createStack();
	StackB = createStack();

	Push(StackA, 1);
	Push(StackA, 2);
	Push(StackA, 3);

	printf("StackA\n");
	CheckStack(StackA);

	Push(StackB, 4);
	Push(StackB, 5);

	printf("\nStackB\n");
	CheckStack(StackB);

	CatStack(StackA, StackB);
	printf("\nAfter CatStack(StackA,StackB)\nStackA\n");
	CheckStack(StackA);

	DestroyStack(StackA);
	DestroyStack(StackB);

	getchar();
	return 0;
}