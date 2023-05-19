#include <iostream>
#include<fstream>
using namespace std;

void splitnumpart(char *source, char *destination, char *numpart);
void splitsize(char *source, char *destination, char *s);
void splitnpremove(char *source, char *destination, char *numpart);
void splitsizeremove(char *source, char *destination, char *s);
void showhelp();

int main(int n, char *argv[])
{
	if (argv[1] == "\?") showhelp();
	else
	{
		if (argv[1] == "-split") 
		{
			if (n == 5)
			{
				if (argv[4] == "-numpart") splitnumpart(argv[2], argv[3], argv[5]);
				else splitsize(argv[2], argv[3], argv[5]);
			}
			if (n == 6)
			{
				if (argv[4] == "-numpart") splitnumpart(argv[2], argv[3], argv[5]);
				else splitsize(argv[2], argv[3], argv[5]);
			}
		}
	}
	return 0;
}

void splitnumpart(char *source, char *destination, char *numpart)
{
	ifstream fin;
	ofstream fout;

	fin.open(source, ios::binary);

	int n = chartoint(numpart);
	long size;
	fin.seekg(0, ifstream::end);
	size = fin.tellg();
	fin.seekg(0);

	char e[10];
	exert(source, e);

	int partsize;
	partsize = size / n;

	for (int i = 1; i <= n; i++)
	{
		char *tmp;
		inttochar(i, tmp);
		string link;
		link = string(destination) + string(tmp) + string(e);
		fout.open(link, ios::binary);
		
		char *b;
		b = new char[partsize];
		fin.read(b, partsize);
		fout.write(b, partsize);

		delete [] b;

		fout.close();
	}
	fin.close();
}

void splitnpremove(char *source, char *destination, char *numpart)
{
	ifstream fin;
	ofstream fout;

	fin.open(source, ios::binary);

	int n = chartoint(numpart);
	long size;
	fin.seekg(0, ifstream::end);
	size = fin.tellg();
	fin.seekg(0);

	char e[10];
	exert(source, e);

	int partsize;
	partsize = size / n;

	for (int i = 1; i <= n; i++)
	{
		char *tmp;
		inttochar(i, tmp);
		string link;
		link = string(destination) + string(tmp) + string(e);
		fout.open(link, ios::binary);

		char *b;
		b = new char[partsize];
		fin.read(b, partsize);
		fout.write(b, partsize);

		delete[] b;

		fout.close();
	}
	fin.close();
	remove(source);
}

void splitsize(char *source, char *destination, char *s)
{
	ifstream fin;
	ofstream fout;

	fin.open(source, ios::binary);

	int n = chartoint(s);
	long size;
	fin.seekg(0, ifstream::end);
	size = fin.tellg();
	fin.seekg(0);

	char e[10];
	exert(source, e);

	int i = 1;
	int count=size;

	while(count>=0 && count>n)
	{
		char *tmp;
		inttochar(i, tmp);
		string link;
		link = string(destination) + string(tmp) + string(e);
		fout.open(link, ios::binary);

		char *b;
		b = new char[n];
		fin.read(b, n);
		fout.write(b, n);

		delete[] b;

		fout.close();
		i++;
		count = count - n;
	}
	if (count != 0)
	{
		if (count < 0)
			count = count*-1;

		i++;
		char *tmp;
		inttochar(i, tmp);
		string link;
		link = string(destination) + string(tmp) + string(e);
		fout.open(link, ios::binary);

		char *b;
		b = new char[count];
		fin.read(b, count);
		fout.write(b, count);

		delete[] b;

		fout.close();
	}
	fin.close();
}

void splitsizeremove(char *source, char *destination, char *s)
{
	ifstream fin;
	ofstream fout;

	fin.open(source, ios::binary);

	int n = chartoint(s);
	long size;
	fin.seekg(0, ifstream::end);
	size = fin.tellg();
	fin.seekg(0);

	char e[10];
	exert(source, e);

	int i = 1;
	int count = size;

	while (count >= 0 && count>n)
	{
		char *tmp;
		inttochar(i, tmp);
		string link;
		link = string(destination) + string(tmp) + string(e);
		fout.open(link, ios::binary);

		char *b;
		b = new char[n];
		fin.read(b, n);
		fout.write(b, n);

		delete[] b;

		fout.close();
		i++;
		count = count - n;
	}
	if (count != 0)
	{
		if (count < 0)
			count = count*-1;

		i++;
		char *tmp;
		inttochar(i, tmp);
		string link;
		link = string(destination) + string(tmp) + string(e);
		fout.open(link, ios::binary);

		char *b;
		b = new char[count];
		fin.read(b, count);
		fout.write(b, count);

		delete[] b;

		fout.close();
	}
	fin.close();
	remove(source);
}

void showhelp()
{
	cout << "This is a split and join program. ";
	system("pause");
}

int chartoint(char *s) 
{
	int p = 0;
	for (int i = 0; i < strlen(s); i++) {
		p = p * 10 + s[i] - '0';
	}
	return p;
}

void inttochar(int x, char *s) 
{
	int i = 0;
	while (x != 0) 
	{
		s[i] = x % 10 + '0';
		x = x / 10;
		i++;
	}
	_strrev(s);
}

void exert(char *source, char *e) 
{
	int m = 0;
	for (int i = 0; i < strlen(source); i++)
		if (source[i] == '.') m = i;
	int t = 0;
	for (int i = m; i <= strlen(source); i++) 
	{
		e[t] = source[i];
		t++;
	}
	_strrev(e);
}