#include <bits/stdc++.h>

/**
    Link: https://www.hackerrank.com/challenges/triple-sum/problem

    Description: For each element in b count how many numbers are smaller that it in A and in C and increment the counter.
    The result will be cnt1 * cnt2 without nulling them
    e.g. 1 3 4    3 5 6   4 5 6
    1 5 4  1 5 5  3 5 4  3 5 5 - for 5 2 * 2
    for 6 it will be 3 * 3, total is 13

    1 5 4
    1 5 5
    3 5 4
    3 5 5
    ----4
    1 6 4
    1 6 5
    1 6 6
    3 6 4
    3 6 5
    3 6 6
    4 6 4
    4 6 5
    4 6 6
    ----9
    the number of number smaller in A * the number of numbers smaller in C


    @author angel.beshirov
**/
using namespace std;

vector<string> split_string(string);

void remove_dup(vector<int>& v) {
    for(int i = 1; i < v.size(); i++) {
        if(v[i] == v[i - 1]) {
            v.erase(v.begin() + i - 1);
        }
    }
}

// Complete the triplets function below.
long triplets(vector<int> a, vector<int> b, vector<int> c) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    remove_dup(a); remove_dup(b); remove_dup(c);

    long i = 0, j = 0, k = 0;

    long ni = a.size(), nj = b.size(), nz = c.size();
    long cnt = 0;
    while (j < nj)
    {
        while (i < ni && a[i] <= b[j])
             i++;
        while (k < nz && c[k] <= b[j])
             k++;

        cnt += ((long) i) * k;
        j++;
    }

    return cnt;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    ostream& fout = cout;

    string lenaLenbLenc_temp;
    getline(cin, lenaLenbLenc_temp);

    vector<string> lenaLenbLenc = split_string(lenaLenbLenc_temp);

    int lena = stoi(lenaLenbLenc[0]);

    int lenb = stoi(lenaLenbLenc[1]);

    int lenc = stoi(lenaLenbLenc[2]);

    string arra_temp_temp;
    getline(cin, arra_temp_temp);

    vector<string> arra_temp = split_string(arra_temp_temp);

    vector<int> arra(lena);

    for (int i = 0; i < lena; i++) {
        int arra_item = stoi(arra_temp[i]);

        arra[i] = arra_item;
    }

    string arrb_temp_temp;
    getline(cin, arrb_temp_temp);

    vector<string> arrb_temp = split_string(arrb_temp_temp);

    vector<int> arrb(lenb);

    for (int i = 0; i < lenb; i++) {
        int arrb_item = stoi(arrb_temp[i]);

        arrb[i] = arrb_item;
    }

    string arrc_temp_temp;
    getline(cin, arrc_temp_temp);

    vector<string> arrc_temp = split_string(arrc_temp_temp);

    vector<int> arrc(lenc);

    for (int i = 0; i < lenc; i++) {
        int arrc_item = stoi(arrc_temp[i]);

        arrc[i] = arrc_item;
    }

    long ans = triplets(arra, arrb, arrc);

    fout << ans << "\n";

//fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
