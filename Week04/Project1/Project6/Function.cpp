#include "Struct.h"

void listtonumb(Node *&head) 
{
	Node *cur = head;
	int x = 0;
	x = cur->data;
	while (cur->next != NULL) 
	{
		cur = cur->next;
		x = x * 10 + cur->data;
	}
	cout << x << endl;
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
