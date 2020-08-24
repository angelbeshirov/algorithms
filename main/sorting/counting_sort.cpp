#include<iostream>
using namespace std;

const int LIMIT = 10000000;

void counting_sort(int* a, int n) {
    int max_number = INT_MIN;
    int min_number = INT_MAX;

    // finds the max and min element in the array so that we can properly allocate the counter array
    for(int i = 0; i < n; i++) {
        if(a[i] < min_number) {
            min_number = a[i];
        }

        if(a[i] > max_number) {
            max_number = a[i];
        }
    }

    int min_number_positive = min_number < 0 ? -min_number : min_number;

    int size = min_number + max_number;
    int* counter = new int[size];

    for(int i = 0; i < size; i++) {
        counter[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        counter[min_number_positive + a[i]]++;
    }

    int j = 0;
    for(int i = 0; i < size; i++) {
        if(counter[i] != 0) {
            while(counter[i]-- > 0) {
                a[j++] = min_number + i;
            }
        }
    }

    delete[] counter;
}

int main() {
    int a[] = {-17, -5, 3, 2, 1, 121212};
    int n = 6;

    counting_sort(a, n);

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
