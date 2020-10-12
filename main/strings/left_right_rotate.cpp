#include<bits/stdc++.h>
using namespace std;

char* left_rotate(char* p, int k) {
    int n = strlen(p);
    if(n < 2) {
        return p;
    }

    while(k-- > 0) {
        char first = p[0];
        for(int i = 1; i < n; i++) {
            p[i - 1] = p[i];
        }

        p[n - 1] = first;
    }

    return p;
}

char* right_rotate(char* p, int k) {
    int n = strlen(p);

    if(n < 2) {
        return p;
    }
    while(k-- > 0) {
        char last = p[n - 1];

        for(int i = n - 1; i >= 0; i--) {
            p[i] = p[i - 1];
        }

        p[0] = last;
    }


    return p;
}
int main() {
    char str[] = {'A', 'n', 'g', 'e', 'l', 'B', 'e', 's', 'h', 'i', 'r', 'o', 'v', '\0'};

    cout << right_rotate(str, 3);
}
