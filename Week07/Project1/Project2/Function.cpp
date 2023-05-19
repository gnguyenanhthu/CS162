#include"Function.h"

bool ispalindrome(int l, int r, char s[])
{
	if (l == r || (l == (r - 1) && s[l] == s[r])) return true;
	if (s[l] != s[r]) return false;
	return ispalindrome(l + 1, r - 1, s);
}