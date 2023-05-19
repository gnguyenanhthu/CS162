#include "Struct.h"

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
	Node* cur = head;
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

void insertasc(Node *&head, int& a)
{
	Node *prev, *cur, *p;
	p = new Node;
	p->data = a;
	p->next = NULL;

	if (a < head->data)
	{
		p->next = head;
		head = p;
	}
	else
	{
		prev = head;
		prev->pre = NULL;
		for (cur = head->next; cur != NULL; cur = cur->next)
		{

			if (prev->data <= a && cur->data > a)
			{
				prev->next = p;
				p->next = cur;

				p->pre = prev;
				cur->pre = p;
				break;
			}
			prev = cur;
		}
		if (cur == NULL)
		{
			prev->next = p;
			p->next = NULL;
			p->pre = prev;
		}
	}
}
