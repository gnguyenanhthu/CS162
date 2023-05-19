#include "Struct.h"

int main()
{
	Node *head = NULL;
	int x;
	cout << "Please input x: ";
	cin >> x;
	numbtolist(x,head);
	save("D:\\APCS\\CS162\\Week04\\output7.txt", head);
	system("pause");
	return 0;
}