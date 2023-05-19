#include"Function.h"

void output(int a[], int n) 
{
	if (n == 0)
		return;
	output(a, n - 1);
	cout << a[n-1] << " ";
}

void outputreverse(int a[], int n, int x) 
{
	if (x == n) return;
	outputreverse(a, n, x + 1);
	cout << a[x] << " ";
}

int sumofposint(int a[], int n) 
{
	if (n == 0) return a[n];
	else if (a[n] > 0)
		return (a[n] + sumofposint(a, n - 1));
	else
		return sumofposint(a, n-1);
}

int countdistinct(int a[], int n) //Chua xong
{
	if (n == 0) return 0;
	else if (a[n - 1] == a[n]) return countdistinct(a, n - 1);
	else
		return 1+countdistinct(a, n - 1);
}

bool checkoddnumb(int a[], int n)
{
	if (a[n] % 2 != 0) return false;
	if (n == 0) return true;
	checkoddnumb(a, n - 1);
}

int maxvalue(int a[], int n)
{
	if (n == 0) return a[0];
	else
	{
		if (maxvalue(a, n - 1) > a[n])
			return maxvalue(a, n - 1);
		else
			return a[n];
	}
}