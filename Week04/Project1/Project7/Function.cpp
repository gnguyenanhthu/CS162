#include "Struct.h"

void numbtolist(int x, Node *&head)
{
	int a = x % 10;
	Node *cur = head, *tmp;
	while (x > 0) 
	{
		if (head == NULL) 
		{
			head = new Node;
			head->next = NULL;
			head->data = a;
			cur = head;
		}
		else 
		{
			tmp = new Node;
			tmp->data = a;
			tmp->next = cur;
			head = tmp;
			cur = head;
		}
		x = x / 10;
		a = x % 10;
	}
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