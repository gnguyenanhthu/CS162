#include"Function.h"

int main()
{
	char s[100];
	cin.getline(s, 100);
	int l = 0, r = strlen(s) - 1;
	if (ispalindrome(l, r, s))
		cout << "Palindrome." << endl;
	else
		cout << "Not palindrome." << endl;
	system("pause");
	return 0;
}