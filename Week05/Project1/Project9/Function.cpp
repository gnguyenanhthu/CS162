#include "Struct.h"

void numbtolist(Node *&head, char s[])
{
	int a = strlen(s);
	for (int i = a - 1; i >= 0; i--) {
		int j = s[i] - '0';
		insert(head, j);
	}
}

void multiplybi(Node *&head1, Node *&head2)
{
	Node *cur1 = NULL, *last1 = head1, *cur2 = head2, *ahead = NULL, *shead = NULL;

	while (last1->next != NULL)
		last1 = last1->next;

	while (cur2->next != NULL)
		cur2 = cur2->next;

	int m, x = 0, y, z = 0;
	while (cur2 != NULL)
	{
		cur1 = last1;
		while (cur1 != NULL)
		{
			m = cur1->data*cur2->data + x;
			y = m % 10;
			x = m / 10;
			cur1 = cur1->prev;
			insert(ahead, y);
		}
		if (x > 0)
			insert(ahead, x);
		if (z == 0)
			shead = ahead;
		else
			shead = plusbi(shead, ahead);
		cur2 = cur2->prev;
		++z;
		ahead = NULL;
		for (int i = 0; i < z; i++)
			insert(ahead, 0);
	}

	Node *tmp = shead;
	while (tmp != NULL)
	{
		cout << tmp->data;
		tmp = tmp->next;
	}
}

Node* plusbi(Node *&head1, Node *&head2)
{
	Node *cur1 = head1, *cur2 = head2, *ahead = NULL;
	while (cur1->next != NULL)
		cur1 = cur1->next;

	while (cur2->next != NULL)
		cur2 = cur2->next;

	bool a = 0;
	int sum;
	while (cur1 != NULL || cur2 != NULL)
	{
		sum = 0;
		sum += a;
		a = 0;

		if (cur1)
		{
			sum += cur1->data;
			cur1 = cur1->prev;
		}

		if (cur2)
		{
			sum += cur2->data;
			cur2 = cur2->prev;
		}

		a = (sum >= 10);
		sum %= 10;
		insert(ahead, sum);
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