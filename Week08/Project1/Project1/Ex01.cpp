#include <iostream>
#include<fstream>
using namespace std;

void copy1(char *source, char *destination);
void copy2(char *source, char *destination, char *filename);
void copyremove1(char *source, char *destination);
void copyremove2(char *source, char *destination, char *filename);
void showhelp();

int main(int n,char *argv[])
{
	if (argv[1] == "\?") showhelp();
	else
	{
		if (n == 3)
			copy1(argv[1], argv[2]);
		if (n == 4)
		{
			if (argv[3] == "-removesource")
				copyremove1(argv[1], argv[2]);
			else
				copy2(argv[1], argv[2], argv[3]);
		}
		if (n == 5)
			copyremove2(argv[1], argv[2], argv[3]);
	}
	return 0;
}

void copy1(char *source, char *destination)
{
	ifstream fin;
	ofstream fout;
	char s[10];

	fin.open(source, ios::binary);
	fout.open(destination, ios::binary);

	while (fin.eof() == false)
	{
		fin.read(s, 10);
		fout.write(s, fin.gcount());
	}

	fin.close();
	fout.close();
}

void copy2(char *source, char *destination, char *filename)
{
	ifstream fin;
	ofstream fout;
	char s[10];

	fin.open(source, ios::binary);

	string link;
	link = string(source) + string(filename);

	fout.open(link, ios::binary);

	while (fin.eof() == false)
	{
		fin.read(s, 10);
		fout.write(s, fin.gcount());
	}

	fin.close();
	fout.close();
}

void copyremove1(char *source, char *destination)
{
	ifstream fin;
	ofstream fout;
	char s[10];

	fin.open(source, ios::binary);
	fout.open(destination, ios::binary);

	while (fin.eof() == false)
	{
		fin.read(s, 10);
		fout.write(s, fin.gcount());
	}

	remove(source);
	fin.close();
	fout.close();
}

void copyremove2(char *source, char *destination, char *filename)
{
	ifstream fin;
	ofstream fout;
	char s[10];

	fin.open(source, ios::binary);

	string link;
	link = string(source) + string(filename);

	fout.open(link, ios::binary);

	while (fin.eof() == false)
	{
		fin.read(s, 10);
		fout.write(s, fin.gcount());
	}
	
	fin.close();
	fout.close();
	remove(source);
}

void showhelp()
{
	cout << "This is a copy program. " << endl;
	system("pause");
}