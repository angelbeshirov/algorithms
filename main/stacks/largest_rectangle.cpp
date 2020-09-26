#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/**


Naive solution, passes 10/16 tests O(n^2)
// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    int n = h.size();
    if(n < 0) return 0;

    int c_min = h[0];

    int cur_max_res = c_min;

    for(int i = 0; i < n - 1; i++) {
        int c_min = h[i];

        for(int j = i + 1; j < n; j++) {
            if(h[j] < c_min) {
                c_min = h[j];
            }

            if(c_min * (j + 1 - i) > cur_max_res) {
                cur_max_res = c_min * (j + 1 - i)
            }
        }
    }

    return cur_max_res;
}**/

/**
    Optimized solutions
**/
long largestRectangle(vector<int> h) {
    int n = h.size();
    if(n < 0) return 0;

    int c_min = h[0];

    int cur_max_res = c_min;

    for(int i = 0; i < n; i++) {
        int c_min = h[i];
        int j = i;

        //while(--j >= 0 && (c_min * (i - j) >))
    }

    return cur_max_res;
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

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
