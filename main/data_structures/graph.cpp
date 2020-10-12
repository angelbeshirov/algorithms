#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    graph(int _n): n(_n), vertices(vector<vector<int> >(_n + 1, vector<int>())) {};

    void add_edge(int from, int to) {
        if(from > n || to > n) {
            return;
        }

        vertices[from].push_back(to);
        vertices[to].push_back(from);
    }

    void bfs(int start) {
        vector<bool> visited(n + 1, false);

        visited[start] = true;
        queue<int> nds;
        nds.push(start);

        while(!nds.empty()) {
            int h = nds.front();
            nds.pop();

            cout << h << " ";

            vector<int> children = vertices[h];
            for(int i = 0; i < children.size(); i++) {
                if(!visited[children[i]]) {
                    nds.push(children[i]);
                    visited[children[i]] = true;
                }
            }
        }
    }

    void dfs(int start) {
        vector<bool> visited(n + 1, false);

        visited[start] = true;
        stack<int> nds;
        nds.push(start);

        while(!nds.empty()) {
            int h = nds.top();
            nds.pop();

            cout << h << " ";

            vector<int> children = vertices[h];
            for(int i = 0; i < children.size(); i++) {
                if(!visited[children[i]]) {
                    nds.push(children[i]);
                    visited[children[i]] = true;
                }
            }
        }
    }

private:
    int n;
    vector<vector<int> > vertices;
};

int main() {
    graph p(5);
    p.add_edge(1, 2);
    p.add_edge(1, 3);
    p.add_edge(3, 4);
    p.add_edge(2, 5);

    p.bfs(1);
    cout << endl;
    p.dfs(1);

}
