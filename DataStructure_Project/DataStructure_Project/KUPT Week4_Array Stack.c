//KUPT Week4 'Array Stack'

#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct NodeType
{
	Element data;
}Node;


/*
It is critical topic in Array Stack to initialize 'Top' index.
I will implement this Array Stack ADT with

Empty : Top = 0
This means that 'in Push operation, I will put data into Top position and then increase Top'
				'in Pop operation, I will get data from (Top - 1) position and then decrease Top'
Like this method, you should check whether Stack is full or empty before each operation

*/

typedef struct ArrayStackType
{
	//int cnt;		//cnt can be replaced by Top
	int maxSize;
	int Top;
	Node* pLink;
}ArrayStack;


ArrayStack* CreateStack(int size)
{
	ArrayStack* rStack = NULL;
	rStack = (ArrayStack*)malloc(sizeof(ArrayStack));
	
	rStack->maxSize = size;
	rStack->Top = 0;
	rStack->pLink = (Node*)malloc(sizeof(Node)*size);

	return rStack;
}


int Push(ArrayStack* pStack, Element dataInput)
{
	if (pStack->Top >= pStack->maxSize)
	{
		printf("Push operation error, Stack is full\n");
		return -1;
	}

	pStack->pLink[pStack->Top].data = dataInput;
	pStack->Top++;

	return 1;
}


Element Pop(ArrayStack* pStack)
{
	if (pStack->Top == 0)
	{
		printf("Pop operation error, Stack is Empty\n");
		return -1;

	}
	
	int dataReturn = 0;
	dataReturn = pStack->pLink[(pStack->Top) - 1].data;
	pStack->Top--;

	return dataReturn;
}

int main()
{
	return 0;
}