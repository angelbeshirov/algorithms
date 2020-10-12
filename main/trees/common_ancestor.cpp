/**
    Link: https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem

    Description: Find the lowest common ancestor of two distinct nodes i.e. they must have the same parent (direct or indirect)

    Approach:
    Note if they have the same parent which is left subtree they can not have also the right subtree, so this branches the Solution
    If the left subtree is a common parent save it and check for left and right again recursively.

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

bool search_for(Node* root, int x) {
    if(root) {
        if(root->data == x) {
            return true;
        }

        return search_for(root->left, x) || search_for(root->right, x);
    }

    return false;
}



    Node* lca(Node* root, int v1, int v2) {
		if(root) {
            Node* prev = NULL;
            bool is_accessible = search_for(root, v1) && search_for(root, v2);
            prev = root;
            while(is_accessible) {
                is_accessible = search_for(prev->left, v1) && search_for(prev->left, v2);
                if(is_accessible) {
                    prev = prev->left;
                } else {
                    is_accessible = search_for(prev->right, v1) && search_for(prev->right, v2);
                    if(is_accessible) {
                        prev = prev->right;
                    }
                }
            }

            return prev;

        }

        return NULL;
    }

}; //End of Solution

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

  	int v1, v2;
  	std::cin >> v1 >> v2;

    Node *ans = myTree.lca(root, v1, v2);

  	std::cout << ans->data;

    return 0;
}
