#include <stdio.h>
#include <stdlib.h>


//two kinds of compare function to satisfy each types
int integer_compare(void* ptr1, void* ptr2)
{
	if (*(int*)ptr1 > *(int*)ptr2)
		return 1;
	else
		return -1;
}


int string_compare(void* ptr1, void* ptr2)
{
	int len1 = 0;
	int len2 = 0;
	char* ptrC1 = (char*)ptr1;
	char* ptrC2 = (char*)ptr2;
	while (*ptrC1 != '\0')
	{
		len1++;
		ptrC1++;
	}
	while (*ptrC2 != '\0')
	{
		len2++;
		ptrC2++;
	}
	if (len1 >= len2)
		return 1;
	else
		return -1;
}


//call with fucntion of comparing
void* larger(void* dataPtr1, void* dataPtr2, int(*functionPtr)(void*, void*))
{
	if ((*functionPtr)(dataPtr1, dataPtr2) > 0)
		return dataPtr1;
	else
		return dataPtr2;
}



int main()
{
	int integer1 = 7;
	int integer2 = 8;
	int integer_lrg = 0;
	char str1[] = "Ilove";
	char str2[] = "Computer";
	char* string_lrg = NULL;
	integer_lrg = *(int*)larger(&integer1, &integer2, integer_compare);
	string_lrg = (char*)larger(str1, str2, string_compare);
	printf("compare %d and %d, larger one : %d\n", integer1, integer2, integer_lrg);

	printf("\nstring1 : %s \nstring2 : %s \nlonger one : %s\n", str1, str2, string_lrg);
	return 0;
}