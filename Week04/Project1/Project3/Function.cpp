#include "Struct.h"

void divide(Node *&head, Node *&ohead, Node*&ehead)
{
	Node *cur, *ocur, *ecur;
	cur = head->next;
	ohead = head;
	ocur = ohead;
	ehead = head->next;
	ecur = ehead;
	while ((ocur->next != NULL) && (ecur->next!= NULL) && (cur->next!=NULL))
	{
		ocur->next = cur->next;
		ecur->next = cur->next->next;
		cur = cur->next;
		ocur = ocur->next;
		ecur = ecur->next;
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