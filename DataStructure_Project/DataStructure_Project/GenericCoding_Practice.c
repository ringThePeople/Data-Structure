#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType		//Use void pointer to implement generic process
{
	void* data;
	struct nodeType* pLink;
}Node;

typedef struct linkedListType
{
	Node* Head;
}linkedList;

Node* createNode(void* data)
{
	Node* pReturn = NULL;
	pReturn = (Node*)malloc(sizeof(Node));
	if (pReturn != NULL)
	{
		pReturn->data = data;
		pReturn->pLink = NULL;
		return pReturn;
	}
	else
	{
		printf("Memory allocation Error, createNode()\n");
		return -1;
	}
}

linkedList* createLinkedList()
{
	linkedList* pReturn = NULL;
	pReturn = (linkedList*)malloc(sizeof(linkedList));
	if (pReturn != NULL)
	{
		pReturn->Head = NULL;
		return pReturn;
	}
	else
	{
		printf("Memory allocation Error, createLinkedLIst()\n");
		return -1;
	}
}


int main()		//Testing function
{
	linkedList* pList = NULL;
	pList = createLinkedList();

	int* intV = NULL;
	intV = (int*)malloc(sizeof(int));
	*intV = 10;
	float* floatV = NULL;
	floatV = (float*)malloc(sizeof(float));
	*floatV = 15.5f;

	pList->Head = createNode(intV);
	pList->Head->pLink = createNode(floatV);

	printf("%d\n", *(int*)(pList->Head->data));
	printf("%.2f\n", *(float*)(pList->Head->pLink->data));

}

