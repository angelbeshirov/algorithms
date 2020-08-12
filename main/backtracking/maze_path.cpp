/**
    Finds and prints the shortest path in a maze of the type
     '0' '0' '0' '0' '^' '0' '0' '1'
     '0' '1' '1' '1' '1' '1' '0' '0'
     '0' '0' '0' '0' '0' '1' '1' '1'
     '0' '1' '1' '1' '0' '1' '0' '0'
     '0' '1' '0' '1' '0' '0' '0' '1'
     '0' '0' '0' '1' '0' '1' '0' '*'

     using backtracking where '0' is passing cell, '1' is blocked cell, ^ is starting cell, * is target is cell.
     The allowed moves are up, down, left and right. The maze can be of arbitrary size.

     Note: There are no guarantees that the found solution will be the shortest one.

     @author angelbeshirov
**/

#include <bits/stdc++.h>
using namespace std;

#define MAX_MOVES 1000

pair<int, int> get_start_position(char maze[][8], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0 ; j < n; j++) {
            if(maze[i][j] == '^') {
                return make_pair(i, j);
            }
        }
    }

    return make_pair(-1, -1);
}

void print_solution(char* sol, int length) {
    cout << "Solution is: \n";
    for(int i = 0; i < length; i++) {
        switch(sol[i]) {
            case 'D': {
                cout << "DOWN\n";
                break;
            }
            case 'U': {
                cout << "UP\n";
                break;
            }
            case 'L': {
                cout << "LEFT\n";
                break;
            }
            case 'R': {
                cout << "RIGHT\n";
                break;
            }
        }
    }
}

bool get_paths(char maze[][8], char* sol, int& i, bool visited[][8], int x, int y, int m, int n) {
    visited[x][y] = true;

    if(maze[x][y] == '*') {
        return true;
    }

    bool concat = false;

    if(x + 1 < m && !visited[x + 1][y] && maze[x + 1][y] != '1') {
        sol[i++] = 'D';
        if(get_paths(maze, sol, i, visited, x + 1, y, m, n)) {
            return true;
        } else i--;
    }
    if(x - 1 >= 0 && !visited[x - 1][y] && maze[x - 1][y] != '1') {
        sol[i++] = 'U';
        if(get_paths(maze, sol, i, visited, x - 1, y, m, n)){
            return true;
        } else i--;
    }

    if(y + 1 < n && !visited[x][y + 1] && maze[x][y + 1] != '1') {
        sol[i++] = 'R';
        if(get_paths(maze, sol, i, visited, x, y + 1, m, n)) {
            return true;
        } else i--;
    }

    if(y - 1 >= 0 && !visited[x][y - 1] && maze[x][y - 1] != '1') {
        sol[i++] = 'L';
        if(get_paths(maze, sol, i, visited, x, y - 1, m, n)) {
            return true;
        } else i--;
    }

    visited[x][y] = false;

    return false;
}

int main() {
    const int m = 6;
    const int n = 8;
    char maze[m][n] = {  {'0', '0', '0', '0', '0', '0', '^', '1'},
                         {'0', '1', '1', '1', '1', '1', '0', '0'},
                         {'0', '0', '0', '0', '0', '1', '1', '1'},
                         {'0', '1', '1', '1', '0', '1', '0', '0'},
                         {'0', '1', '0', '1', '0', '0', '0', '1'},
                         {'0', '0', '0', '1', '0', '1', '0', '*'}
                      };
    char* sol = new char[MAX_MOVES];

    bool visited[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0 ; j < n; j++) {
            visited[i][j] = false;
        }
    }

    int i = 0;
    pair<int, int> st  = get_start_position(maze, m, n);
    if(get_paths(maze, sol, i, visited, st.first, st.second, m, n)) {
        print_solution(sol, i);
    } else {
        cout << "There is no solution!";
    }

}
