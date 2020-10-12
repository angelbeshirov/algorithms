/**
    Link: https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem

    Note: No memorization therefore slow for large ns;
    @author angel.beshirov
**/

#include <iostream>

using namespace std;

int fibonacci(int n) {
    if(n == 0) {
        return 0;
    }

    if(n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);

}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
