#include "Struct.h"

void numbtolist(Node *&head, char s[])
{
	int a = strlen(s);
	for (int i = a - 1; i >= 0; i--) {
		int j = s[i] - '0';
		insert(head, j);
	}
}

void divide(Node *&head1, Node *&head2)
{
	bool check;
	check = ifbigger(head1, head2);
	if (check == false)
	{
		cout << "0" << endl;
		return;
	}
	Node *cur1 = head1, *cur2 = head2,*ahead=NULL,*mhead = NULL, *result = NULL;
	int x;
	while (check)
	{
		x = cur1->data / cur2->data;
		ahead = NULL;
		if (x = 0) 
		{
			x = (cur1->data * 10 + cur1->next->data) / cur2->data;
			insert(ahead, x % 10);
			insert(ahead, x / 10);
		}
		else insert(ahead, x);
		mhead = multiplybi(head2, ahead);
		check = ifbigger(head1, mhead);
		while (check == false)
		{
			--x;
			ahead = NULL;
			if (x = 0)
			{
				x = (cur1->data * 10 + cur1->next->data) / cur2->data;
				insert(ahead, x % 10);
				insert(ahead, x / 10);
			}
			else insert(ahead, x);
			mhead = multiplybi(head2, ahead);
			check = ifbigger(head1, mhead);
		}
		insertlast(result, x);
		cur1 = substractbi(cur1, cur2);
		check = ifbigger(cur1, cur2);
	}

	Node *tmp = result;
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

Node* multiplybi(Node *&head1, Node *&head2)
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
	return shead;
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

void insertlast(Node *&head, int t)
{
	Node *tmp = new Node;
	tmp->data = t;
	tmp->next = NULL;
	tmp->prev = NULL;
	
	if (head == NULL)
		head = tmp;
	else
	{ 
		Node *cur = head;
		while (cur->next != NULL)
			cur = cur->next;
		tmp->prev = cur;
		cur->next = tmp;
	}
		
}