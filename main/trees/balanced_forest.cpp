#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

struct node {
    int data;
    vector<node*> children;
};

/**
1
5
1 2 2 1 1
1 2
1 3
3 5
1 4
**/

long get_overall_sum(vector<pair<int, vector<int>>> tree, int n) {

    vector<bool> visited(n + 1, false);
    long sum = 0;

    int start = 1;
    visited[1] = true;

    queue<int> nds;
    nds.push(start);

    while(!nds.empty()) {
        int t = nds.front();
        nds.pop();

        vector<int> children = tree[t].second;
        sum += (tree[t - 1].first);
        cout << "Visiting " << t << endl;

        for(int i = 0; i < children.size(); i++) {
            if(!visited[children[i]]) {
                nds.push(children[i]);
                visited[children[i]] = true;
            }
        }
    }

    return sum;
}

long get_min_sum(vector<pair<int, vector<int>>> tree, int n, long osm) {
    vector<bool> visited(n + 1, false);
    long target_sum = 0;
    int start = 1;
    int visitedn = 1;
    visited[1] = true;

    stack<int> nds;
    nds.push(start);
    target_sum += (tree[start - 1].first);

    while(!nds.empty()) {
        int t = nds.top();
        nds.pop();

        vector<int> children = tree[t].second;

        if(children.size() == 0) {

        }

        for(int i = 0; i < children.size(); i++) {
            visited[children[i]] = true;
            nds.push(children[i]);
            target_sum += tree[children[i] - 1].first;

            visitedn++;
            int cpv = visitedn;

            bool has_connected_equal_sum = check_connected_sum();

            if(has_connected_equal_sum) {
                if(osm <= 3 * target_sum && visitedn + visited_css) {

                }
            }
        }
    }
}

// Complete the balancedForest function below.
int balancedForest(vector<int> c, vector<vector<int>> edges) {
    int n = c.size();
    int m = edges.size();

    if(n < 3) {
        return -1;
    }

    vector<pair<int, vector<int>>> tree(n + 1);
    for(int i = 0; i < n + 1; i++) {
        tree[i] = make_pair(c[i], vector<int>());
    }

    for(int i = 0; i < m; i++) { // TODO change to n - 1
        tree[edges[i][0]].second.push_back(edges[i][1]);
        //tree[edges[i][1]].second.push_back(edges[i][0]);
    }

    long osm = get_overall_sum(tree, n);

    if(n == 3 && osm / 3 != tree[0].first) {
        return -1;
    } else return 0;
    cout << "OS:" << osm << endl;


    return get_min_sum(tree, n, osm);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string c_temp_temp;
        getline(cin, c_temp_temp);

        vector<string> c_temp = split_string(c_temp_temp);

        vector<int> c(n);

        for (int i = 0; i < n; i++) {
            int c_item = stoi(c_temp[i]);

            c[i] = c_item;
        }

        vector<vector<int>> edges(n - 1);
        for (int i = 0; i < n - 1; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = balancedForest(c, edges);

        fout << result << "\n";
    }

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
