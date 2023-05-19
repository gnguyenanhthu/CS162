#include "Struct.h"

int main()
{
	Node *head;
	head = NULL;
	load("D:\\APCS\\CS162\\Week05\\date.txt", head);
	date("D:\\APCS\\CS162\\Week05\\log6.txt","D:\\APCS\\CS162\\Week05\\output6.txt", head);
	return 0;
}