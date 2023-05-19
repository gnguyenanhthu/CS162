#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int *a = new int;
	int *b = new int;
	
	*a = 2;
	b = a;
	
	cout << *a << endl;
	cout << *b << endl;
	
	delete a;
	// delete b; bi du dong nay do b=a

	system("pause");
	return 0;
}