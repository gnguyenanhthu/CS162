#include <iostream>
using namespace std;

unsigned int dectobi(unsigned int x);
unsigned int bitodec(unsigned int x);
void dectohex(unsigned int x);

unsigned int dectobi(unsigned int x)
{
	unsigned int a = x, b = x;
	a = a / 2;
	b = b % 2;
	if (a == 0)
	{
		cout << b;
		return b;
	}
	dectobi(a);
	cout << b;
}


unsigned int bitodec(unsigned int x)
{
	int i = 0, a = 0, r;
	while (x != 0)
	{
		r = x % 10;
		x = x / 10;
		a = a + r*pow(2, i);
		++i;
	}
	return a;
}

void dectohex(unsigned int x) 
{
	int r;
	while (x > 0)
	{
		r = x % 16;
		if (r > 9)
		{
			switch (r)
			{
			case 10:
				cout << "A";
				break;
			case 11:
				cout << "B";
				break;
			case 12:
				cout << "C";
				break;
			case 13:
				cout << "D";
				break;
			case 14:
				cout << "E";
				break;
			case 15:
				cout << "F";
				break;
			}
		}
		else
			cout << r ;
		x = x / 16;
	}
}

int main()
{
	int a;
	unsigned int x;
	cout << "1.Decimal base to binary base." << endl;
	cout << "2.Binary base to decimal base." << endl;
	cout << "3. Decimal base to hex base." << endl;
	cin >> a;
	cout << "Input x: ";
	cin >> x;
	switch (a) 
	{
		case 1:
			dectobi(x);
		case 2:
		{
			unsigned int result;
			result = bitodec(x);
			cout << result << endl;
		}
		case 3:
			dectohex(x);
	}
	system("pause");
	return 0;
}