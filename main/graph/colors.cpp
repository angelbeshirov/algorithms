/**
    Link: https://www.hackerrank.com/challenges/find-the-nearest-clone/problem

    Description: Find the shortest path between two colors.

    Approach: Because the graph is connected and undirected, we know that there should be a path between every pair of vertexes, therefore
    when searching for the min path between 2 colors, start at random vertex which has the needed color, and use BFS, then when you encounter
    a vertex with the same color in some child node X at distance p, check if p is the smallest possible distance and set the distance of that X node
    to 0 (simulate starting BFS from there).

    @author angel.beshirov
**/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    int colors_n = ids.size();
    int edges_n = graph_from.size();

    queue<long> nds;
    vector<vector<long> > nodes(graph_nodes + 1, vector<long>());

    bool* visited = new bool[graph_nodes + 1];
    long* dist = new long[graph_nodes + 1];

    long start_from = 1;
    long mind = LONG_MAX;

    for(int i = 0; i < edges_n; i++) {
        nodes[graph_from[i]].push_back(graph_to[i]);
        nodes[graph_to[i]].push_back(graph_from[i]);
    }

    for(int i = 0 ; i < graph_nodes + 1; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    while(ids[start_from - 1] != val && start_from < colors_n) {
        start_from++;
    }

    if(start_from >= colors_n) { // no color was found to match the val
        return -1;
    }

    dist[start_from] = 0;
    visited[start_from] = true;

    nds.push(start_from);


    while(!nds.empty()) {
        long p = nds.front();
        nds.pop();

        vector<long> children = nodes[p];

        for(int i = 0; i < children.size(); i++) {
            if(!visited[children[i]]) {
                visited[children[i]] = true;
                dist[children[i]] = dist[p] + 1;
                nds.push(children[i]);

                if(ids[children[i] - 1] == val && dist[children[i]] < mind) {
                    mind = dist[children[i]];
                    dist[children[i]] = 0;
                }
            }
        }
    }

    delete[] visited;
    delete[] dist;

    return mind > 1e9 ? -1 : mind;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    ostream& fout = cout;

    int graph_nodes;
    int graph_edges;

    ifstream ct("input02.txt");

    ct >> graph_nodes >> graph_edges;
    ct.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        ct >> graph_from[i] >> graph_to[i];
        ct.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(ct, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    ct >> val;
    ct.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

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
