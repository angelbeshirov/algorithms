#include<bits/stdc++.h>
using namespace std;

// 0 - black
// 1 - red

struct node {
    int data;
    node* left;
    node* right;
    node* parent;
    int color;

    node(int _data): data(_data), left(NULL), right(NULL), parent(NULL), color(1) {};
};

class rbt {
public:
    rbt() {};

    // TODO the big 4

    void insert_node(int x) {
        node* new_node = new node(x);

        root = insert_node(root, new_node);

        fix_violations(root, new_node);
    }

    void delete_node(int x) {

    }

private:
    node* root;

    void left_rotation(node*& r) {

    }

    void right_rotation(node*& r) {

    }

    // normal bst insertion
    node* insert_node(node* root, node* nd) {
        if(!root) {
            return nd;
        }

        if(nd->data < root->data) {
            root->left = insert_node(root->left, nd);
            root->left->parent = root;
        } else {
            root->right = insert_node(root->right, nd);
            root->right->parent = root;
        }

        return root;
    }

    void delete_node(node*& root, int x) {

    }

    void fix_violations(node*& root) {

    }


};
int main() {

}
