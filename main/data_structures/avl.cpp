#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    int height;

    node(int x): data(x), left(NULL), right(NULL), height(1) {};
};

class avl {
public:
    avl(): root(NULL) {};

    avl(const avl& bs) {
        copy_bst(root, bs.root);
    }

    avl& operator=(const avl& bs) {
        if(this != &bs) {
            delete_bst(root);
            copy_bst(root, bs.root);
        }

        return *this;
    }

    ~avl() {
        delete_bst(root);
    }

    void add_node(int x) {
        root = add_node_balanced(root, x);
    }

    void delete_node(int x) {
        root = delete_node(root, x);
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
        if(r->data < x) {
            add_node(r->right, x);
        } else {
            add_node(r->left, x);
        }
    }

    node* add_node_balanced(node*& r, int x) {
        if(r == NULL) {
            return new node(x);
        }

        if(r->data < x) {
            r->right = add_node_balanced(r->right, x);
        } else {
            r->left = add_node_balanced(r->left, x);
        }

        r->height = max(height(r->left), height(r->right)) + 1;

        int balance = get_balance(r);

        if(balance > 1 && x < r->left->data) { // the data is inserted into the left of the left subtree - only right rotate left left case
            right_rotate(r);
        }

        if(balance < -1 && x > r->right->data) { // the data is inserted into the right of the right subtree - only left rotate
            left_rotate(r);
        }

        if(balance > 1 && x > r->left->data) { // the data is inserted into the right of the left subtree - left right case
            left_rotate(r->left);
            right_rotate(r);
        }

        if(balance < -1 && x < r->right->data) { // the data is inserted into the left of the right subtree - right left case
            right_rotate(r->right);
            left_rotate(r);
        }

        return r;
    }

    int get_balance(node* nd) {
        if(!nd) {
            return 0;
        }

        int left = height(nd->left);
        int right = height(nd->right);

        return (left - right);
    }

    void left_rotate(node*& nd) {
        node* rg = nd->right;
        node* lf = rg->left;

        rg->left = nd;
        nd->right = lf;

        nd->height = max(height(nd->left), height(nd->right)) + 1;
        rg->height = max(height(rg->left), height(rg->right)) + 1;

        nd = rg;
    }

    void right_rotate(node*& nd) {
        node* lf = nd->left;
        node* rg = lf->right;

        lf->right = nd;
        nd->left = rg;

        nd->height = max(height(nd->left), height(nd->right)) + 1;
        lf->height = max(height(lf->left), height(lf->right)) + 1;

        nd = lf;
    }

    int height(node* nd) {
        return nd == NULL ? 0 : nd->height;
    }

    int get_min_value(node* root) {
        if(!root) {
            return -1;
        }

        if(root->left == NULL) {
            return root->data;
        } else {
            return get_min_value(root->left);
        }
    }

    node* delete_node(node* root, int x) {
        if(!root) {
            return NULL;
        }

        if(root->data < x) {
            root->right = delete_node(root->right, x);
        } else if(root->data > x) {
            root->left = delete_node(root->left, x);
        } else {
            node* temp;

            if(!root->left || !root->right) {
                temp = root->left ? root->left : root->right;

                if(temp) {
                    delete root;
                    root = temp;
                } else {
                    delete root;
                    root = NULL;
                    return root;
                }
            } else {
                int min_val = get_min_value(root->right);
                root->data = min_val;
                root->right = delete_node(root->right, min_val);
            }
        }

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = get_balance(root);

        if(balance > 1 && get_balance(root->left) >= 0) { // left left case
            right_rotate(root);
        }

        if(balance < -1 && get_balance(root->right) <= 0) { // right right case
            left_rotate(root);
        }

        if(balance > 1 && get_balance(root->left) < 0) { // left right case
            left_rotate(root->left);
            right_rotate(root);
        }

        if(balance < -1 && get_balance(root->right) > 0) { // right left case
            right_rotate(root->right);
            left_rotate(root);
        }

        return root;
    }
};

int main() {
    avl p;

    p.add_node(1);
    p.add_node(33);
    p.add_node(2);
    p.add_node(11);
    p.add_node(4);
    p.add_node(8);
    p.preorder_traversal();

    cout << endl;
    avl st = p;
    st.inorder_traversal();
    st.delete_node(11);
    cout << endl;
    st.inorder_traversal();
}
