#include "Struct.h"

void removedup(Node *&head)
{
	Node *cur;
	cur = head;
	while (cur->next != NULL)
	{
		Node *tmp;
		tmp = cur->next;
		while (tmp != NULL)
		{
			if (tmp->data == cur->data)
			{
				Node *del = tmp;
				tmp = tmp->next;
				del->pre->next = tmp;
				tmp->pre = del->pre;
				delete del;
			}
			else
				tmp = tmp->next;
		}
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