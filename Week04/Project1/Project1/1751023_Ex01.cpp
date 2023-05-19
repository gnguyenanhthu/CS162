#include "Struct.h"

int main()
{
	Node *head = NULL;
	int a;
	load("D:\\APCS\\CS162\\Week04\\input.txt", head);
	cout << "Input a number: ";
	cin >> a;
	sortlist(head, a);
	save("D:\\APCS\\CS162\\Week04\\output1.txt", head);
	return 0;
}