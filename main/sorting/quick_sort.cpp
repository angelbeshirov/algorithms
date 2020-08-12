#include<iostream>
using namespace std;

/**
    6, 1, 3, 5, 10, 2

    first pivot = 2
    1 6 3 5 10 2 -> 1 2 3 5 10 6

    3 5 10 6, pivot = 6
    3 5 6 10

    3 5, pivot = 5

    1 2 3 5 6 10
**/

int partition(int* arr, int start, int end) {
    int pick_index = end;

    int swap_index = start - 1;

    for (int i = start; i < end; i++) {
        if(arr[i] < arr[pick_index]) {
            swap_index++;
            int save = arr[i];
            arr[i] = arr[swap_index];
            arr[swap_index] = save;
        }
    }

    swap_index++;
    int save = arr[pick_index];
    arr[pick_index] = arr[swap_index];
    arr[swap_index] = save;

    return swap_index;
}

void quicksort(int* arr, int start, int end) {
    if (start < end) {

        int part = partition(arr, start, end);

        quicksort(arr, start, part - 1);
        quicksort(arr, part + 1, end);
    }
}
int main() {
    int arr[] = {6, 1, 3, 5, 10, 2};
    int start = 0;
    int end = 5;

    for(int i = 0; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, start, end);

    for(int i = 0; i <= end; i++) {
        cout << arr[i] << " ";
    }
}
