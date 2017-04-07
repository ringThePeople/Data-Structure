//from Data Structure COSE213(Korea Univ, 2016 - 2)
//Queue simulation 2
// The hotdog stand gets larger and It has two line
// Each line makes one hotdog per time unit
// Input : number of customers, series of customer¡¯s patience
// Output : maximum number of hotdogs sold


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


//line 1 : half of input customers(raising fractions not lower than 0.5 to a unit)
//line 2 : rest of customers
//to each lines, do simulation same as Queue simulation1 

//It can be implemented with two ideas
//idea 1 : reduce all of customers every unit
//			and check whose data is negative , drop them
//			but, this idea against the queue operation

//idea 2 : recode every unit count then check whether dequeue customer can satisfy this count
//			don't increase unit if that customer didn't buy something
//			I adopted this idea

void QueueSimulation2(ArrayQueue *pQueue1, ArrayQueue *pQueue2)
{
	ArrayQueueNode* Node = NULL;
	int sales = 0;
	int i = 0;
	while (isArrayQueueEmpty(pQueue1) == 0)
	{
		Node = Dequeue(pQueue1);
		if (Node->data < 0)
			continue;
		else
		{
			sales++;
			for (i = 0; i < pQueue1->maxCount; i++)
				(pQueue1->pData[i].data)--;
		}
	}
	while (isArrayQueueEmpty(pQueue2) == 0)
	{
		Node = Dequeue(pQueue2);
		if (Node->data < 0)
			continue;
		else
		{
			sales++;
			for (i = 0; i < pQueue2->maxCount; i++)
				(pQueue2->pData[i].data)--;
		}
	}
	printf("I sell %d hotdogs\n", sales);
}


int main()
{
	ArrayQueue* QueueSimu_line1 = NULL;
	ArrayQueue* QueueSimu_line2 = NULL;
	int CustomerNum = 0;
	printf("number of customer : ");
	scanf_s("%d", &CustomerNum);
	int size2 = CustomerNum / 2;
	int size1 = CustomerNum - size2;

	QueueSimu_line1 = createArrayQueue(size1);
	QueueSimu_line2 = createArrayQueue(size2);

	int patience = 0;
	int i = 0;
	for (i = 0; i < size1; i++)
	{
		printf("Patience of customer : ");
		scanf_s("%d", &patience);
		Enqueue(QueueSimu_line1, patience);
	}
	for (i = 0; i < size2; i++)
	{
		printf("Patience of customer : ");
		scanf_s("%d", &patience);
		Enqueue(QueueSimu_line2, patience);
	}
	QueueSimulation2(QueueSimu_line1, QueueSimu_line2);

	destroyqueue(QueueSimu_line1);
	destroyqueue(QueueSimu_line2);

	getchar();
	getchar();
	return 0;
}