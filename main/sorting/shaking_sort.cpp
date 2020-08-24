/**

    Shaking sort:
    1. Let left = 0, right = n - 1;
    2. The subset aleft aleft + 1 ... aright is traversed twice
    once from left to right and once from right to left

    When traversed from left to right the last index of a swapped element is the new right
    This way all elements from right to n will be sorted

    When traversed from right to left the last index of a swapped element - 1 (if comparing a[i] and a[i - 1] we get i - 1) is the new left
    This way all elements from 0 to left will be sorted

    We do this until right - left > 0

    Complexity:
    O(n^2)
**/

#include<iostream>
using namespace std;

template<typename T>
void shaking_sort(T* a, int n) {
    int right = n - 1;
    int left = 0;
    while(right - left > 0) {
        int new_right = left;
        for(int i = left; i < right; i++) {
            if(a[i] > a[i + 1]) {
                T swapped = a[i];
                a[i] = a[i + 1];
                a[i + 1] = swapped;
                new_right = i;
            }
        }

        right = new_right;

        int new_left = right;
        for(int j = right; j > left; j--) {
            if(a[j] < a[j - 1]) {
                T swapped = a[j];
                a[j] = a[j - 1];
                a[j - 1] = swapped;
                new_left = j - 1;
            }
        }

        left = new_left;
    }
}
int main() {
    double a[] = {9, 7, 6, 3, 1};
    int n = 5;

    shaking_sort(a, n);

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
