#include "Struct.h"

int main()
{
	Node *head1 = NULL, *head2 = NULL;
	char s1[100], s2[100];
	cin.get(s1, 100, '\n');
	cin.ignore(100, '\n');
	cin.get(s2, 100, '\n');
	numbtolist(head1, s1);
	numbtolist(head2, s2);
	multiplybi(head1, head2);
	system("pause");
}