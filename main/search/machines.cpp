#include <bits/stdc++.h>

/**
    Link: https://www.hackerrank.com/challenges/minimum-time-required/problem

    Description:
    Pick left and right boundary and do binary search for the production the machines can do for that many days.
    right is the goal / number_of_machines + 1 * slowest_machine

    @author angel.beshirov
**/
using namespace std;

vector<string> split_string(string);

long items_to_produce(long per_day, long days) {
    return days / per_day;
}

long get_production_for_days(long days, vector<long> machines, long n) {
    long k = 0;
    for(long i = 0; i < n; i++) {
        k += items_to_produce(machines[i], days);
    }

    return k;
}

// Complete the minTime function below.
long minTime(vector<long> machines, long goal) {
    sort(machines.begin(), machines.end());
    long n = machines.size();
    //cout << machines[n - 1] << endl;
    //cout << goal << endl;
    long right = (goal / n + 1) * machines[n - 1];
    long left = 0;

    long cur_sol = right;

    cout << left << " " << right << endl;

    while(left <= right) {
            //cout << "in";
        long mid = right - (right - left) / 2;

        long sol = get_production_for_days(mid, machines, n);
        if(sol >= goal) {
            if(mid <= cur_sol)
                cur_sol = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return cur_sol;


}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    ostream& fout = cout;

    ifstream i("data.txt");
    string nGoal_temp;
    getline(i, nGoal_temp);

    vector<string> nGoal = split_string(nGoal_temp);

    int n = stoi(nGoal[0]);

    long goal = stol(nGoal[1]);

    string machines_temp_temp;
    getline(i, machines_temp_temp);

    vector<string> machines_temp = split_string(machines_temp_temp);

    vector<long> machines(n);

    for (int i = 0; i < n; i++) {
        long machines_item = stol(machines_temp[i]);

        machines[i] = machines_item;
    }

    long ans = minTime(machines, goal);

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

