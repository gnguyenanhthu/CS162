#include<iostream>
#include<stdio.h>
using namespace std;

int main() 
{
	int a = 3;
	int *b = &a;
	cout << b << endl;
	cout << *b << endl;
	cout << &b << endl;
	cout << a << endl;
	// cout << *a << endl; bi sai vi a ko phai pointer
	cout << &a << endl;
	system("pause");
	return 0;
}