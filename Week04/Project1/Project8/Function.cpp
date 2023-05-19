#include"Struct.h"

void share(Node *&ohead, Node *&ehead) 
{
	Node *ocur = ohead, *ecur = ehead;
	while (ocur != NULL) 
	{
		while (ecur != NULL) 
		{
			if (ocur == ecur) 
			{
				cout << "There's common node at " << ocur->data << endl;
				return;
			}
			ecur = ecur->next;
		}
		ecur = ehead;
		ocur = ocur->next;
	}
	cout << "There's no common node." << endl;
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

