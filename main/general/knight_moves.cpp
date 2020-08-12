/**
    The program finds all squares reachable from a starting position on a chess board for a number of moves.
    It uses BFS type of traversal of the chessboard.

    @author angelbeshirov
**/

#include <bits/stdc++.h>

using namespace std;

int mvsdiff[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

vector<pair<int, int>> get_children(int start_col, int start_row) {
    vector<pair<int, int>> children;
    for(int i = 0; i < 8; i++) {
        int new_col = start_col + mvsdiff[i][0];
        int new_row = start_row + mvsdiff[i][1];

        if(new_col >= 1 && new_col <= 8 && new_row >= 1 && new_row <= 8) {
            children.push_back(make_pair(new_row, new_col));
        }
    }

    return children;
}

string convert_to_str(char col, int row) {
    return string(1, col) + to_string(row);
}

vector<string> knight_moves(char start_col, int start_row, int num_moves) {
    vector<string> result;
    bool visited[9][9];
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            visited[i][j] = false;
        }
    }

    visited[start_row][start_col - 'a' + 1] = true;
    vector<pair<int, int>> prev_layer;


    prev_layer.push_back(make_pair(start_col - 'a' + 1, start_row));
    result.push_back(convert_to_str(start_col, start_row));
    while(num_moves-- > 0) {
        vector<pair<int, int>> next_layer;

        while(!prev_layer.empty()) {
            pair<int, int> pr = prev_layer.back();
            prev_layer.pop_back();

            vector<pair<int, int>> children = get_children(pr.first, pr.second);

            for(int j = 0; j < children.size(); j++) {
                if(!visited[children[j].first][children[j].second]) {
                    next_layer.push_back(make_pair(children[j].first, children[j].second));
                    result.push_back(convert_to_str(children[j].first - 1 + 'a', children[j].second));
                    visited[children[j].first][children[j].second] = true;
                }
            }
        }

        prev_layer = next_layer;
    }




    return result;
}

int main() {
    char start_col = 'a';
    int start_row = 1;
    int num_moves = 2;

    vector<string> moves = knight_moves(start_col, start_row, num_moves);

    cout << "Number of moves reachable from " << start_col << start_row << " in " << num_moves << " moves:" << endl;
    for(int i = 0; i < moves.size(); i++) {
        cout << moves[i] << " ";
    }
}
