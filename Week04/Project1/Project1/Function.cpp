#include "Struct.h"

void sortlist(Node *&head, int& a)
{
	Node *pre, *cur, *p;
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
		pre = head;
		for (cur = head->next; cur != NULL; cur = cur->next)
		{
			if (pre->data <= a && cur->data > a)
			{
				pre->next = p;
				p->next = cur;
				break;
			}
			pre = cur;
		}
		if (cur == NULL)
		{
			pre->next = p;
			p->next = NULL;
		}
	}
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
		fout << cur->data << endl;
		cur = cur->next;
	}
	fout.close();
}