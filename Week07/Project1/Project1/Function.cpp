#include "Function.h"


int fibonaci(int n) //Ex01
{
	if (n == 1 || n == 2) return 1;
	return (fibonaci(n - 2) + fibonaci(n - 1));
}


int sequencex(int n, int x, int y) //Ex02
{
	if (n == 0) return x = 1;
	return(sequencex(n - 1, x, y) + sequencey(n - 1, x, y));
}


int sequencey(int n, int x,int y)
{
	if (n == 0) return y = 0;
	return(3 * sequencex(n - 1, x, y) + 2 * sequencey(n - 1, x, y));
}


int calxn(int n) //Ex03
{
	if (n == 0) return 1;
	return(pow(n, 2)+pow(n-1,2)*calxn(n - 1));
}


int calcnk(int n, int k) //Ex04
{
	if (k == 0 || k == n) return 1;
	return (calcnk(n - 1, k) + calcnk(n - 1, k - 1));
}


int sumofdigits(int x) //Ex05
{
	if (x == 0) return 0;
	return sumofdigits(x / 10) + x % 10;
}

