/**
    Link: https://www.hackerrank.com/challenges/ctci-big-o/problem

    Description: check if number is prime in O(sqrt(n))

    Approach: Check if number is prime, check if all numbers up to sqrt(n) divide it
    n = sqrt(n) * sqrt(n), i.e. a * b at least 1 of them will be < sqrt(n) if it is not prime and if it divides it then it divides the whole n
    if it is prime it can not be splitted into sqrt(n) * sqrt(n) so it will return false

    @author angel.beshirov
**/

#include <bits/stdc++.h>

using namespace std;

// Complete the primality function below.
string primality(int n) {
    // if some number divides sqrt(n), then it is not prime
    // otherwise it is n = sqrt(n) * sqrt(n), all other representations
    // at least one of the two multipliers are smaller than sqrt(n)
    // so it is enough to check up to sqrt(n)
    if(n < 2) {
        return "Not prime";
    }

    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return "Not prime";
    }

    return "Prime";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int p_itr = 0; p_itr < p; p_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = primality(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
