#include<bits/stdc++.h>
using namespace std;

long fast_power(long x, long n) {
    if(n == 0) return 1;
    if(n == 1) return x;

    return n % 2 == 0 ? fast_power(x * x, n / 2) : x * fast_power(x * x, (n - 1) / 2);
}

double fast_power_neg(double x, long n) {
    if(n == 0) return 1;
    if(n == 1) return x;

    bool neg = n < 0;
    if(neg) n = -n;

    double res = n % 2 == 0 ? fast_power(x * x, n / 2) : x * fast_power(x * x, (n - 1) / 2);

    return neg ? 1 / res : res;
}

int main() {
    cout << fast_power_neg(3, -4);
}
