#include "Struct.h"

void listsum(Node *&head, Node *&shead)
{
	Node *cur = head;
	shead = new Node;
	shead->data = head->data;
	shead->pre = NULL;

	Node *prev = shead;
	Node *last = new Node;
	prev->next = last;
	last->data = 0;
	last->pre = prev;
	last->next = NULL;

	while (cur->next != NULL)
	{
		Node *tmp = new Node;
		tmp->data = prev->data + cur->next->data;
		prev->next = tmp;
		tmp->pre = prev;
		prev = prev->next;
		tmp->next = last;
		last->pre = tmp;
		cur = cur->next;
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
	fin >> x;
	while(x!=0)
	{
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
		fin >> x;
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