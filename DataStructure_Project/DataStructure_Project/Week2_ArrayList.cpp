//KUPT Week2 'Array List'
//with two types of methods

#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct NodeType
{
	Element data;
}Node;


//type 1
typedef struct ArrayListType_type1
{
	int cnt;
	int maxSize;
	Node* pLink;
}ArrayList_type1;

ArrayListType_type1* CreateList_type1(int size)
{
	ArrayListType_type1* rList = NULL;

	rList = (ArrayListType_type1*)malloc(sizeof(ArrayListType_type1));
	rList->cnt = 0;
	rList->maxSize = size;
	rList->pLink = (Node*)malloc(sizeof(Node)*size);

	return rList;
}

int Insert_type1(ArrayListType_type1* pList, Element dataInput)
{
	if (pList->cnt >= pList->maxSize)
	{
		printf("Insert_type1 error, pList was already ful\n");
		return -1;
	}
	pList->pLink[pList->cnt].data = dataInput;
	pList->cnt++;

	return 1;
}

Element Data_from_index_type1(ArrayListType_type1* pList, int index)
{
	if (index >= pList->cnt || index < 0 || pList->cnt == 0)
	{
		printf("Data_from_index_type1 error, input of index is out of range\n");
		return -1;
	}

	return pList->pLink[index].data;
}

int Delete_from_index_type1(ArrayListType_type1* pList, int index)
{
	if (index >= pList->cnt || index < 0 || pList->cnt == 0)
	{
		printf("Delete_from_index_type1 error, input of index is out of range\n");
		return -1;
	}

	pList->pLink[pList->cnt].data = 0; 	//this operation is almost meaningless
	pList->cnt--;

	return 1
		;
}
//type 2
typedef struct ArrayListType_type2
{
	int cnt;
	int maxSize;
	Node** pLink;
}ArrayList_type2;


ArrayListType_type2* CreateList_type2(int size)
{
	ArrayListType_type2* rList = NULL;

	rList = (ArrayListType_type2*)malloc(sizeof(ArrayListType_type2));
	rList->cnt = 0;
	rList->maxSize = size;
	rList->pLink = (Node**)malloc(sizeof(Node*) * size);

	return rList;
}

int Insert_type2(ArrayListType_type2* pList, Element dataInput)
{
	if (pList->cnt >= pList->maxSize)
	{
		printf("Insert_type2 error, pList was already ful\n");
		return -1;
	}
	pList->pLink[pList->cnt] = (Node*)malloc(sizeof(Node));
	pList->pLink[pList->cnt]->data = dataInput;
	pList->cnt++;

	return 1;
}

Element Data_from_index_type2(ArrayListType_type2* pList, int index)
{
	if (index >= pList->cnt || index < 0 || pList->cnt == 0)
	{
		printf("Data_from_index_type2 error, input of index is out of range\n");
		return -1;
	}

	return pList->pLink[index]->data;
}

int Delete_from_index_type2(ArrayListType_type2* pList, int index)
{
	if (index >= pList->cnt || index < 0 || pList->cnt == 0)
	{
		printf("Delete_from_index_type2 error, input of index is out of range\n");
		return -1;
	}

	free(pList->pLink[pList->cnt]);
	pList->cnt--;

	return 1;
}

int main()
{
	return 0;
}