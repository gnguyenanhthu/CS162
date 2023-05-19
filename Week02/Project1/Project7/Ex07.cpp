#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

void change(int *b, int n);

int main()
{
	int i, a[] = { 2,4,6,8,10 };
	change(a, 5);
	for (i = 0; i <= 4; i++)
		printf("%d, ", a[i]);
	system("pause");
	return 0;
}

void change(int *b, int n)
{
	int i;
	for (i = 0; i < n; i++)
		*(b + 1) = *(b + i) + 5;
}
