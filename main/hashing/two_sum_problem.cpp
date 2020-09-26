/// https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem

/// Can be solved in multiple ways, standard interview question

/// Way 1. Naive - iterate 2 times over the array O(n^2)
/// Way 2. Sort + binary_search O(nlogn)
/// Way 3. Hashing and search for target - x

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// recursive binary search
int binary_search(int left, int right, int val, vector<pair<int, int>> arr) {
    if (left > right) {
        return -1;
    }

    int mid = right - (right - left) / 2;

    if(arr[mid].first == val) {
        return mid;
    } else if(arr[mid].first < val) {
        return binary_search(mid + 1, right, val, arr);
    } else {
        return binary_search(left, mid - 1, val, arr);
    }
}

// Complete the whatFlavors function below.
void whatFlavors_binary_too_slow(vector<int> cost, int money) {
    int n = cost.size();
    vector<pair<int, int>> indexedCost;
    for(int s = 0; s < n; s++) {
        indexedCost.push_back(make_pair(cost[s], s));
    }

    sort(indexedCost.begin(), indexedCost.end());

    for(int i = 0; i < n; i++) {
        if(indexedCost[i].first <= (money + 1) / 2) {
            int index = i;
            int second = binary_search(index + 1, n, money - indexedCost[index].first, indexedCost);
            //cout << "returned " << second << endl;

            if(second != -1) {
                int x = indexedCost[index].second;
                int y = indexedCost[second].second;

                if (x < y) {
                    cout << x + 1 << " " << y + 1 << endl;
                } else {
                    cout << y + 1 << " " << x + 1 << endl;
                }

                break;
            }
        } else {
            break;
        }
    }
}

// Two-sum problem using hashing, this can also be replaced by hashSet and look for target - x in the set
// and add x O(n)
void whatFlavors(vector<int> cost, int money) {
    int n = cost.size();
    map<int, int> mp;

    for(int i = 0; i < n; i++){
        if(mp[money - cost[i]]) {
            cout << mp[money - cost[i]] << " " << i + 1 << endl;
            break;
        }
        mp[cost[i]] = i + 1;
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
