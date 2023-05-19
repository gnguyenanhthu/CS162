#include "Struct.h"

int main()
{
	Book *head = NULL;
	int x, k;
	char s[200];
	
	input(head);
	
	cout << "Input ISBN of a book you want to buy: ";
	cin >> x;
	sellabook(x, head);

	cout << "Input a threshold: ";
	cin >> k;
	remove(k, head);

	cout << "Input title of a book you want to find: ";
	cin.getline(s, 200, '\n');
	findbook(s, head);

	system("pause");
	return 0;

}