#include <stdio.h>
#include <stdlib.h>


__int64 Fibonacci_Tail(int num, __int64 preFibo, __int64 prepreFibo)	// __int64 can show bigger size of Fibonacci numbers
{
	if (num <= 1)
		return num*preFibo;
	__int64 currFibo = preFibo + prepreFibo;

	prepreFibo = preFibo;

	preFibo = currFibo;

	return Fibonacci_Tail(num - 1, preFibo, prepreFibo);	//Using Tail recursion process

}


int main()
{
	int i;
	for (i = 50; i<60; i++)
		printf("%d : %lld\n", i, Fibonacci_Tail(i - 1, 1, 0));

	return 0;
}