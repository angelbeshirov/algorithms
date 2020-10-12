#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    int height;

    node(int x): data(x), left(NULL), right(NULL), height(1) {};
};

class bst {
public:
    bst(): root(NULL) {};

    bst(const bst& bs) {
        copy_bst(root, bs.root);
    }

    bst& operator=(const bst& bs) {
        if(this != &bs) {
            delete_bst(root);
            copy_bst(root, bs.root);
        }

        return *this;
    }

    ~bst() {
        delete_bst(root);
    }

    void add_node(int x) {
        add_node(root, x);
    }

    void inorder_traversal() {
        inorder_traversal(root);
    }

    void preorder_traversal() {
        preorder_traversal(root);
    }

    void postorder_traversal() {
        postorder_traversal(root);
    }

private:
    node* root;

    void copy_bst(node*& dest, node* source) {
        if(!source) {
            return;
        }

        dest = new node(source->data);

        copy_bst(dest->left, source->left);
        copy_bst(dest->right, source->right);
    }

    void delete_bst(node*& nd) {  //reference to pointer and not a copy of pointer;
        if(nd) {
            delete_bst(nd->left);
            delete_bst(nd->right);
            delete nd;
            nd = NULL;
        }
    }

    void inorder_traversal(node* r) {
        if(r) {
            inorder_traversal(r->left);
            cout << r->data << " ";
            inorder_traversal(r->right);
        }
    }

    void preorder_traversal(node* r) {
        if(r) {
            cout << r->data << " ";
            inorder_traversal(r->left);
            inorder_traversal(r->right);
        }
    }

    void postorder_traversal(node* r) {
        if(r) {
            inorder_traversal(r->left);
            inorder_traversal(r->right);
            cout << r->data << " ";
        }
    }

    void add_node(node*& r, int x) {
        if(r == NULL) {
            r = new node(x);
            return;
        }

        // r != null
        if(r->data < x) {
            add_node(r->right, x);
        } else {
            add_node(r->left, x);
        }
    }
};

int main() {
    bst p;

    p.add_node(1);
    p.add_node(33);
    p.add_node(2);
    p.add_node(11);
    p.add_node(4);
    p.add_node(8);
    p.preorder_traversal();

    cout << endl;
    bst st = p;
    st.inorder_traversal();
}
