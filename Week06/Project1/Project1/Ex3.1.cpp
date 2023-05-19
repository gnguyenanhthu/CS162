#include <iostream>
using namespace std;

struct Stack {
	int *data;
	int top;
	int size;
};


void init(Stack &s, int maxsize); //Ex01
void push(Stack &s, int a); //Ex02
int pop(Stack &s); //Ex03
bool checkempty(Stack &s); //Ex04
void makeempty(Stack &s); //Ex05
int countelements(Stack &s); //Ex06


void init(Stack &s, int maxsize)
{
	int *content;
	content = new int[maxsize];
	if (content == NULL) return;
	s.top = -1;
	s.size = maxsize;
	s.data = content;
}

void push(Stack &s, int a)
{
	++s.top;
	s.data[s.top] = a;
	++s.size;
}

int pop(Stack &s)
{
	if (s.top == -1)
	{
		return -1;
	}
	--s.top;
	return s.data[++s.top];
}

bool checkempty(Stack &s)
{
	if (s.top == -1)
		return true;
	return false;
}

void makeempty(Stack &s)
{
	if (s.top == -1)
		cout << "Stack is already empty." << endl;
	else
		while (s.top!=-1)
		{
			int tmp;
			tmp = pop(s);
			--s.top;
			cout << "Delete " << tmp << endl;
		}
}

int countelements(Stack &s)
{
	return s.top + 1;
}

int main()
{
	Stack s;
	int ms;

	cin >> ms;

	init(s,ms); //Ex01

	push(s,5); //Ex02
	push(s,1);

	cout << "Number of elements: " << countelements(s) << endl; //Ex06

	cout << "Pop element: " << pop(s) << endl; //Ex03

	if (checkempty(s)) //Ex04
		cout << "Stack is empty." << endl;
	else
		cout << "Stack is not empty." << endl;

	makeempty(s); //Ex05

	system("pause");
	return 0;
}
