#include <bits/stdc++.h>

using namespace std;

int arr[] = {1, 2, 3};

int stepPermsR(int n, int* cache) {
    if(n < 0) {
        return 0;
    }

    if(cache[n] != 0) {
        return cache[n];
    }

    return (cache[n] = stepPermsR(n - 1, cache) + stepPermsR(n - 2, cache)
    + stepPermsR(n - 3, cache) % ((long) 10e10 + 7));
}

// Complete the stepPerms function below.
int stepPerms(int n) {
    int cache[37] = {0};
    cache[3] = 4;
    cache[2] = 2;
    cache[1] = 1;
    cache[0] = 1;

    return stepPermsR(n, cache);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
