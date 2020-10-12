/**
    Link: https://www.hackerrank.com/challenges/ctci-is-binary-search-tree/problem

    Description: Check if a binary tree is BST
    1) nodes in the left subtree are smaller than the root
    2) nodes in the right subtree are greater than the root
    3) all nodes are unique

    Approach 1: Do in-order traversal of the tree and keep the prev value, compare it with the next one and check if sorted (not so elegant)
    Approach 2: Recursively update the (min, max) range in which each node value should be in, if it is out of that range return false;

    @author angel.beshirov
**/

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

int prev = -1;
void inorder_traversal(Node* root, bool& done) {
    if(!root) {
        return;
    }

    inorder_traversal(root->left, done);

    if(root->data <= prev) {
        if(!done) {
            done = true;
        }
    }

    prev = root->data;

    inorder_traversal1(root->right, done);
}



bool checkBST(Node* root) {
    bool done = false;
    inorder_traversal1(root, done);
    return !done;
}

// solutions Number 2 much more elegant
bool doCheck(Node* root, int min, int max) {
    if(!root) {
        return true;
    }

    if(root->data <= min || root->data >= max) {
        return false;
    }

    return doCheck(root->left, min, root->data) && doCheck(root->right, root->data, max);
}

bool checkBST(Node* root) {
    return doCheck(root, INT_MIN, INT_MAX);
}

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

  	std::cout << checkBST(root);

    return 0;
}
