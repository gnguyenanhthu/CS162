#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int x, z;
	float y;
	char ch, *chp;
	int *ip1, *ip2;
	float *fp;

	x = 100;
	y = 20.0;
	z = 50;
	ch = 'Z';
	ip1 = &x; //dia chi cua x
	ip2 = &z; //dia chi cua z
	fp = &y; //dia chi cua y
	chp = &ch; //dia chi cua ch
	ip2 = ip1; // ip2 la dia chi cua x

	ip1 = &z; // ip1 la dia chi cua z
	*ip1 = *ip2; //*ip1 = 100 = z
	*ip1 = 200; //*ip1 = 200 = z
	*ip1 = *ip2 + 300; //*ip1 = 400 = z
	*fp = 1.2; //y=1.2

	cout << x << endl; //100
	cout << y << endl; //1.2
	cout << z << endl; //400
	cout << ip1 << endl; // dia chi cua z
	cout << *ip1 << endl; //400
	cout << &ip1 << endl; //dia chi cua ip1
	cout << ip2 << endl; //dia chi cua x
	cout << *ip2 << endl; //100
	cout << &ip2 << endl; //dia chi cua ip2
	cout << fp << endl; //dia chi cua y
	cout << *fp << endl; //1.2
	cout << &fp << endl; //dia chi cua fp
	cout << chp << endl; //dia chi cua ch
	cout << *chp << endl; //Z
	cout << &chp << endl; //dia chi cua chp
	
	system("pause");
	return 0;
}