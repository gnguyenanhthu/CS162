//
//  main.cpp
//  S2018_CS162_2_W7
//


#include <iostream>
using namespace std;

void try2Buy(int cur, int n, int* price, int x_Re, int* boughtItems, int* bestItems, int& bestRemaining);

void printOut(int n, int* bestItems, int total);

int main() {
    int* price, *boughtItems, *bestItems;
    int n, x, bestRemaining;
    
    cout << "How many items in the shop? ";
    cin >> n;
    price = new int[n];
    boughtItems = new int[n];
    bestItems = new int[n];
    cout << "Price of each item: ";
    for (int i=0; i<n; ++i) {
        cin >> price[i];
        boughtItems[i] = 0; //didnt buy it yet
        bestItems[i] = 0;
    }
    cout << "How much money do you have? ";
    cin >> x;
    bestRemaining = x;
    
    try2Buy(0, n, price, x, boughtItems, bestItems, bestRemaining);
    printOut(n, bestItems, x-bestRemaining);
    
    delete [] price;
    delete [] boughtItems;
    delete [] bestItems;
    return 0;
}

void try2Buy(int cur, int n, int* price, int x_Re, int* boughtItems, int* bestItems, int& bestRemaining) {
    
    if (bestRemaining==0) return;
    
    bool flag = true;
    for (int i=cur; i<n; ++i)
        if (x_Re >= price[i]) { //enough money to buy
            ++boughtItems[i]; //bought it
            flag = false;
            try2Buy(i, n, price, x_Re-price[i], boughtItems, bestItems, bestRemaining);
            --boughtItems[i];
        }
    if (flag && (x_Re < bestRemaining)) {
        bestRemaining = x_Re; //save
        for (int i=0; i<n; ++i)
            bestItems[i] = boughtItems[i]; //save it
    }
}

void printOut(int n, int* bestItems, int total) {
    cout << "Items to buy: " << endl;
    for (int i=0; i<n; ++i)
        if (bestItems[i]>0)
            cout << "Item " << i+1 << ": " << bestItems[i] << endl;
    cout << "Total money spent: " << total << endl;
}











