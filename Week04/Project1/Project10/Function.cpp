#include "Struct.h"

void input(Book *&head)
{
	Book *tmp;
	tmp = new Book;
	cout << "Title: ";
	cin.getline(tmp->title, 200, '\n');
	cout << "Author: ";
	cin.getline(tmp->author, 40, '\n');
	cout << "Language: ";
	cin.getline(tmp->language, 30, '\n');
	cout << "ISBN: ";
	cin >> tmp->ISBN;
	cout << "Year published: ";
	cin >> tmp->yp;
	cout << "Price: ";
	cin >> tmp->price;
	cout << "Stock level: ";
	cin >> tmp->stlevel;
	tmp->next = NULL;
	if (head == NULL)
		head = tmp;
	else
	{
		Book *cur;
		cur = head;
		while (cur ->next != NULL)
		{
			if (cur->ISBN == tmp->ISBN)
			{
				cur->stlevel = cur->stlevel + tmp->stlevel;
				delete tmp;
				return;
			}
			cur = cur->next;
		}
		cur->next = tmp;
	}
}

void sellabook(int x, Book *&head)
{
	Book *cur;
	cur = head;
	while (cur != NULL)
	{
		if (cur->ISBN == x)
		{
			cout << "Title: " << cur->title << endl;
			cout << "Price: " << cur->price << endl;
			if (cur->stlevel == 0)
			{
				cout << "Out of stock." << endl;
				return;
			}
			else
			{
				cur->stlevel = cur->stlevel - 1;
				return;
			}
		}
		else
			cur = cur->next;
	}
}

void findbook(char s[], Book *&head)
{
	Book *cur;
	cur = head;
	int a, b;
	a = strlen(s);
	while (cur != NULL)
	{
		b = strlen(cur->title);
		for(int i=0;i<(a-1);i++)
			for(int j=0;j<(b-1);j++)
				if ((s[i] == cur->title[j]) && (s[i + 1] == cur->title[j + 1]))
				{
					cout << "Title: " << cur->title << endl;
					cout << "ISBN: " << cur->ISBN << endl;
				}
		cur = cur->next;
	}
}

void remove(int k, Book *&head)
{
	Book *cur, *pre;
	pre = head; cur = head->next;
	while (cur != NULL)
	{
		if (head->stlevel < k)
		{
			Book *tmp;
			tmp = pre;
			pre = pre->next;
			cur = cur->next;
			head = head->next;
		}
		if (cur->stlevel < k)
		{
			Book *tmp;
			tmp = cur;
			cur = cur->next;
			delete tmp;
			pre->next = cur;
		}
		pre = cur;
		cur = cur->next;
	}
}