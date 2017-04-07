#include <stdio.h>
#include <stdlib.h>


int* Fibonacci_loop(int n)		//Using iteration
{
	int*fp = (int*)malloc(n * sizeof(int));
	fp[0] = 0;
	fp[1] = 1;
	int i;
	for (i = 2; i < n; i++)
	{
		fp[i] = fp[i - 1] + fp[i - 2];
	}
	return fp;
}


int Fibonacci_recursion(int n)		//Using recursion
{
	if (n == 1)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}
	return (Fibonacci_recursion(n - 1) + Fibonacci_recursion(n - 2));
}
int main()
{
	int n = 9;

	int* Fibo_loop = NULL;
	Fibo_loop = Fibonacci_loop(n);
	int i;
	printf("Fibonacci function with Iteration\n");
	for (i = 0; i < n; i++)
	{
		printf("%d : %d\n", i + 1, Fibo_loop[i]);
	}

	printf("\nFibonacci function with Recursion\n");
	for (i = 1; i <= n; i++)
	{
		printf("%d : %d\n", i, Fibonacci_recursion(i));
	}

	return 0;
}