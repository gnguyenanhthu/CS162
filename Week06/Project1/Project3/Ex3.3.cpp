#include <iostream>
using namespace std;

struct Queue {
	int *data;
	int in;
	int out;
	int size;
};


void init(Queue &q, int maxsize); //Ex01
void enqueue(Queue &q, int x); //Ex02
void dequeue(Queue &q); //Ex03
bool checkempty(Queue &q); //Ex04
int countelements(Queue &q); //Ex05
void makeempty(Queue &q); //Ex06


void init (Queue &q, int maxsize) //Ex01
{
	q.size = maxsize;
	q.in = 0;
	q.out = 0;
	q.data = new int[maxsize];
}

void enqueue(Queue &q, int x) //Ex02
{
	if (q.in >= q.size) 
		return;
	q.data[q.in] = x;
	q.in++;
}

void dequeue(Queue &q) //Ex03
{
	if (checkempty(q))
		cout << "The list is already empty." << endl;
	else 
	{
		cout << "Delete " << q.data[q.out] << endl;
		++q.out;
	}
}

int countelements(Queue &q) //Ex05
{
	return (q.in - q.out);
}

bool checkempty(Queue &q) //Ex04
{
	if (q.in==q.out)
		return true;
	return false;
}

void makeempty(Queue &q) //Ex06
{
	while (q.in != q.out)
		++q.out;
}

int main()
{
	Queue q;
	
	int ms;
	cin >> ms;
	init(q, ms); //Ex01

	enqueue(q, 5); //Ex02
	enqueue(q, 1);

	cout << "Number of elements: " << countelements(q) << endl; //Ex05

	dequeue(q); //Ex03

	checkempty(q); //Ex04

	makeempty(q); //Ex06

	system("pause");
	return 0;
}
