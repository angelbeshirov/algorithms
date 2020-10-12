#include<bits/stdc++.h>
using namespace std;

int get_min_number(int n) {
    vector<int> dyn(n + 1, 0);

    dyn[1] = 1;
    dyn[2] = 2;
    dyn[3] = 3;

    for(int i = 4; i <= n; i++) {

        dyn[i] = i;

        for(int j = 1; j < (int) ceil(i); j++) {
            if(j * j > i) {
                break;
            } else {
                dyn[i] = min(dyn[i], 1 + dyn[i - j * j]);
            }
        }
    }

    return dyn[n];
}

int main() {
    int n;
    cin >> n;

    cout << get_min_number(n);
}
