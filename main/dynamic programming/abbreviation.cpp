#include <bits/stdc++.h>

/**
    Link: https://www.hackerrank.com/challenges/abbr/problem
    Description: Dynamic programming approach to check whether a string A can be changed to a string B using the following rules:
    1) all lower-cased letters can be changed to upper-case
    2) all lower-cased letters can be deleted
    3) all upper-cased letters should match directly

    Approach:
    Dynamic programming using 2D dyn array, where i j is true if a1a2...aj can be changed to form b1b2...bi.

    Initializing: dyn[0][0] is true,
                  dyn[0][i] is true if all letters in a1a2...aj are all lower-cased letters
                  dyn[i][0] is false because you can not form b1b2..bi for i > 0 with 0 letters

    if a[j] == b[i] then it is true if dyn[i - 1][j - 1] is true
    else check if the letter is upper case if yes then dyn[i][j] is false
                                           else check if it can be changed to upper case and all the previous letters match or it can be deleted and all previous letters match.

    @author angel.beshirov

**/

using namespace std;

/**
1
abcDD
BCDD
**/
// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    int m = b.size();
    int n = a.size();
    bool dyn[m + 1][n + 1];

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            dyn[i][j] = false;
        }
    }

    dyn[0][0] = true;

    for(int i = 1; i < m; i++) {
        dyn[i][0] = false;
    }

    for(int i = 1; i < n; i++) {
        dyn[0][i] = (a[i - 1] >= 'a' && a[i - 1] <= 'z') && (i > 1 ? dyn[0][i - 1] : true);
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[j - 1] == b[i - 1]) {
                dyn[i][j] = dyn[i - 1][j - 1]; // if the letters are the same then it is the previous result
            } else {
                if(a[j - 1] >= 'A' && a[j - 1] <= 'Z') {
                    // if a[j] != b[i] and it is upper case then false
                    dyn[i][j] = false;
                } else {
                    // if you can change the letter from lower case to upper case and all previous match then true or if u can delete it - the previous result
                    dyn[i][j] = ((a[j - 1] - ('a' - 'A') == b[i - 1]) && dyn[i - 1][j - 1]) || dyn[i][j - 1];
                }
            }
        }
    }

    return dyn[m][n] ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    //ostream& fout = cout;

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    //fout.close();

    return 0;
}
