#include<iostream>
using namespace std;

int get_that_digit(int x, int exponent) {
    return (x / exponent) % 10;
}

void per_digit_counting_sort(int* a, int n, int exponent) {
    int digit_counter[10] = {0};
    int* output = new int[n];

    for(int i = 0; i < n; i++){
        digit_counter[get_that_digit(a[i], exponent)]++;
    }

    for(int i = 1; i < 10; i++) {
        digit_counter[i] += digit_counter[i - 1];
    }

    // if this is for(int i = 0; i < n; i++) then when we receive sorted
    // 0 11 2 3 6 7
    // on the second iteration in this function the sorted numbers will be put in reversed order
    // due to the summing in the previous loop
    // Example:
    // 0 11 6 3 2 7
    // [1 1 1 1 0 0 1 1 0 0] -> [1 2 3 4 0 0 5 6 0 0]
    // this will sort it to 0 11 2 3 6 7

    // now if the loop was from 0 to n
    // it will become
    // [5 1 0 0 0 0 0 0 0 0] -> [5 6 0 0 0 0 0 0 0 0]
    // it will be sorted to
    // - - - - 0 -
    // - - - - 0 11
    // - - - 2 0 11
    // - - 3 2 0 11
    // - 6 3 2 0 11
    // 7 6 3 2 0 11
    for(int i = n - 1; i >= 0; i--) {

        output[digit_counter[get_that_digit(a[i], exponent)] - 1] = a[i];
        cout << a[i] << " " << output[digit_counter[get_that_digit(a[i], exponent)] - 1] << " " << digit_counter[get_that_digit(a[i], exponent)] << endl;
        digit_counter[get_that_digit(a[i], exponent)]--;
    }

    for(int i = 0; i < n; i++) {
        cout << output[i] << " ";
        a[i] = output[i];
    }

    cout << endl;


    delete[] output;
}

void radix_sort(int* a, int n) {
    int max_number = INT_MIN;

    for(int i = 0; i < n; i++) {
        if(a[i] > max_number) {
            max_number = a[i];
        }
    }

    for(int i = 1; max_number / i > 0; i*=10) {
        per_digit_counting_sort(a, n, i);
    }
}

int main() {
    int a[] = {6, 3, 1, 11, 0};
    int n = 5;

    radix_sort(a, n);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
