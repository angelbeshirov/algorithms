#include<iostream>
using namespace std;

/**
    right_index is the first index of the last swapped element, if that index is 0 then no elements were swapped -> the array is sorted.

    O(n^2) complexity

**/
template<typename T>
void bubble_sort(T* a, int n) {
    int right_index = n - 1;

    while(right_index > 0) {
        int curr_right_index = 0;

        for(int i = 0; i < right_index; i++) {
            if(a[i] > a[i + 1]) {
                T swaper = a[i];
                a[i] = a[i + 1];
                a[i + 1] = swaper;

                curr_right_index = i;
            }
        }

        right_index = curr_right_index;
    }
}

int main() {
    int a[] = {4, 5, 1, 9, 11, 32};
    int n = 6;

    bubble_sort(a, n);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
