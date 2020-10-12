/**
    Link: https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid/problem

    Description: Find the largest connected grid in a matrix;

    Approach: BFS or DFS from each not visited position and mark the 1s as visited.

    @author angel.beshirov
**/

#include <bits/stdc++.h>

using namespace std;
/**
4
4
1 1 0 0
0 1 1 0
0 0 1 0
1 0 0 0
**/
vector<pair<int, int>> get_children(int x, int y, int n, int m, vector<vector<bool>>& visited, const vector<vector<int>>& grid) {
    vector<pair<int, int> > children;

    if(x - 1 >= 0 && grid[x - 1][y] == 1 && !visited[x - 1][y]) {
        children.push_back(make_pair(x - 1, y));
    }

    if(x + 1 < n && grid[x + 1][y] == 1 && !visited[x + 1][y]) {
        children.push_back(make_pair(x + 1, y));
    }

    if(y - 1 >= 0 && grid[x][y - 1] == 1 && !visited[x][y - 1]) {
        children.push_back(make_pair(x, y - 1));
    }

    if(y + 1 < n && grid[x][y + 1] == 1 && !visited[x][y + 1]) {
        children.push_back(make_pair(x, y + 1));
    }

    if(x - 1 >= 0 && y - 1 >= 0 && grid[x - 1][y - 1] == 1 && !visited[x - 1][y - 1]) {
        children.push_back(make_pair(x - 1, y - 1));
    }

    if(x + 1 < n && y + 1 < m && grid[x + 1][y + 1] == 1 && !visited[x + 1][y + 1]) {
        children.push_back(make_pair(x + 1, y + 1));
    }

    if(x - 1 >= 0 && y + 1 < m && grid[x - 1][y + 1] == 1 && !visited[x - 1][y + 1]) {
        children.push_back(make_pair(x - 1, y + 1));
    }

    if(x + 1 < n && y - 1 >= 0  && grid[x + 1][y - 1] == 1 && !visited[x + 1][y - 1]) {
        children.push_back(make_pair(x + 1, y - 1));
    }

    return children;
}

int dfs(int& x, int& y, int& n, int& m, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
    stack<pair<int, int> > nds;
    nds.push(make_pair(x, y));
    visited[x][y] = true;
    int res = 1;
    //cout << "Starting from " << x << " " << y << endl;
    while(!nds.empty()) {
        pair<int, int> o = nds.top();
        nds.pop();

        vector<pair<int, int>> children = get_children(o.first, o.second, n, m, visited, grid);
        for(int i = 0; i < children.size(); i++) {
            visited[children[i].first][children[i].second] = true;
            //cout << "Adding child " << children[i].first << " " << children[i].second << endl;
            nds.push(children[i]);
            res++;
        }
    }

    return res;
}
// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int max_region = INT_MIN;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && grid[i][j] == 1) {
                int region_size = dfs(i, j, n, m, visited, grid);
                if(max_region < region_size) {
                    max_region = region_size;
                }
            }
        }
    }

    return max_region;

}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    ostream& fout = cout;

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    //fout.close();

    return 0;
}
