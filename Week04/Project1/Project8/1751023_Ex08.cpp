#include "Struct.h"

int main()
{
	Node *ohead = NULL, *ehead = NULL;
	load("D:\\APCS\\CS162\\Week04\\even.txt", ehead);
	load("D:\\APCS\\CS162\\Week04\\odd.txt", ohead);
	share(ohead, ehead);
	system("pause");
	return 0;
}