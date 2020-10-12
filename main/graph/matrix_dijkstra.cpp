
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int pick_shortest(vector<long> dist, vector<bool> spt_set, int n) {
    long min_dist = LONG_MAX;
    int min_index = -1;
    for(int i = 0; i < n; ++i) {
        if(min_dist > dist[i] && !spt_set[i]) {
            min_dist = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

/**
7 4
0 1 4
1 2 3
1 3 7
0 4 2
3 5 9
5 6 10
2
3
4
6
**/
// Complete the minTime function below.
int minTime(vector<vector<int>> roads, vector<int> machines) {
    int n = roads.size();
    int machines_size = machines.size();

    if(machines_size <= 1) {
        return 0;
    }

    int start_vertex = machines[0];

    vector<bool> spt_set(n + 2, false); // true if vertex u is included in the SPT
    vector<long> smallest_edge(n + 2, LONG_MAX);
    vector<bool> is_machine(n + 2, false);

    for(int i = 0; i < machines_size; i++) {
        is_machine[machines[i]] = true;
    }

    vector<vector<pair<int, int>>> graph(n + 2, vector<pair<int, int>>());

    for(int i = 0; i < n; i++) {
        graph[roads[i][0]].push_back(make_pair(roads[i][1], roads[i][2]));
        graph[roads[i][1]].push_back(make_pair(roads[i][0], roads[i][2]));
    }

    smallest_edge[start_vertex] = 0;
    spt_set[start_vertex] = true;

    cout << "The start vertex is " << start_vertex << endl;

    queue<int> nds;
    nds.push(start_vertex);

    while(!nds.empty()) {
        int nd = nds.front();
        nds.pop();

        vector<pair<int, int>> children = graph[nd];

        for(int i = 0; i < children.size(); i++) {
            //cout << spt_set[children[i].first] << " " << dist[children[i].first] << " " << children[i].second << endl;
            if(!spt_set[children[i].first]) {
                spt_set[children[i].first] = true;
                nds.push(children[i].first);

                //cout << "Iterating " << children[i].first << " with len " << children[i].second << endl;

                if(smallest_edge[children[i].first] > children[i].second) {
                    smallest_edge[children[i].first] = children[i].second;
                }

                if(smallest_edge[children[i].first] > smallest_edge[nd] && !is_machine[nd]) {
                    smallest_edge[children[i].first] = smallest_edge[nd];
                }
            }
        }
    }

    long maxv = LONG_MIN;
    long sum = 0;

    for(int i = 0; i < n + 1; i++) {
        if(i != 0) {
            cout << " ";
        }
        cout << smallest_edge[i];

        if(is_machine[i]) sum += smallest_edge[i];
    }
    cout << endl;
    cout << "Returning " << sum << endl;

    for(int i = 20; i < 100; i++) {
        cout << i << endl;
    }

    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> roads(n - 1);
    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> roads[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> machines(k);

    for (int i = 0; i < k; i++) {
        int machines_item;
        cin >> machines_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        machines[i] = machines_item;
    }

    int result = minTime(roads, machines);

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
