#include<iostream>
using namespace std;

/**
    Idea: Start from the 2nd element and assign a[i - 1] to a[i] if a[i - 1] is less than X, where X is a[i]
    in the end put the X element in the index which will be the last one which was swapped between i - 1 and i;
    a[i - 1] = X
**/

template<typename T>
void insertion_sort(T* a, int n) {
    for(int i = 1; i < n; i++) {
        T el = a[i];

        int j = i - 1;
        while(j >= 0 && a[j] > el) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = el;
    }
}

int main() {
    int a[] = {6, 1, 3, 11, 32};
    int n = 5;

    insertion_sort(a, n);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
