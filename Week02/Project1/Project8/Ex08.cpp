#include "Function.h"

int main()
{
	int *p, n, a, b, k;

	load("D:\\APCS\\CS162\\Week02\\input.txt", p, n); //1

	a = largestprime(p, n); //2
	if (a == 0)
		cout << "There's no prime number." << endl;
	else
		cout << "The largest prime number is: " << a << endl;

	cout << "The array after sort odd and even: " << endl;
	sortoddeven(p, n); //3
	
	cout << "Input a number you want to insert: ";
	cin >> k;
	insert(p, n, k); //4

	removesame(p, n); //5

	b = gcdarray(p, n); //6
	cout << "GCD of the array is:" << b << endl;

	cout << "This is the array: " << endl;
	display(p, n); //7

	save("D:\\APCS\\CS162\\Week02\\output.txt", p, n); //8

	system("pause");
	return 0;
}