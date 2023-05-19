#include <iostream>
using namespace std;

struct Node {
	Node *next;
	int data;
};

struct Stack {
	Node *head;
	int size;
};


void init(Stack &s); //Ex01
void push(Stack &s, int a); //Ex02
int pop(Stack &s); //Ex03
bool checkempty(Stack &s); //Ex04
void makeempty(Stack &s); //Ex05
int countelements(Stack &s); //Ex06


void init(Stack &s) //Ex01
{
	s.head = NULL;
	s.size = 0;
}

void push(Stack &s, int a) //Ex02
{
	Node *tmp = new Node;
	tmp->data = a;
	tmp->next = s.head;
	s.head = tmp;
	++s.size;
}

int pop(Stack &s) //Ex03
{
	if (s.head == NULL)
		return -1;
	else
	{
		int pop = s.head->data;
		Node *tmp = s.head;
		s.head = s.head->next;
		delete tmp;
		--s.size;
		return pop;
	}
}

bool checkempty(Stack &s) //Ex04
{
	if (s.head == NULL)
		return true;
	else  return false;
}

void makeempty(Stack &s) //Ex05
{
	if (s.head == NULL)
		cout << "Stack is already empty" << endl;
	else
	{
		while (s.head != NULL)
		{
			Node *tmp = s.head;
			cout << "Delete " << s.head->data << endl;
			s.head = s.head->next;
			delete tmp;
			--s.size;
		}
	}
}

int countelements(Stack &s) //Ex06
{
	return s.size;
}

int main() {

	Stack s;

	init(s); //Ex01

	push(s,5); //Ex02
	push(s,1);

	cout << "Number of elements: " << countelements(s) << endl; //Ex06

	cout << "Pop element: " << pop(s) << endl; //Ex03


	if (checkempty(s))
		cout << "Stack is empty." << endl; //Ex04
	else
		cout << "Stack is not empty." << endl;

	makeempty(s); //Ex05

	system("pause");
	return 0;
}