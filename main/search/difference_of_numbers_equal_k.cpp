/**
    Link: https://www.hackerrank.com/challenges/pairs/problem
    @author angel.beshirov
**/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool binary_search(vector<int> arr, int target, int start, int end) {
    if(start <= end) {
        int mid = end - (end - start) / 2;
        if(arr[mid] == target) {
            return true;
        } else if(arr[mid] < target) {
            return binary_search(arr, target, mid + 1, end);
        } else return binary_search(arr, target, start, mid - 1);
    }

    return false;
}

// Complete the pairs function below.
// nlogn too slow obviously
/*
int pairs(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());

    int cnt = 0;
    int n = arr.size();

    // a[j] - a[i] = k
    // search for k + a[i]
    for(int i = 0; i < n; ++i) {
        int target = k + arr[i];
        if(binary_search(arr, target, i + 1, n - 1)) {
            ++cnt;
        }
    }

    return cnt;
}*/

// linear O(n)
int pairs(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());

    int cnt = 0;
    int n = arr.size();

    int i = 0;
    int j = 1;
    // 1 4 6 7 9 10 11, k = 2
    // if condition is i < j, this will exit on step 1
    // 4 - 1 = 3 > 2, i++ - i = 1, j = 1, 4 - 4 = 0 < 2 -> j++
    while(j < n) {
        int diff = arr[j] - arr[i];
        if(diff == k) {
            ++cnt;
            j++;
        } else if(diff < k) {
            j++;
        } else {
            i++;
        }
    }

    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pairs(k, arr);

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
