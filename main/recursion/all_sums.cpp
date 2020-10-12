#include<bits/stdc++.h>
using namespace std;

void print_solution(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/** all sums up to a target from a given set/multi-set with repetitions **/
void print_all_sums(int* arr, int n, int target, int* sol, int m) {
    for(int i = 0; i < n; i++) {
        if(target - arr[i] == 0) {
            sol[m++] = arr[i];
            print_solution(sol, m);
            m--;
        } else if(target - arr[i] > 0) {
            sol[m++] = arr[i];
            print_all_sums(arr, n, target - arr[i], sol, m);
            m--;
        }
    }
}

/** all sums up to a target from a given set/multi-set without repetitions **/
void print_all_sums(int* arr, int n, int from, int target, int* sol, int m) {
    for(int i = from; i < n; i++) {
        if(target - arr[i] == 0) {
            sol[m++] = arr[i];
            print_solution(sol, m);
            m--;
        } else if(target - arr[i] > 0) {
            sol[m++] = arr[i];
            print_all_sums(arr, n, i + 1, target - arr[i], sol, m);
            m--;
        }
    }
}

int main() {
    int arr[] = {3, 4, 1, 5, 2};
    int n = 5;

    int target = 7;

    int sol[40];
    int m = 0;

    print_all_sums(arr, n, 0, target, sol, m);
}
