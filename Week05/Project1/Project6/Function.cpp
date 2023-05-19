#include "Struct.h"

void date(char path1[], char path2[], Node *&head)
{
	Node *cur = head;
	ofstream fout1;
	ofstream fout2;
	fout1.open(path1);
	if (!fout1.is_open()) {
		return;
	}
	fout2.open(path2);
	if (!fout2.is_open()) {
		return;
	}
	
	while (cur->next != head)
		cur = cur->next;
	
	while (cur->next != cur) 
	{
		srand(time(NULL));
		int a = rand() % 6 + 1;
		int b = a - 1;
		
		while (b--)
			cur = cur->next;
		
		Node *tmp = cur->next;
		fout1 << "Dice: " << a << endl;
		fout1 << tmp->id << endl;
		fout1 << tmp->name << endl;
		cur->next = tmp->next;
		delete tmp;
	}
	fout2 << cur->id << endl;
	fout2 << cur->name << endl;
	fout1.close();
	fout2.close();
}

void load(char path[], Node *&head)
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) {
		return;
	}
	Node *p, *cur = head;
	int x;
	fin >> x;
	for (int i=0;i<x;i++)
	{
		p = new Node;
		fin >> p->id;
		fin.getline(p->name, 50, '\n');
		fin.ignore(50,'\n');
		
		if (head == NULL)
		{
			head = p;
			cur = head;
			cur->next = head;
		}
		else
		{
			cur->next = p;
			cur = p;
			cur->next = head;
		}
	}
	fin.close();
}


