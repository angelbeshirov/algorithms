/**
    Link: https://www.hackerrank.com/challenges/torque-and-development/problem

    Description: Fix roads for price x or build library for price y. There should be a path from each node to a library
    and the price to build this should be minimized.

    If the price to build a library is less than the price to build a path, then just build library at each node.
    Else DFS, and for each connected component build 1 library, iterate all connected components.

    Final price will be: n_fixed_edges * x + n_connected_components * y
    n_fixed_edges starts at 0 (or -1 depends on implementation) because initially when we start with DFS 0 edges have been fixed. on the 2nd iteration 1 edge and so on
    at the end n - 1 edges have been fixed for n edges.

    @author angel.beshirov

**/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void add_edge(vector<vector<int> >& s1, int from, int to) {
    s1[from].push_back(to);
    s1[to].push_back(from);
}

/**
1
3 3 2 1
1 2
3 1
2 3
**/
// Complete the roadsAndLibraries function below.
// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    if(c_lib < c_road) {
        return (long) n * c_lib;
    }

    vector<vector<int> > nodes(n + 1, vector<int>());

    int elen = cities.size();

    for(int i = 0; i < elen; ++i) {
        add_edge(nodes, cities[i][0], cities[i][1]);
    }

    long vcnt = 0;
    bool* visited = new bool[n + 1];

    for(int i = 0 ; i < n + 1; i++)
        visited[i] = false;

    long start_from = 1;
    long n_fixed_edges = -1;
    long n_connected_components = 0; // graph is fully connected
    long final_fixed_edges = 0;

    while(visited[start_from]) {
        start_from++;
    }

    stack<int> nds;
    nds.push(start_from);
    n_connected_components++;

    while(!nds.empty() || vcnt < n) {
        if(nds.empty()) {
            while(visited[start_from]) {
                start_from++;
            }
            nds.push(start_from);
            n_connected_components++;
            final_fixed_edges += n_fixed_edges;
            n_fixed_edges = -1;
        }

        int p1 = nds.top();
        nds.pop();

        if(visited[p1]) {
            continue;
        }
        visited[p1] = true;
        vcnt++;
        n_fixed_edges++;
        vector<int> children = nodes[p1];

        for(int i = 0; i < children.size(); i++) {
            if(!visited[children[i]]) {
                nds.push(children[i]);

            }
        }
    }

    final_fixed_edges += n_fixed_edges;

    delete[] visited;
    return (long) final_fixed_edges * c_road + (long) n_connected_components * c_lib;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

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
