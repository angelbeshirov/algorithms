// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;

int binary_search_iterative(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }

    }
    return -1;
}

int binary_search_recursive(int arr[], int l, int r, int x) {
    if(l <= r) {
        int mid = r - (r - l) / 2;

        if(arr[mid] == x) {
            return mid;
        }

        if(arr[mid] < x) {
            return binary_search_recursive(arr, mid + 1, r, x);
        } else {
            return binary_search_recursive(arr, l, mid - 1, x);
        }
    }

    return -1;
}

int main(void)
{
    int arr[] = {1, 2, 3};
    int x = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binary_search_iterative(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}
