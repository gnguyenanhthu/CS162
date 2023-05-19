#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int *p, *q, v, nom[5];
	p = &v; //p la dia chi cua v
	*p = 12; //v=12
	q = p; //q la dia chi cua v
	nom[0] = *q; //nom la dia chi cua q
	p = nom; //p la dia chi cua nom[0]
	p++; //dia chi nom[1]
	nom[2] = 12; 
	*p = 13; //n[0]=13
	*q = 10; //v=13
	v = 11; //*q=11
	*(p + 3) = 16; //nom[3]=16
	p = &nom[3]; //p la dia chi cua nom[3]
	*p = 10; //nom[3]=10
	p--; //p la dia chi cua nom[2]

	cout << *p << endl;
	cout << *q << endl;
	cout << v << endl;
	cout << nom << endl;

	system("pause");
	return 0;
}