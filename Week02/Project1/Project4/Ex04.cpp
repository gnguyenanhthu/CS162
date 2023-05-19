#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int a = 3;
	int *p = &a;
	cout << *p << endl;
	p = new int(5);
	cout << *p << endl;
	system("pause");
	return 0;
}