#include<iostream>
#include<vector>
using namespace std;

struct node {
    char c;
    int n;
    vector<node*> children;
};

class tree {
public:
    tree() {
        root = new node();
        root->c = 'a';
        root->n = 2;
    }

    ~tree() {
        delete root;
    }

    tree(const tree& tr) {
        // TODO
    }

    tree& operator=(const tree& tr) {
        // TODO
        return *this;
    }

    void print() {
        cout << root->c;
    }
private:
    node* root;
};

int sumVal(node& u, node& v) {

}


int main() {
    tree m;
    m.print();
}
