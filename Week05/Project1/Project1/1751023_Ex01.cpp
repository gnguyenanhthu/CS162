#include "Struct.h"

int main()
{
	Node *head;
	head = NULL;
	int a;
	cin >> a;
	load("D:\\APCS\\CS162\\Week05\\input.txt", head);
	insertasc(head, a);
	save("D:\\APCS\\CS162\\Week05\\output1.txt", head);
	return 0;
}