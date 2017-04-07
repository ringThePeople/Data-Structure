#include <stdio.h>
#include <stdlib.h>


typedef int Element;


typedef struct ArrayQueueNodeType
{
	Element data;
}ArrayQueueNode;


typedef struct ArrayQueueType
{
	int maxCount;
	int currentCount;
	int front;
	int rear;
	ArrayQueueNode *pData;
}ArrayQueue;


int isArrayQueueFull(ArrayQueue* pQueue);
int isArrayQueueEmpty(ArrayQueue* pQueue);


ArrayQueue* createArrayQueue(int size)
{
	ArrayQueue *pReturn = NULL;
	pReturn = (ArrayQueue*)malloc(sizeof(ArrayQueue));
	memset(pReturn, 0, sizeof(ArrayQueue));
	pReturn->maxCount = size;
	pReturn->currentCount = 0;
	pReturn->front = -1;
	pReturn->rear = -1;

	pReturn->pData = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode)*size);
	memset(pReturn->pData, 0, sizeof(ArrayQueueNode)*size);

	return pReturn;
}


int Enqueue(ArrayQueue* pQueue, Element data)
{
	int ret = 0;

	if (pQueue != NULL) {
		if (isArrayQueueFull(pQueue) == 0) {
			pQueue->rear = (pQueue->rear + 1) % pQueue->maxCount;
			pQueue->pData[pQueue->rear].data = data;
			pQueue->currentCount++;
			ret = 1;
		}
		else {
			printf("Queue overflow Error, enqueue\n");
		}
	}
	return ret;
}


int isArrayQueueFull(ArrayQueue* pQueue)
{
	int ret = 0;

	if (pQueue != NULL) {
		if (pQueue->currentCount == pQueue->maxCount)
			ret = 1;
	}
	return ret;
}

ArrayQueueNode* Dequeue(ArrayQueue* pQueue)
{
	ArrayQueueNode *pReturn = NULL;
	if (pQueue != NULL) {
		if (isArrayQueueEmpty(pQueue) == 0) {
			pReturn = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode));
			if (pReturn != NULL) {
				pQueue->front = (pQueue->front + 1) % pQueue->maxCount;
				pReturn->data = pQueue->pData[pQueue->front].data;
				pQueue->currentCount--;
			}
			else {
				printf("Memory allocation Error,dequeue\n");
			}
		}
	}
	return pReturn;
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	int ret = 0;
	if (pQueue != NULL) {
		if (pQueue->currentCount == 0) {
			ret = 1;
		}
	}
	return ret;
}

ArrayQueueNode* QueueFront(ArrayQueue* pQueue)
{
	ArrayQueueNode *pReturn = NULL;
	if (pQueue != NULL) {
		if (isArrayQueueEmpty(pQueue) == 0) {
			pReturn = &(pQueue->pData[pQueue->front + 1]);
		}
		else
			printf("Queue is Empty, QueueFront function\n");
	}

	return pReturn;
}

void destroyqueue(ArrayQueue* pQueue)
{
	if (pQueue != NULL) {
		if (pQueue->pData != NULL) {
			free(pQueue->pData);
		}
		free(pQueue);
	}
}

void displayArrayQueue(ArrayQueue *pQueue)
{
	int i = 0, position = 0;

	if (pQueue != NULL) {
		printf("size of queue: %d, current queue count : %d\n",
			pQueue->maxCount,
			pQueue->currentCount);

		for (i = pQueue->front + 1; i <= pQueue->front + pQueue->
			currentCount; i++) {
			position = i % pQueue->maxCount;
			printf("[%d]-[%d]\n", position, pQueue->pData[position].data);
		}
	}
}

int main()
{
	ArrayQueue *pQueue = NULL;
	ArrayQueueNode *pNode = NULL;

	pQueue = createArrayQueue(4);
	if (pQueue != NULL) {
		Enqueue(pQueue, 1);
		Enqueue(pQueue, 2);
		Enqueue(pQueue, 3);
		Enqueue(pQueue, 4);
		displayArrayQueue(pQueue);

		pNode = Dequeue(pQueue);
		if (pNode != NULL) {
			printf("Dequeue Value-[%d]\n", pNode->data);
			free(pNode);
		}

		displayArrayQueue(pQueue);

		pNode = QueueFront(pQueue);
		if (pNode != NULL) {
			printf("QueueFront value-[%d]\n", pNode->data);
		}
		displayArrayQueue(pQueue);
		Enqueue(pQueue, 5);
		displayArrayQueue(pQueue);

	}
	destroyqueue(pQueue);
	getchar();
	return 0;
}