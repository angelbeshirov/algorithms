#include<bits/stdc++.h>
using namespace std;

void print_pascals(int n) { // 0 based
    vector<vector<int> > dyn(n + 1, vector<int>(n + 1, 1));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            dyn[i][j] = dyn[i - 1][j] + dyn[i - 1][j - 1];
        }
    }

    for(int i = 0; i < n + 1; i++) {
        cout << dyn[n][i] << " ";
    }
}

// 0 + 1 + 2 + 3 + 4 + 5 // n^2

int main() {
    int n;
    cin >> n;

    print_pascals(n);
}
