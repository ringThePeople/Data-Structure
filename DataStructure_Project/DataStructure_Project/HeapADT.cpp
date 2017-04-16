#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Element;

typedef struct HeapType
{
	Element* Array;
	int maxSize;
	int Cnt;
}Heap;


Heap* heapCreate(int size);						//memory allocation
int heapCount(Heap* pHeap);
bool heapFull(Heap* pHeap);
bool heapEmpty(Heap* pHeap);
bool heapDestroy(Heap* pHeap);

int parentIndex(int index);
void reheapUp(Heap* pHeap, int index);
bool heapInsert(Heap* pHeap, Element insert);	//insert data to heap, it needs reheap up

int childIndex(Heap* pHeap, int index);			
void reheapDown(Heap* pHeap, int index);		
bool heapDelete(Heap* pHeap);					//delete root node's data, then reheap down operation

int powfunction(int a, int n);
void heapPrint(Heap* pHeap);


Heap* heapCreate(int size)
{
	Heap* hReturn = NULL;
	hReturn = (Heap*)malloc(sizeof(Heap));
	hReturn->maxSize = size;
	hReturn->Cnt = 0;

	hReturn->Array = (Element*)malloc(sizeof(Element)*size);

	int i;
	for (i = 0; i < size; i++)
		hReturn->Array[i] = 0;	//initialize

	return hReturn;
}


int heapCount(Heap* pHeap)
{
	int sizeReturn = 0;
	sizeReturn = pHeap->Cnt;

	return sizeReturn;
}


bool heapFull(Heap* pHeap)
{
	if (pHeap->Cnt >= pHeap->maxSize)
		return true;
	else
		return false;
}


bool heapEmpty(Heap* pHeap)
{
	if (pHeap->Cnt == 0 || pHeap->maxSize == 0)
		return true;
	else
		return false;
}


bool heapDestroy(Heap* pHeap)
{
	free(pHeap->Array);
	free(pHeap);

	return true;
}


int parentIndex(int index)
{
	int pReturn = 0;
	pReturn = (index - 1) / 2;
	return pReturn;
}


void reheapUp(Heap* pHeap, int index)
{
	if (index == 0)
		return;

	int pIndex = parentIndex(index);
	Element temp = 0;
	if (pHeap->Array[pIndex] < pHeap->Array[index])
	{
		temp = pHeap->Array[pIndex];
		pHeap->Array[pIndex] = pHeap->Array[index];
		pHeap->Array[index] = temp;
		reheapUp(pHeap, pIndex);
	}
	else
		return;
}


bool heapInsert(Heap* pHeap, Element insert)
{
	if (heapFull(pHeap))
		return false;
	else
	{
		int index = heapCount(pHeap);
		pHeap->Array[index] = insert;
		reheapUp(pHeap, index);

		pHeap->Cnt++;
		return true;
	}
}


int childIndex(Heap* pHeap, int index)
{
	int C1 = (index * 2) + 1;
	int C2 = (index * 2) + 2;
	if (C1 == (pHeap->Cnt - 1))
		return C1;
	else if (C2 >= pHeap->Cnt)
	{
		return -1;
	}
	else
	{
		if (pHeap->Array[C1] < pHeap->Array[C2])
			return C2;
		else
			return C1;
	}
}


void reheapDown(Heap* pHeap, int index)
{
	int bigChild = childIndex(pHeap, index);
	Element temp = 0;
	if (bigChild < 0)
		return;

	if (pHeap->Array[index] < pHeap->Array[bigChild])
	{
		temp = pHeap->Array[index];
		pHeap->Array[index] = pHeap->Array[bigChild];
		pHeap->Array[bigChild] = temp;

		reheapDown(pHeap, bigChild);
	}
}


bool heapDelete(Heap* pHeap)
{
	if (heapEmpty(pHeap))
		return false;
	else if (heapCount(pHeap) == 1)
	{
		pHeap->Array[0] = 0;
		pHeap->Cnt--;
		return true;
	}
	else
	{
		int last = heapCount(pHeap) - 1;
		pHeap->Array[0] = pHeap->Array[last];
		pHeap->Array[last] = 0;
		reheapDown(pHeap, 0);

		pHeap->Cnt--;
		return true;
	}
}


int powfunction(int a, int n)
{
	if (n == 0)
		return 1;
	int i = 0;
	int pReturn = a;
	for (i = 1; i < n; i++)
		pReturn *= a;

	return pReturn;
}


void heapPrint(Heap* pHeap)
{
	int index = 0;
	int i, j;
	for (i = 0; i < heapCount(pHeap); i++)
	{
		for (j = 0; j < powfunction(2, i); j++)
		{
			printf("%d ", pHeap->Array[index++]);
			if (index == pHeap->Cnt)
			{
				printf("\n");
				return;
			}
		}

		printf("\n");
	}

}


int main()
{
	Heap* pHeap = heapCreate(15);
	heapInsert(pHeap, 6);
	heapInsert(pHeap, 3);
	heapInsert(pHeap, 8);
	heapInsert(pHeap, 2);
	heapInsert(pHeap, 10);
	heapInsert(pHeap, 11);
	heapInsert(pHeap, 12);
	heapInsert(pHeap, 13);
	heapInsert(pHeap, 14);

	heapPrint(pHeap);

	printf("\nheapDelete\n\n");
	heapDelete(pHeap);

	heapPrint(pHeap);

	printf("\nheapInsert(9)\n");
	heapInsert(pHeap, 9);

	heapPrint(pHeap);

	heapDestroy(pHeap);

	return 0;
}