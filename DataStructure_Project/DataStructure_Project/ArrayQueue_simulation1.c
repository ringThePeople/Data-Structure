//from Data Structure COSE213(Korea Univ, 2016 - 2)
//Queue simulation 1
// There is a small hotdog stand
// Each customer has their own patience(1~9)
// The hotdog stand makes one hotdog per time unit
// Each Customer¡¯s patience is decreased by 1 per time unit
// If a customer¡¯s patience is 0, he left the queue before next time unit starts
// Input : number of customers, series of customer¡¯s patience
// Output : the number of hotdogs sold


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


//It can be implemented with two ideas
//idea 1 : reduce all of customers every unit
//			and check whose data is negative , drop them
//			but, this idea against the queue operation

//idea 2 : recode every unit count then check whether dequeue customer can satisfy this count
//			don't increase unit if that customer didn't buy something
//			I adopted this idea

void QueueSimulation1(ArrayQueue *pQueue)
{
	ArrayQueueNode* Node = NULL;
	int sales = 0;
	int i = 0;
	while (isArrayQueueEmpty(pQueue) == 0)
	{
		Node = Dequeue(pQueue);
		if (Node->data < 0)
			continue;
		else
		{
			sales++;
			for (i = 0; i < pQueue->maxCount; i++)
				(pQueue->pData[i].data)--;
		}
	}
	printf("I sell %d hotdogs\n", sales);
}


int main()
{
	ArrayQueue* QueueSimu = NULL;
	int CustomerNum = 0;
	printf("number of customer : ");
	scanf_s("%d", &CustomerNum);

	QueueSimu = createArrayQueue(CustomerNum);
	int patience = 0;
	int i = 0;
	for (i = 0; i < CustomerNum; i++)
	{
		printf("Patience of customer : ");
		scanf_s("%d", &patience);
		Enqueue(QueueSimu, patience);
	}

	QueueSimulation1(QueueSimu);

	destroyqueue(QueueSimu);
	getchar();
	getchar();
	return 0;
}