#include<iostream>
#include<fstream>
using namespace std;

struct Node {
	Node *next;
	int data;
};

struct List {
	Node *head;
};

void insertafter(Node *head, int x, int y);
void insertend(Node *head, int k);
void load(char path[], Node *&head);
void save(char path[], Node *&head);

int main()
{
	Node *head = NULL;
	int x, y;
	load("D:\\APCS\\CS162\\Week03\\input.txt", head);

	cout << "Input x: ";
	cin >> x;
	cout << "Input y: ";
	cin >> y;
	insertafter(head, x, y);
	save("D:\\APCS\\CS162\\Week03\\output3.txt", head);
}

void insertafter(Node *head, int x, int y)
{
	Node *cur = head;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			Node *tmp;
			tmp = new Node;
			tmp->data = y;
			tmp->next = cur->next;
			cur->next = tmp;
			cur = tmp;
			return;
		}
		else
			cur = cur->next;
	}
	insertend(head, y);
}

void insertend(Node *head, int k)
{
	Node *tmp, *cur = head;
	tmp = new Node;
	tmp->data = k;
	tmp->next = NULL;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = tmp;
}

void load(char path[], Node *&head)
{
	Node *p, *cur = head;
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return;
	int n;
	fin >> n;
	for (int i = 0; i<n; ++i)
	{
		int x;
		fin >> x;
		p = new Node;
		p->data = x;
		p->next = NULL;

		if (head == NULL)
		{
			head = p;
			cur = head;
		}
		else
		{
			cur->next = p;
			cur = p;
		}
	}
	fin.close();
}

void save(char path[], Node *&head)
{
	Node *cur = head;
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		return;
	}
	while (cur != NULL)
	{
		fout << cur->data << " ";
		cur = cur->next;
	}
	fout.close();
}