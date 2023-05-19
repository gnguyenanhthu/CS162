#include "Function.h"

int main() {
	cout << "Enter n: ";
	int n; cin >> n;

	int *ans = new int[n];
	for (int i = 0; i < n; ++i) ans[i] = -1;
	bool *column = new bool[n];
	for (int i = 0; i < n; ++i) column[i] = false;

	bool *mainDiagonal = new bool[2 * n - 1];
	for (int i = 0; i < 2 * n - 1; ++i) mainDiagonal[i] = false;

	bool *subDiagonal = new bool[2 * n - 1];
	for (int i = 0; i < 2 * n - 1; ++i) subDiagonal[i] = false;

	PutQueen(0, n, 0, ans, column, mainDiagonal, subDiagonal);

	delete[] column;
	delete[] subDiagonal;
	delete[] mainDiagonal;

	system("pause");
	return 0;
}