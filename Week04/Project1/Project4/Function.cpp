#include "Struct.h"

void combine(Node *&ohead, Node*&ehead)
{
	Node *cur = ohead->next, *ocur = ohead, *ecur = ehead;
	while (ocur->next != NULL) 
	{
		cur = ocur->next;
		ocur->next = ecur;
		ecur = ecur->next;
		ocur->next->next = cur;
		ocur = ocur->next->next;
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