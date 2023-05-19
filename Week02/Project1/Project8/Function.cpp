#include "Function.h"

void load(char path[], int *&p, int &n) //1
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return;
	fin >> n;
	p = new int[n];
	for (int i = 0; i<n; i++)
		fin >> p[i];
	fin.close();
}

bool checkprime(int n)
{
	bool prime = true;
	for (int i = 2; i <= (n/2); i++)
	{
		if (n % i == 0)
			return prime = false;
	}
	return prime = true;
}

int largestprime(int *p, int n) //2
{
	int ans = 0;
	bool prime;
	for (int i = 0; i<n; i++)
	{
		prime = checkprime(p[i]);
		if ((prime) && (p[i] > ans))
			ans = p[i];
	}
	return ans;
}

void sortoddeven(int *p, int n) //3
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((p[i] % 2 == 0) && (p[j] % 2 == 0) && (p[i] < p[j]))
				swap(p[i], p[j]);
			if ((p[i] % 2 != 0) && (p[j] % 2 != 0) && (p[i] > p[j]))
				swap(p[i], p[j]);
		}
	}
	display(p, n);
}

void insert(int *&p, int &n, int k) //4
{
	p[n] = k;
	n = n + 1;
}

void removeone(int *s, int &n, int a)
{
	for (int i = a; i < n; i++)
		s[i] = s[i + 1];
	--n;
}

void removesame(int *p, int &n)
{
	for (int i=0;i<(n-1);i++)
		for (int j = i; j < n; j++)
		{
			if (p[i] == p[j])
				removeone(p, n, j);
		}
	display(p, n);
}

int gcdtwo(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int gcdarray(int *p, int n) //6
{
	int ans;
	ans = gcdtwo(p[0], p[1]);
	for (int i = 2; i < n; i++)
		ans = gcdtwo(ans, p[i]);
	return ans;
}

void display(int *p, int n) //7
{
	for (int i = 0; i < n; i++)
		cout << p[i] << endl;
}

void save(char path[], int *p, int n) //8
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return;
	for (int i = 0; i < n; i++)
		fout << p[i] << endl;
	fout.close();
}