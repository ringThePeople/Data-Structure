//JosephusProblem
//People are standing in a circle waiting to be executed.
//Counting begins at a specified point in the circle and proceeds around the circle in a specified direction.
//After a specified number of people are skipped, the next person is executed.The procedure is repeated with the remaining people, 
//starting with the next person, going in the same direction and skipping the same number of people, until only one person remains, and is freed.
//
//The problem given the number of people, starting point
//https://en.wikipedia.org/wiki/Josephus_problem


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
	ArrayQueue* JoseQueue = NULL;
	int Num_People = 0;
	int k = 0;
	printf("number of people : ");
	scanf_s("%d", &Num_People);
	printf("k : ");
	scanf_s("%d", &k);

	k = k % Num_People;
	JoseQueue = createArrayQueue(Num_People);
	int i = 0;
	for (i = 0; i < Num_People; i++)
	{
		Enqueue(JoseQueue, i + 1);
	}
	int index = k - 1;
	int check = 0;
	int output = 0;
	while (check<Num_People)
	{
		output = JoseQueue->pData[index].data;

		printf("%d ", output);
		JoseQueue->pData[index].data = 0;

		for (i = 0; i < k; i++)
		{
			index++;
			index = index%Num_People;
			while (JoseQueue->pData[index].data == 0)
			{
				index++;
				index = index%Num_People;
			}

		}
		check++;
	}
	printf("\n");
	return 0;
}