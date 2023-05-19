#include "Function.h"

int main()
{
	int n;
	cout << "Input number of disks: ";
	cin >> n;
	HanoiTower(n, 'A', 'B', 'C');
	system("pause");
	return 0;
}