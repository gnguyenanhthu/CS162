#include "Struct.h"

int main()
{
	Node *head = NULL, *ohead = NULL, *ehead=NULL;
	load("D:\\APCS\\CS162\\Week04\\input.txt", head);
	divide(head, ohead, ehead);
	save("D:\\APCS\\CS162\\Week04\\divideodd.txt", ohead);
	save("D:\\APCS\\CS162\\Week04\\divideeven.txt", ehead);
	return 0;
}