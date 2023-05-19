#include "Struct.h"

void reverse(Node *&head)
{
	Node *cur;
	cur = head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	head = cur;
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
		cur = cur->pre;
	}
	fout.close();
}