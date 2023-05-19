#include<iostream>
#include<fstream>
using namespace std;

struct Node {
	Node *next;
	int data;
};

void load(char path[], Node *&head);
void save(char path[], Node *&head);

int main()
{
	Node *head=NULL;
	load("D:\\APCS\\CS162\\Week03\\input.txt", head);
	save("D:\\APCS\\CS162\\Week03\\output2.txt", head);
}

void load(char path[], Node *&head)
{
	Node *p, *cur = head;
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return;
	int n;
	fin >> n;//n=6
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
			p->next = head;
			head = p;
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
		fout << cur->data << " ";
		cur = cur->next;
	}
	fout.close();
}