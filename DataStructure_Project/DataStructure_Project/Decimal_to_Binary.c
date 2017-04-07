#include <stdio.h>
#include <stdlib.h>


void Decimal_to_Binary(int Dnum)	//print binary type numbers of decimal number
{
	if (Dnum != 0)
	{
		Decimal_to_Binary(Dnum / 2);
		printf("%d", Dnum % 2);
	}
	return;
}


int main()
{
	int i;
	for (i = 1; i <= 12; i++)
	{
		printf("%d : ", i);
		Decimal_to_Binary(i);
		printf("\n");
	}
	return 0;
}