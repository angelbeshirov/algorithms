#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/**
Naive solutions solves 6/9 test cases.
**/
/* Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
    int n = arr.size();
    vector<long> res;
    stack<long> keep;

    int c = 0;
    for(int ws = 1; ws < n; ws++) {
        int cur_ws = 0;
        vector<int> mins;

        for(int i = 0; i <= n; i++) {
            if(cur_ws == ws) {
                int m = INT_MAX;
                while(cur_ws > 0) {
                    long t = arr[i - cur_ws];
                    if(t < m) {
                        m = t;
                    }
                    cur_ws--;
                }

                cur_ws = ws - 1;
                mins.push_back(m);
            }
            cur_ws++;
        }

        int mx = INT_MIN;
        cout << mins.size() << " " << n - ws + 1 << endl;
        for(int i = 0; i < n - ws + 1; i++) {
            if(mx < mins[i]) {
                mx = mins[i];
            }
        }

        res.push_back(mx);
    }

    return res;
}*/

vector<long> riddle(vector<long> arr) {
    int n = arr.size();
    vector<long> res;
    stack<long>* mins = new stack<long>();
    long mx = LONG_MIN;

    for(int i = 0; i < n; i++) {
        mins->push(arr[i]);
        if(mx < arr[i]) {
            mx = arr[i];
        }
    }
    res.push_back(mx);
    mx = LONG_MIN;

    for(long ws = 2; ws <= n; ws++) {
        long t_ws = ws;
        long mn = LONG_MAX;
        new_mins = new stack<long>();
        while(!mins->empty()) {
            long p = mins->top();
            mins->pop();

            if(mn > p) {
                mn = p;
            }

            if(--t_ws <= 0) {
                cout << "Adding min " << mn << endl;
                new_mins->push(mn);
                if(mx < mn) {
                    mx = mn;
                }
                mn = LONG_MAX;
                t_ws = ws;
            }
        }
        res.push_back(mx);
        mx = LONG_MIN;
        delete mins;
        mins = new_mins;
    }

    return res;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    ostream& fout = cout;

    //ifstream s11("input02.txt");
    istream& s11 = cin;

    int n;
    s11 >> n;
    s11.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(s11, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
