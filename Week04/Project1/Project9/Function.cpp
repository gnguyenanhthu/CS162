#include "Struct.h"

void loop(Node *head)
{
	Node *cur, *last;
	cur = head;
	last = head;
	while (last->data != 0)
		last = last->next;
	while (cur != NULL)
	{
		if (last->next == cur)
		{
			cout << "There's a loop at " << cur->data << endl;
			return;
		}
		else
			cur = cur->next;
	}
	cout << "There's no loop" << endl;
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

