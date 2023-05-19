#include "Struct.h"

int main()
{
	Node *ohead = NULL, *ehead = NULL;
	load("D:\\APCS\\CS162\\Week04\\even.txt", ehead);
	load("D:\\APCS\\CS162\\Week04\\odd.txt", ohead);
	join(ohead, ehead);
	save("D:\\APCS\\CS162\\Week04\\output5.txt", ohead);
	return 0;
}