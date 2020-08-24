#include <bits/stdc++.h>

/**
Swapping subtrees at depth 1K 2K 3K...


https://www.hackerrank.com/challenges/swap-nodes-algo/problem

Approach:
Construct tree from the input each node including it's height, using a queue.
After construction parse the tree from root and at each height %k = 0 swap left and right subtree,
then recursively invoke for left and right.
**/
using namespace std;

struct node {
    int idx;
    int height;
    node* left;
    node* right;
};

void inorder(vector<vector<int>> indexes, int x, vector<int>& indices, int ind_size) {
    if(indexes[x - 1][0] != -1) {
        inorder(indexes, indexes[x - 1][0], indices, ind_size);
    }

    indices.push_back(x);

    if(indexes[x - 1][1] != -1) {
        inorder(indexes, indexes[x - 1][1], indices, ind_size);
    }
}

void inorder(node* root, vector<int>& indices, int ind_size) {
    if(root->left) {
        inorder(root->left, indices, ind_size);
    }

    indices.push_back(root->idx);

    if(root->right) {
        inorder(root->right, indices, ind_size);
    }
}

node* createNode(int idx, int height) {
    node* nd = new node();
    nd -> idx = idx;
    nd -> height = height;
    nd -> left = nd -> right = NULL;

    return nd;
}

int determine_height(int j, int parents[1025]) {
    int height = 1;

    while(parents[j] != -1) {
        height += 1;
        j = parents[j];
    }

    return height;
}

vector<vector<int>> swapNodes_too_slow(vector<vector<int>> indexes, vector<int> queries) {
    int indexesSize = indexes.size();
    pair<int, int> parents[1025] = {make_pair(-1, -1)};
    int max_height = 1;

    for(int i = 0; i < indexesSize; i++) {
        if(indexes[i][0] != -1) {
            parents[indexes[i][0] - 1] = make_pair(i, 2);

            int j = i;
            int saved = indexes[i][0] - 1;

            while(parents[j].first != -1) {
                parents[saved].second += 1;
                j = parents[j].first;
            }

            if(max_height < parents[saved].second) {
                max_height = parents[saved].second;
            }
        }

        if(indexes[i][1] != -1) {
            parents[indexes[i][1] - 1] = make_pair(i, 2);

            int j = i;
            int saved = indexes[i][1] - 1;

            while(parents[j].first != -1) {
                parents[saved].second += 1;
                j = parents[j].first;
            }

            if(max_height < parents[saved].second) {
                max_height = parents[saved].second;
            }
        }
    }

    vector<vector<int>> result;
    for(int s = 0; s < queries.size(); s++) {
        int k = queries[s];

        for(int j = 0; j < indexesSize; j++) {
            if(parents[j].second % k == 0) {
                int temp = indexes[j][0];
                indexes[j][0] = indexes[j][1];
                indexes[j][1] = temp;
            }
        }
        vector<int> inorder_result;
        inorder(indexes, 1, inorder_result, indexesSize);
        result.push_back(inorder_result);
    }

    return result;
}

void swap_recursive(node* nd, int s) {
    if(nd == NULL) {
        return;
    }

    if(nd->height % s == 0) {
        node* temp = nd->left;
        nd->left = nd->right;
        nd->right = temp;
    }

    swap_recursive(nd->left, s);
    swap_recursive(nd->right, s);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    int indexesSize = indexes.size();
    vector<vector<int>> result;
    queue<node*> helper;

    node* nd = createNode(1, 1);

    helper.push(nd);

    for(int i = 0; i < indexesSize && !helper.empty(); i++) {
        node* s = helper.front();
        helper.pop();

        if(indexes[i][0] != -1) {
            node* left = createNode(indexes[i][0], s->height + 1);
            s -> left = left;
            helper.push(left);
        }

        if(indexes[i][1] != -1) {
            node* right = createNode(indexes[i][1], s->height + 1);
            s -> right = right;
            helper.push(right);
        }
    }

    for(int s = 0; s < queries.size(); s++) {
        int k = queries[s];

        swap_recursive(nd, k);
        vector<int> inorder_result;
        inorder(nd, inorder_result, indexesSize);
        result.push_back(inorder_result);
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    //std::ostream& fout = cout;

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
