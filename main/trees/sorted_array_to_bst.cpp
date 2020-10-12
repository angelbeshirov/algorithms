#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    node(int _data): data(_data), left(NULL), right(NULL) {};
};

node* sorted_array_to_bst(int* a, int left, int right) { // inclusive

    if(right < left) {
        return NULL;
    }


    int mid_point = right - (right - left) / 2;

    node* p = new node(a[mid_point]);

    p->left = sorted_array_to_bst(a, left, mid_point - 1);
    p->right = sorted_array_to_bst(a, mid_point + 1, right);

    return p;
}

void inorder_traversal(node* p) {
    if(p == NULL) {
        return;
    }
    inorder_traversal(p->left);
    cout << p->data << " ";
    inorder_traversal(p->right);
}

int main() {
    int arr[] = {1, 3, 5, 9, 11};
    int n = 5;

    node* root;
    root = sorted_array_to_bst(arr, 0, n - 1);
    inorder_traversal(root);
}
