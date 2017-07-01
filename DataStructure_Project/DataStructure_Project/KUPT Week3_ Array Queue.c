//KUPT Week3 'Array Queue'

#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct NodeType
{
	Element data;
}Node;


/*
	It is critical topic in Array Queue to initialize 'front, rear' index.
	I will implement this Array Queue ADT with
	
	Empty : front = 0, rear = 0
	This means that 'in Enqueue operation, I will put data into rear position and then increase rear'
					'in Dequeue operation, I will get data from front position and then increase front'
	Like this method, you should check whether cnt is ful or empty before each operation
*/

typedef struct ArrayQueueType
{
	int cnt;		//cnt can be replaced by (rear - front)
	int maxSize;
	int front;
	int rear;
	Node* pLink;
}ArrayQueue;


ArrayQueue* CreateArrayQueue(int size)
{
	ArrayQueue* rQueue = NULL;
	
	rQueue = (ArrayQueue*)malloc(sizeof(ArrayQueue));
	rQueue->cnt = 0;
	rQueue->maxSize = size;
	rQueue->front = 0;
	rQueue->rear = 0;
	rQueue->pLink = (Node*)malloc(sizeof(Node)*size);

	return rQueue;
}


int Enqueue(ArrayQueue* pQueue, Element dataInput)
{
	if (pQueue->cnt >= pQueue->maxSize || pQueue->rear >= pQueue->maxSize)
	{
		printf("Enqueue error, Queue doesn't have enough space\n");
		return -1;
	}

	pQueue->pLink[pQueue->rear].data = dataInput;
	pQueue->cnt++;
	pQueue->rear++;

	return 1;
}


Element Dequeue(ArrayQueue* pQueue)
{
	if (pQueue->cnt == 0)
	{
		printf("Dequeue error, Queue is Empty\n");
		return -1;
	}
	
	int dataReturn = 0;
	dataReturn = pQueue->pLink[pQueue->front].data;
	pQueue->cnt--;

	if (pQueue->cnt == 0)	// This Dequeue operation makes Queue Empty
	{
		pQueue->front = 0;
		pQueue->rear = 0;
		return dataReturn;
	}

	pQueue->front++;
	return dataReturn;
}

int main()
{
	return 0;
}