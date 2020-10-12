/**
    Link: https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem

    Description: Write a program to print the shortest path for undirected graph with constant edge weights from a starting vertex.
    If there is not a path from the start vertex to some vertex the shortest path distance to that vertex is -1.

    Approach: Use bfs from the starting vertex, afterwards check if some nodes are still with the initialized value and change it if needed.

    @author angel.beshirov
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    public:
        Graph(int _n): n(_n), nodes(vector<vector<int>>(_n, vector<int>())) {

        }

        void add_edge(int u, int v) {
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }

        vector<int> shortest_reach(int start) {
            vector<bool> visited(n, false);
            vector<int> dist(n, 0);


            queue<int> nds;
            nds.push(start);
            visited[start] = true;

            while(!nds.empty()) {
                int s = nds.front();
                nds.pop();

                vector<int>& children = nodes[s];

                for(int i = 0; i < children.size(); i++) {
                    if(!visited[children[i]]) {
                        visited[children[i]] = true;
                        nds.push(children[i]);
                        dist[children[i]] = dist[s] + 6;
                    }
                }
            }

            for(int i = 0; i < dist.size(); i++) {
                if(dist[i] == 0) dist[i] = -1;
            }

            return dist;
        }

    private:
        vector<vector<int> > nodes;
        int n;

};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
