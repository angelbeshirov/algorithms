/**
    Description: Dijkstra algorithm for finding the shortest path tree. No cycles and negative weights allowed.

    @author angel.beshirov
**/

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

int dijkstra(vector<vector<pair<int, int>>> graph, int n, int start_vertex) {
    vector<bool> spt_set(n + 1, false); // true if vertex u is included in the shortest path tree
    vector<long> dist(n + 1, LONG_MAX);

    dist[start_vertex] = 0;
    int spt_set_size = 1;

    cout << "The start vertex is " << start_vertex << endl;

    while(spt_set_size < n + 1) {
        int shortest_vertex = pick_shortest(dist, spt_set, n);

        spt_set[shortest_vertex] = true;
        spt_set_size++;

        vector<pair<int, int>> children = graph[shortest_vertex];

        for(int i = 0; i < children.size(); i++) {
            if(!spt_set[children[i].first] && dist[shortest_vertex] + children[i].second < dist[children[i].first]) {
                dist[children[i].first] = dist[shortest_vertex] + children[i].second;
            }
        }
    }

    cout << "Shortest paths from " << start_vertex << " are:" << endl;
    for(int i = 0; i < n; i++) {
        if(i != 0) {
            cout << " ";
        }
        cout << dist[i];
    }
}

int main()
{
    int n;
    int m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>()); // 0-indexed
    int from, to, distance;

    for(int i = 0; i < m; i++) {
        cin >> from >> to >> distance;
        graph[from].push_back(make_pair(to, distance));
        graph[to].push_back(make_pair(from, distance));
    }

    dijkstra(graph, n, 2);


}
