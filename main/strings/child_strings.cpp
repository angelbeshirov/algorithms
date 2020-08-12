/**
    Longest common subsequence problem. Given 2 string ABCD and ABDT find the longest subsequence which is a child of both ABCD and ABDT. In this case
    this will be ABD. Solved using recursion and DP.

    HackerRank link: https://www.hackerrank.com/challenges/common-child/problem
**/

#include <bits/stdc++.h>

using namespace std;


// Recursive approach - not very efficient
int LCS(string s1, string s2, int i, int j) {

    if(i < 0 || j < 0) {
        return 0;
    }

    if(s1[i] == s2[j]) {
        return 1 + LCS(s1, s2, i - 1, j - 1);
    } else {
        return max(LCS(s1, s2, i - 1, j), LCS(s1, s2, i, j - 1));
    }
}


int LCS[5001][5001]; // n can get up to 4999, <= n + 1 = <= 5000 max index -> 5001
// Dynamic programming approach
int LCSDP(string s1, string s2, int n, int m) {

    for(int i = 0; i <= n + 1; i++) { // LCS[i][0] = longest subsequence with length 0 in string s1 from 0 up to n
        LCS[i][0] = 0;
    }

    for(int j = 0; j <= m + 1; j++) { // LCS[0][j] = longest subsequence with length 0 in string s2 from 0 up to m
        LCS[0][j] = 0;
    }

    for(int i = 1; i <= n + 1; i++) { // start with length 1
        for(int j = 1; j <= m + 1; j++) { // starts with length 1
            if(s1[i - 1] == s2[j - 1]) {
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            } else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }


    return LCS[n + 1][m + 1];
}

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    return LCSDP(s1, s2, i, j);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    cout << result << "\n";

    fout.close();

    return 0;
}
