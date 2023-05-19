#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int v = 8, *r, *s;
	int *p;
	int q = 100;
	p = &q; //p la dia chi cua q
	r = p; //r,p la dia chi cua q
	*p = 20; //q=20 , *r=20
	p = new int;
	*r = 30; //q=30
	q = v; // q=v=8=*r
	s = p; //s la dia chi cua o moi
	*s = 50;

	cout << *p << endl;
	cout << q << endl;
	cout << *r << endl;
	cout << v << endl;
	cout << *s << endl;

	system("pause");
	return 0;
}