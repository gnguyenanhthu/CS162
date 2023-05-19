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

void removefirst(Node *&head);
void load(char path[], Node *&head);
void save(char path[], Node *&head);

int main()
{
	Node *head = NULL;
	load("D:\\APCS\\CS162\\Week03\\input.txt", head);
	removefirst(head);
	save("D:\\APCS\\CS162\\Week03\\output5.txt", head);
}

void removefirst(Node *&head)
{
	if (head == NULL)
		return;
	Node *cur = head;
	head = cur->next;
	delete cur;
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