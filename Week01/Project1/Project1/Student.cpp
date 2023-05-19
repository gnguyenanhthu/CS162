#include "Student.h"

void load(char path[], Student a[], int &n) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) {
		n = 0;
		return;
	}
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> a[i].id;
		while (fin.get() != '\n');
		fin.get(a[i].name, 30, '\n');
		fin >> a[i].socialID;
		fin >> a[i].dob.day >> a[i].dob.month >> a[i].dob.year;
		int x;
		fin >> x;
		if (x == 0)
			a[i].gender = MALE;
		if (x == 1)
			a[i].gender = FEMALE;
		if (x == 2)
			a[i].gender = NA;
		fin >> a[i].GPA;
	}
	fin.close();
}

void save(char path[], Student a[], int n) {
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		return;
	}
	fout << n << endl;
	for (int i = 0; i < n; i++) {
		fout << a[i].id << endl;
		fout << a[i].name << endl;
		fout << a[i].socialID << endl;
		fout << a[i].dob.day << " " << a[i].dob.month << " " << a[i].dob.year<<endl;
		fout << a[i].gender << endl;
		fout << a[i].GPA << endl;
	}
	fout.close();
}

void saveStudent(char path[], Student st) 
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		return;
	}
	else
	{
		fout << st.id << endl;
		fout << st.name << endl;
		fout << st.socialID << endl;
		fout << st.dob.day << " " << st.dob.month << " " << st.dob.year<<endl;
		fout << st.gender << endl;
		fout << st.GPA << endl;
	}
	fout.close();
}

void manyStudents(char path[], Student st)
{
	ofstream fout;
	fout.open(path,ios::app);
	if (!fout.is_open()) {
		return;
	}
	else
	{
		fout << st.id << endl;
		fout << st.name << endl;
		fout << st.socialID << endl;
		fout << st.dob.day << " " << st.dob.month << " " << st.dob.year<<endl;
		fout << st.gender << endl;
		fout << st.GPA << endl;
	}
	fout.close();
}

Student maxGPA(Student a[], int n) //Ex03
{
	Student ans = a[0];
	for (int i = 1; i < n; i++) 
	{
		if (a[i].GPA > ans.GPA)
			ans = a[i];
		else if ((a[i].GPA == ans.GPA) && (a[i].id < ans.id))
			ans = a[i];
	}
	return ans;
}

void belowaverage(char path[], Student a[], int n) //Ex04
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		return;
	}
	else
	for (int i = 0; i < n; i++) 
	{
		if (a[i].GPA < 5)
			manyStudents(path, a[i]);
	}
	fout.close();
}

void courses(char path[], Student a[], int n, int x) //Ex05
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		return;
	}
	else
	for (int i = 0; i < n; i++)
	{
		if ((a[i].id / 100000) == x)
			manyStudents(path, a[i]);
	}
	fout.close();
}

void findid(char path [], Student a[], int n, int x) //Ex06
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].id == x)
		{
			saveStudent(path, a[i]);
			return;
		}
	}
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		return;
	}
	else
		fout << "No student has this ID.";
	fout.close();
}

void findname(char path[], Student a[], int n, char s[]) //Ex07
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return;
	else
	{
		for (int i = 0; i < n; i++)
			if (_stricmp(a[i].name, s) == 0)
				manyStudents(path, a[i]);
	}
	fout.close();
}

void female(char path[], Student a[], int n) //Ex08
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		return;
	}
	else
	for (int i = 0; i < n; i++)
	{
		if (a[i].gender == 1)
			manyStudents(path, a[i]);
	}
	fout.close();
}

void male(char path[], Student a[], int n) //Ex09
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		return;
	}
	else
		for (int i = 0; i < n; i++)
		{
			if (a[i].gender == 0)
				manyStudents(path, a[i]);
		}
	fout.close();
}

void sortid(Student a[], int n) //Ex10
{
	Student b;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i].id < a[j].id)
			{
				b = a[i];
				a[i] = a[j];
				a[j]=b;
			}
		}
}

void sortname(Student a[], int n) //Ex11
{
	Student b;
	for (int i = 0; i < n; i++)
		for (int j = i; j<n; j++)
		{
			if (strcmp(a[i].name, a[j].name) > 0)
			{
				b = a[j];
				a[j] = a[i];
				a[i] = b;
			}
		}
}

void sortgpa(Student a[], int n) //Ex12
{
	Student b;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if ((a[i].GPA > a[j].GPA)||((a[i].GPA==a[j].GPA)&&(a[i].id < a[j].id)))
			{
				b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
		}
}

Student oldest(Student a[], int n) //Ex13
{
	Student ans = a[0];
	for (int i = 1; i < n; i++)
	{
		if ((ans.dob.year > a[i].dob.year) ||
			((ans.dob.year == a[i].dob.year) && (ans.dob.month > a[i].dob.month)) ||
			((ans.dob.year == a[i].dob.year) && (ans.dob.month == a[i].dob.month) && (ans.dob.day > a[i].dob.day)))
			ans = a[i];
		if ((ans.dob.year == a[i].dob.year) && (ans.dob.month == a[i].dob.month) && (ans.dob.day == a[i].dob.day) && (ans.id > a[i].id))
			ans = a[i];
	}
	return ans;
}

void top5(char path[], Student a[], int n) //Ex14
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return;
	else
	{
		sortgpa(a, n);
		Student b;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (((a[i].GPA == a[j].GPA) && (a[i].gender>a[j].gender))||((a[i].GPA == a[j].GPA) && (a[i].gender<a[j].gender)&&(a[i].id<a[j].id)))
				{
					b = a[i];
					a[i] = a[j];
					a[j] = b;
				}
		for (int k = 0; k < 5; k++)
			manyStudents(path, a[k]);
	}
	fout.close();
}

void bdthismonth(char path[], Student a[], int n) //Ex15
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return;
	else
	{
		time_t now = time(0);
		struct tm *t = localtime(&now);
		int x = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i].dob.month == (t->tm_mon + 1))
			{
				++x;
				manyStudents(path, a[i]);
			}
		}
		if (x == 0)
			fout << "Nobody has birthday in this month.";
		fout.close();
	}
}

void samebirthday(char path[], Student a[], int n) //Ex16
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) 
		return;
	else
	{
		int x = 0;
		for (int i = 0; i < n; i++)
			for (int j = (i + 1); j < n; j++)
				if ((a[j].dob.month == a[i].dob.month) && (a[j].dob.day == a[i].dob.day))
				{
					++x;
					manyStudents(path, a[i]);
					manyStudents(path, a[j]);
				}
		if (x == 0)
			fout << "No students have the same birthday.";
	}
	fout.close();
}

Student findrandom(Student a[], int n) //Ex17
{
	int numb = rand() % 90 + 10;
	Student ans = a[0];
	for (int i = 1; i < n; i++)
	{
		if ((abs((a[i].id % 100) - numb) < abs((ans.id % 100) - numb)) ||
			(abs((a[i].id % 100) - numb) == abs((ans.id % 100) - numb)) && ((a[i].id / 100000) > (ans.id / 100000)))
			ans = a[i];
	}
	return ans;
}

void group(char path[], Student a[], int n, int k) //Ex18
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return;
	else
	{
		Student b;
		for (int i = 0; i < n; i++)
			a[i].random = rand() % 100;
		for (int m = 0; m < n; m++)
			for (int j = 0; j < n; j++)
			{
				if (a[m].random > a[j].random)
				{
					b = a[m];
					a[m] = a[j];
					a[j] = b;
				}
			}
		int x = n / k, y = n%k;
		int c = 1, d = 0;
		if (y < k / 4)
		{
			for (int i = 0; i < x - y; i++)
			{
				fout << "Group " << c;
				for (int e = 0; e < k; e++)
				{
					manyStudents(path, a[d]);
					d++;
				}
				c++;
			}
			for (int i = 0; i < y; i++)
			{
				fout << "Group " << c;
				for (int e = 0; e < k; e++)
				{
					manyStudents(path, a[d]);
					d++;
				}
				c++;
			}
		}
		else
		{
			for (int i = 0; i < x - 1; i++)
			{
				fout << "Group " << c;
				for (int e = 0; e < k; e++)
				{
					manyStudents(path, a[d]);
					d++;
				}
				c++;
			}
			fout << "Group " << c;
			for (int e = 0; e < y; e++)
			{
				manyStudents(path, a[d]);
				d++;
			}
		}
		fout.close();
	}
}
void schoolyear(char path[], Student a[], int n) //Ex19
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return;
	else
	{
		int x[100] = { 0 }, j = 0, m=a[0].id/100000;
		x[0] = 1;
		sortid(a, n);
		for (int i = 0; i < (n - 1); i++)
		{
			if ((a[i].id / 100000) == (a[i + 1].id / 100000))
				++x[j];
			if ((a[i].id / 100000) != (a[i + 1].id / 100000))
			{
				++j;
				++x[j];
			}
		}
		for (int k = 0; k <= j; k++)
		{
			fout << "Khoa " << 2000 + m << " co " << x[k] << " sinh vien." << endl;
			++m;
		}
	}
	fout.close();
}

void bornmonth(char path[], Student a[], int n) //Ex20
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return;
	else
	{
		int x[12] = { 0 };
		for (int i = 0; i < n; i++)
			x[a[i].dob.month - 1]++;
		for (int j = 0; j < 12; j++)
			fout << "Thang " << j + 1 << " co sinh nhat cua " << x[j] << " sinh vien." <<endl;
	}
	fout.close();
}