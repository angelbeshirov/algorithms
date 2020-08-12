#include<iostream>
using namespace std;


/**
    6 1 3 5 10 2

    6 1 3 5 10 2

    6 1 3 | 5 10 2

    6 1 | 3 || 5 10 | 2
**/
void merge_arrays(int* arr, int start, int part, int end) {
    int first_arr_size = part - start + 1;
    int second_arr_size = end - part;

    int* first_arr = new int[first_arr_size];
    int* second_arr = new int[second_arr_size];

    int first_arr_cnt = 0;
    int second_arr_cnt = 0;


    for(int i = start; i <= part; i++) {
        first_arr[first_arr_cnt++] = arr[i];
    }

    for(int i = part + 1; i <= end; i++) {
        second_arr[second_arr_cnt++] = arr[i];
    }

    first_arr_cnt = second_arr_cnt = 0;

    int main_iter = start;

    while(first_arr_cnt < first_arr_size && second_arr_cnt < second_arr_size) {
        if(first_arr[first_arr_cnt] < second_arr[second_arr_cnt]) {
            arr[main_iter++] = first_arr[first_arr_cnt++];
        } else {
            arr[main_iter++] = second_arr[second_arr_cnt++];
        }
    }

    // first_arr_cnt >= first_arr_size || second_arr_cnt >= second_arr_size

    while(first_arr_cnt < first_arr_size) {
        arr[main_iter++] = first_arr[first_arr_cnt++];
    }

    while(second_arr_cnt < second_arr_size) {
        arr[main_iter++] = second_arr[second_arr_cnt++];
    }

    delete[] first_arr;
    delete[] second_arr;
}

void merge_sort(int* arr, int start, int end) {
    if(start < end) {
        int part = start - (start - end) / 2;

        merge_sort(arr, start, part);
        merge_sort(arr, part + 1, end);

        merge_arrays(arr, start, part, end);
    }
}

int main() {
    int arr[] = {6, 1, 3, 5, 10, 2};
    int start = 0;
    int end = 5;

    for(int i = 0; i <= end; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    merge_sort(arr, start, end);

    for(int i = 0; i <= end; i++){
        cout << arr[i] << " ";
    }
}
