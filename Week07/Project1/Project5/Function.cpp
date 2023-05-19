#include "Function.h"

void PutQueen(int i, int n, int cnt, int *ans, bool *column, bool *mainDiagonal, bool *subDiagonal) {
	if (i == n) 
	{
		int maxQueen = n;
		if (n == 2 || n == 3) --maxQueen;
		if (cnt == maxQueen) {
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < n; ++y)
					if (ans[x] == y) cout << "Q";
					else cout << ".";
					cout << endl;
			}
			cout << endl;
		}
		return;
	}
	PutQueen(i + 1, n, cnt, ans, column, mainDiagonal, subDiagonal);
	for (int j = 0; j < n; ++j) 
	{
		if (!column[j] && !mainDiagonal[i + j] && !subDiagonal[i - j + n - 1]) 
		{
			ans[i] = j;
			column[j] = mainDiagonal[i + j] = subDiagonal[i - j + n - 1] = true;
			PutQueen(i + 1, n, cnt + 1, ans, column, mainDiagonal, subDiagonal);
			column[j] = mainDiagonal[i + j] = subDiagonal[i - j + n - 1] = false;
			ans[i] = -1;
		}
	}
}