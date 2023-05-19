#include "Struct.h"

void numbtolist(Node *&head, char s[])
{
	int a = strlen(s);
	for (int i = a - 1; i >= 0; i--) {
		int j = s[i] - '0';
		insert(head, j);
	}
}

void mod(Node *head1, Node *head2) 
{
	Node *cur1 = head1, *cur2 = head2, *modhead = NULL;
	if (!ifbigger(head1, head2)) 
	{
		modhead = new Node;
		modhead->data = 0;
		modhead->next = NULL;
		modhead->prev = NULL;
		cout << "0" << endl;
		return;
	}
	while (ifbigger(head1, head2))
	{
		head1 = substractbi(head1, head2);
	}

	Node *tmp = head1;
	while (tmp != NULL)
	{
		cout << tmp->data;
		tmp = tmp->next;
	}
}

bool ifbigger(Node *&head1, Node *&head2)
{
	Node *cur1 = head1, *cur2 = head2;
	int len1 = 0, len2 = 0;

	while (cur1 != NULL)
	{
		len1++;
		cur1 = cur1->next;
	}
	while (cur2 != NULL)
	{
		len2++;
		cur2 = cur2->next;
	}

	if (len1 > len2) return true;
	if (len2 > len1) return false;

	if (len1 == len2)
	{
		cur2 = head2;
		cur1 = head1;
		while (cur1 != NULL)
		{
			if (cur1->data > cur2->data) return true;
			if (cur2->data < cur1->data) return false;
			cur2 = cur2->next;
			cur1 = cur1->next;
		}
	}
	return true;
}

Node* substractbi(Node *&head1, Node *&head2)
{
	bool check;
	Node *cur1 = head1, *cur2 = head2, *ahead = NULL;
	check = ifbigger(head1, head2);

	if (check == false)
	{
		cout << "-";
		cur1 = head2;
		cur2 = head1;
	}

	while (cur1->next != NULL)
		cur1 = cur1->next;

	while (cur2->next != NULL)
		cur2 = cur2->next;

	bool a = 0;
	int subs;
	while (cur1 != NULL || cur2 != NULL)
	{
		subs = 0;
		subs -= a;
		a = 0;

		if (cur1)
		{
			subs += cur1->data;
			cur1 = cur1->prev;
		}

		if (cur2)
		{
			subs -= cur2->data;
			cur2 = cur2->prev;
		}

		a = (subs > 0);
		if (subs<0)
			subs = subs*(-1);
		insert(ahead, subs);
	}
	return ahead;
}

void insert(Node *&head, int t)
{
	Node *tmp = new Node;
	tmp->data = t;
	tmp->next = NULL;
	tmp->prev = NULL;

	if (head != NULL)
	{
		tmp->next = head;
		head->prev = tmp;
		head = tmp;
	}
	else
		head = tmp;
}