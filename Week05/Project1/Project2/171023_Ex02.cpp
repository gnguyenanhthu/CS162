#include "Struct.h"

int main()
{
	Node *head, *shead;
	head = NULL; shead = NULL;
	load("D:\\APCS\\CS162\\Week05\\input.txt", head);
	listsum(head, shead);
	save("D:\\APCS\\CS162\\Week05\\output2.txt", shead);
	return 0;
}