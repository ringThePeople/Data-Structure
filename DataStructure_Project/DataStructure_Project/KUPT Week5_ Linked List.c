//KUPT Week5 'Linked List'

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Element;

typedef struct NodeType
{
	Element data;
	struct NodeType* pNext;
}Node;


typedef struct LinkedListType
{
	int cnt;
	Node* pLink;
}LinkedList;


LinkedList* CreateLinkedList()
{
	LinkedList* rList = NULL;
	rList->cnt = 0;
	rList->pLink = NULL;

	return rList;
}


void Insert_rear(LinkedList* pList, Element dataInput)
{
	Node* newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = dataInput;
	newNode->pNext = NULL;

	if (pList->cnt == 0)
	{
		pList->pLink = newNode;
		pList->cnt++;
		return;
	}

	Node* pNode = NULL;
	pNode = pList->pLink;
	while (pNode->pNext != NULL)
	{
		pNode = pNode->pNext;
	}
	
	pNode->pNext = newNode;
	pList->cnt++;
	return;
}


int Insert_index(LinkedList* pList, int index, Element dataInput)	
{
	/*
		Index should not be larger than cnt of List. 
		ex) cnt == 2, index should be 0, 1 or 2.
	*/
	if (index > pList->cnt)
	{
		printf("Insert_index error, input of index is out of range\n");
		return -1;
	}

	Node* newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = dataInput;
	newNode->pNext = NULL;

	if (index == 0)
	{
		newNode->pNext = pList->pLink;
		pList->pLink = newNode;
		pList->cnt++;
		return 1;
	}

	Node* pNode = NULL;
	pNode = pList->pLink;
	int i = 0;
	for (i = 1; i < index; i++)
	{
		pNode = pNode->pNext;
	}
	pNode->pNext = newNode;
	
	pList->cnt++;
	return 1;
}


bool Delete_data(LinkedList* pList, Element dataFind)
{
	if (pList->cnt == 0)
	{
		printf("pList is Empty\n");
		return false;
	}

	
	int delete_cnt = 0;
	Node* pNode = NULL;
	while (pList->cnt != 0 && pList->pLink->data != dataFind)
	{
		pNode = pList->pLink;
		pList->pLink = pNode->pNext;
		pList->cnt--;
		free(pNode);

		delete_cnt++;
	}
	
	if (pList->cnt == 0)
	{
		printf("delete %d in List, in %dth iteration\n", dataFind, delete_cnt);
		return true;
	}

	pNode = pList->pLink;
	Node* tempNode = NULL;
	while (pNode->pNext != NULL)
	{
		if (pNode->pNext->data == dataFind)
		{
			tempNode = pNode->pNext;
			pNode->pNext = tempNode->pNext;
			free(tempNode);
			pList->cnt--;
			delete_cnt++;
		}
		pNode = pNode->pNext;
	}
	if (delete_cnt != 0)
	{
		printf("delete %d in List, in %dth iteration\n", dataFind, delete_cnt);
		return true;
	}
	else
	{
		printf("List has not %d\n", dataFind);
		return false;
	}
}


int main()
{
	return 0;
}