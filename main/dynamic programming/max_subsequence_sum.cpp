#include <bits/stdc++.h>
/**
    Link: https://www.hackerrank.com/challenges/max-array-sum/problem

    Approach: Keep track of the max possible sum so far based on these rules:
    1) dyn[0] = a[0], dyn[1] = max(a[0], a[1])

    2) dyn[i] is the max of current element, current_element + dyn[i - 2]
    3) max of dyn[i], dyn[i - 1] if the previous sum is bigger than (point 2))

    @author angel.beshirov
**/


using namespace std;

vector<string> split_string(string);

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    int k = arr.size();
    int dyn[k];

    dyn[0] = arr[0];
    dyn[1] = max(arr[0], arr[1]);

    for(int i = 2; i < k; i++) {
        dyn[i] = max(arr[i], dyn[i - 2] + arr[i]);
        dyn[i] = max(dyn[i], dyn[i - 1]);
    }

    return dyn[k - 1];

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = maxSubsetSum(arr);

    fout << res << "\n";

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
