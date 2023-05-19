#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

struct Queue {
	Node *head;
	Node *tail;
};

void init(Queue &q); //Ex01
void enqueue(Queue &q, int a); //Ex02
void dequeue(Queue &q); //Ex03
bool checkempty(Queue &q); //Ex04
void makeempty(Queue &q); //Ex05
int countelements(Queue q); //Ex06


void init(Queue &q) //Ex01
{
	q.head = NULL;
	q.tail = NULL;
}

void enqueue(Queue &q, int a) //Ex02
{
	if (q.head == NULL && q.tail==NULL)
	{
		q.head = new Node;
		q.head->data = a;
		q.tail = q.head;
		q.head->next = NULL;
	}
	else
	{
		Node *tmp = new Node;
		tmp->data = a;
		tmp->next = NULL;
		q.tail->next = tmp;
		q.tail = tmp;
	}
}

void dequeue(Queue &q) //Ex03
{
	if (q.head == NULL)
	{
		cout << "The list is empty." << endl;
		return;
	}
	else
	{
		int pop = q.head->data;
		Node *tmp = q.head;
		q.head = q.head->next;
		cout << "Delete " << tmp->data << endl;
		delete tmp;
	}
}

bool checkempty(Queue &q) //Ex04
{
	if (q.head == NULL)
		return true;
	else  return false;
}

void makeempty(Queue &q) //Ex05
{
	if (q.head == NULL)
		cout << "Stack is already empty" << endl;
	else
		while (q.head != NULL)
			dequeue(q);
}

int countelements(Queue q) //Ex06
{
	int c = 1;
	while (q.head != q.tail)
	{
		q.head = q.head->next;
		++c;
	}
	return c;
}

int main() 
{
	Queue q;

	init(q); //Ex01

	enqueue(q, 5); //Ex02
	enqueue(q, 1);

	cout << "Number of elements: " << countelements(q) << endl; //Ex06

	dequeue(q); //Ex03

	if (checkempty(q))
		cout << "Stack is empty." << endl; //Ex04
	else
		cout << "Stack is not empty." << endl;

	makeempty(q); //Ex05

	system("pause");
	return 0;
}