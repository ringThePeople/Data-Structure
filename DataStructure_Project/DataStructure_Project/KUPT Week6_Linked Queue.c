//KUPT Week6 'Linked Queue'

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Element;

typedef struct NodeType
{
	Element data;
	struct NodeType* pNext;
}Node;


typedef struct LinkedQueueType
{
	int cnt;
	Node* front;
	Node* rear;
}LinkedQueue;


LinkedQueue* CreateLinkedQueue()
{
	LinkedQueue* rQueue = NULL;
	rQueue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	rQueue->cnt = 0;
	rQueue->front = NULL;
	rQueue->rear = NULL;

	return rQueue;
}


void Enqueue(LinkedQueue* pQueue, Element dataInput)
{
	Node* newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = dataInput;
	newNode->pNext = NULL;

	if (pQueue->cnt == 0)
	{
		pQueue->front = newNode;
		pQueue->rear = newNode;
		pQueue->cnt++;
		return;
	}

	pQueue->rear->pNext = newNode;
	pQueue->rear = newNode;
	pQueue->cnt++;
	return;
}


Element Dequeue(LinkedQueue* pQueue)
{
	if (pQueue->cnt == 0)
	{
		printf("Dequeue error, Queue is Empty\n");
		return -1;
	}

	Node* pNode = NULL;
	pNode = pQueue->front;
	int dataReturn = 0;
	dataReturn = pNode->data;

	if (pQueue->cnt == 1)
	{
		pQueue->front = NULL;
		pQueue->rear = NULL;

		free(pNode);
		pQueue->cnt--;
		return dataReturn;
	}

	pQueue->front = pNode->pNext;
	
	free(pNode);
	pQueue->cnt--;
	return dataReturn;
}


int main()
{
	return 0;
}