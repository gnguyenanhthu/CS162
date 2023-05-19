#include "Struct.h"

void inserteven(Node *&head)
{
	Node *cur;
	cur = head;
	int x = 2;
	while (cur != NULL)
	{
		if (cur == head)
		{
			Node *tmp;
			tmp = new Node;
			tmp->data = x;
			tmp->next = head;
			tmp->pre = NULL;
			cur->pre = tmp;
			head = tmp;
			cur = cur->next;
			x = x + 2;
		}
		else
		{
			Node *tmp;
			tmp = new Node;
			tmp->data = x;
			tmp->next = cur;
			tmp->pre = cur->pre;
			cur->pre->next = tmp;
			cur->pre = tmp;
			cur = cur->next;
			x = x + 2;
		}
	}
}


void load(char path[], Node *&head)
{
	Node* p, *cur = head;
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) {
		return;
	}
	int x;
	do
	{
		fin >> x;
		p = new Node;
		p->data = x;
		p->next = NULL;
		p->pre = NULL;

		if (head == NULL)
		{
			head = p;
			cur = head;
		}
		else
		{
			cur->next = p;
			cur->next->pre = cur;
			cur = p;

		}
	} while (x != 0);
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
		fout << cur->data << endl;
		cur = cur->next;
	}
	fout.close();
}