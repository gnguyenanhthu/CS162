#include "Function.h"

int main()
{
	int r1, rx = 0, ry = 0, r3 = 0, r4, r5 = 0;
	int n, k;
	cout << "Input n: ";
	cin >> n;
	cout << "Input k: ";
	cin >> k;

	r1 = fibonaci(n); //Ex01
	cout <<"Fibonaci: "<< r1 << endl;

	rx = sequencex(n, rx, ry); //Ex02
	ry = sequencey(n, rx, ry);
	cout << "x(n) = " << rx << endl;
	cout << "y(n) = " << ry << endl;

	r3 = calxn(n); //Ex03
	cout << "x(n) = " << r3 << endl;

	r4 = calcnk(n, k); //Ex04
	cout << "C(n,k) = " << r4 << endl;

	r5 = sumofdigits(n); //Ex05
	cout << "Sum of digits: " << r5 << endl;

	system("pause");
	return 0;

}