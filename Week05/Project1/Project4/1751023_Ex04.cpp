#include "Struct.h"

int main()
{
	Node *head;
	head = NULL;
	load("D:\\APCS\\CS162\\Week05\\input.txt", head);
	removedup(head);
	save("D:\\APCS\\CS162\\Week05\\output4.txt", head);
	return 0;
}