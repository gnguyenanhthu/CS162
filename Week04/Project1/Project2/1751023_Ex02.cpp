#include "Struct.h"

int main()
{
	Node *head = NULL;
	load("D:\\APCS\\CS162\\Week04\\input.txt", head);
	listsum(head);
	save("D:\\APCS\\CS162\\Week04\\output2.txt", head);
	return 0;
}