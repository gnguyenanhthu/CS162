#include "Struct.h"

int main()
{
	Node *head;
	head = NULL;
	load("D:\\APCS\\CS162\\Week05\\input.txt", head);
	reverse(head);
	save("D:\\APCS\\CS162\\Week05\\output5.txt", head);
	return 0;
}