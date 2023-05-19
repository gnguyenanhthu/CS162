//
//  main.cpp
//  S2018_CS162_2_W8b
//


#include <iostream>
using namespace std;

void PutQueen(int i, int n, int cnt, int *ans, bool *column, bool *mainDiagonal, bool *subDiagonal);

int main() {
    cout << "Enter n: ";
    int n; cin >> n;
    
    int *ans = new int[n];
    for(int i = 0; i < n; ++i) ans[i] = -1;
    bool *column = new bool[n];
    for(int i = 0; i < n; ++i) column[i] = false;
    
    bool *mainDiagonal = new bool[2*n-1];
    for(int i = 0; i < 2*n-1; ++i) mainDiagonal[i] = false;
    
    bool *subDiagonal = new bool[2*n-1];
    for(int i = 0; i < 2*n-1; ++i) subDiagonal[i] = false;
    
    PutQueen(0, n, 0, ans, column, mainDiagonal, subDiagonal);
    
    delete [] column;
    delete [] subDiagonal;
    delete [] mainDiagonal;
    return 0;
}

void PutQueen(int i, int n, int cnt, int *ans, bool *column, bool *mainDiagonal, bool *subDiagonal) {
    if (i == n) {
        int maxQueen = n;
        if (n == 2 || n == 3) --maxQueen;
        if (cnt == maxQueen) {
            for(int x = 0; x < n; ++x) {
                for(int y = 0; y < n; ++y)
                    if (ans[x] == y) cout << "Q";
                    else cout << ".";
                cout << endl;
            }
            cout << endl;
        }
        return;
    }
    PutQueen(i+1, n, cnt, ans, column, mainDiagonal, subDiagonal);
    for(int j = 0; j < n; ++j) {
        if (!column[j] && !mainDiagonal[i+j] && !subDiagonal[i-j+n-1]) {
            ans[i] = j;
            column[j] = mainDiagonal[i+j] = subDiagonal[i-j+n-1] = true;
            PutQueen(i+1, n, cnt+1, ans, column, mainDiagonal, subDiagonal);
            column[j] = mainDiagonal[i+j] = subDiagonal[i-j+n-1] = false;
            ans[i] = -1;
        }
    }
}
















