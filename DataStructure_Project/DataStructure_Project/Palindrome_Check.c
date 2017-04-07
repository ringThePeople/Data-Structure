#include <stdio.h>
#include <stdlib.h>


//A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward as forward, such as madam or racecar.
//https://en.wikipedia.org/wiki/Palindrome


int string_length(char* ptr, int length)
{
	int len = 0;
	if (ptr[length] == '\0')
		return len;
	len = string_length(ptr, length + 1) + 1;
	return len;
}


int palindrome(char* ptr, int n1, int n2)
{
	if (n1 == n2 || n1 > n2)
		return 1;
	if (palindrome(ptr, n1 + 1, n2 - 1) > 0 && ptr[n1] == ptr[n2])
		return 1;
	else
		return -1;
}


void print_palindrome(char* ptr, int len)
{
	printf("%s\n", ptr);
	if (palindrome(ptr, 0, len - 1) > 0)
	{
		printf("The string is palindrome\n");
	}
	else
		printf("The string is not palindrome\n");
}


int main()
{
	char str1[] = "asdfqwer";
	char str2[] = "kayak";
	char str3[] = "rotator";
	int length = 0;

	length = string_length(str1, 0);
	print_palindrome(str1, length);

	length = string_length(str2, 0);
	print_palindrome(str2, length);

	length = string_length(str3, 0);
	print_palindrome(str3, length);

	return 0;
}