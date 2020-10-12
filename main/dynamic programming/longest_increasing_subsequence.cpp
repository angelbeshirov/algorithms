#include<bits/stdc++.h>
using namespace std;

// 3, 2, 7, 8, 1, 4
int lis(int* arr, int n) {
    vector<int> dyn(n, 1);

    for(int i = 1; i < n; i++) {

        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && dyn[i] < 1 + dyn[j]) {
                dyn[i] = 1 + dyn[j];
            }
        }
    }

    int men = INT_MIN;

    for(int i = 0; i < dyn.size(); i++) {
        if(men < dyn[i]) {
            men = dyn[i];
        }
    }

    return men;
}

int main() {
    int arr[6] = {3, 2, 7, 8, 1, 4};
    int n = 6;

    cout << lis(arr, n);
}
