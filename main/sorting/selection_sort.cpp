#include<iostream>
using namespace std;

template<typename T>
void selection_sort(T* a, int n) {
    T min_el;
    int min_index;
    for(int i = 0; i < n - 1; i++) {
        int min_index = i;
        min_el = a[min_index];

        for(int j = i + 1; j < n; j++){
            if(a[j] < min_el) {
                min_el = a[j];
                min_index = j;
            }
        }

        a[min_index] = a[i];
        a[i] = min_el;
    }
}

int main() {
    double a[] = {6.3, 3, 1, 5, 8};
    int n = 5;

    selection_sort(a, n);

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
