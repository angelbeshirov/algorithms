#include<iostream>
using namespace std;

/**
Start by assigning h for which these conditions should hold:
1) h <= 2n
2) 2(3h + 1) > n

To generate such h we use

h = 1
while(2(3h + 1) <= n) h = 3h + 1;

    when this while stops h = 3h + 1 and 2(3h + 1) > n
    and h = 3h + 1 which will be <= n such it entered the while for the last 2(3h + 1) <= n condition -> h = 2n will hold

While h > 0
we pick a[h], a[2h], a[3h] ...

Compare a[h], a[2h], a[3h] with all previous elements with step h
and if x = a[h] < a[j], where j < h swap a[i - h] and a[i]

At the last step assign x to the last swapped index i - h

Do this while h > 0 and divide h by 3 at each iteration over the array from i = h to n i += h;

**/
template<typename T>
void shell_sorting(T* a, int n) {
    int h = 1;

    // conditions for h are:
    // 1) 2h < n
    // 2) 2 * (3h + 1) > n
    while(2 * (3 * h + 1) <= n) {
        h = 3 * h + 1;
    }

    while(h > 0) {
        for(int i = h; i < n; i += h) {
            T el = a[i];

            int j;
            for(j = i - h; j >= 0; j -= h) {
                if(a[j] > el) {
                    a[j + h] = a[j];
                } else {
                    break; // otherwise the elements are sorted
                }
            }
            a[j + h] = el; // the condition is evaluated before the check, when the check fails j < 0 i.e. add the increment back
        }

        h /= 3;
    }
}

int main() {
    int a[] = {8, 4, 1, 17, 11};
    int n = 5;

    shell_sorting(a, n);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
