#include "Struct.h"

int main()
{
	Node *head;
	head = NULL;
	load("D:\\APCS\\CS162\\Week05\\input.txt", head);
	inserteven(head);
	save("D:\\APCS\\CS162\\Week05\\output3.txt", head);
	return 0;
}