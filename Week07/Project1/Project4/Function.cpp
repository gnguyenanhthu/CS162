#include "Function.h"

void HanoiTower(int n, char start, char tmp, char end)
{
	if (n == 1)
	{
		cout << "Move disk 1 from rod " << start << " to rod " << end << endl;
		return;
	}
	HanoiTower(n - 1, start, end, tmp);
	cout << "Move disk " << n << " from rod " << start << " to rod " << end << endl;
	HanoiTower(n - 1, tmp, start, end);
}
