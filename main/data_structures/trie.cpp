#include<bits/stdc++.h>
using namespace std;

struct node {
    char data;
    vector<node*> children;
    bool is_word;

    node(char _data): data(_data), children(vector<node*>(26, NULL)), is_word(false) {};
};
class trie {
public:
    trie(): root(new node('\0')) {};

    void insert(const char* p) {
        node* cur = root;
        int i = 0;
        while(p[i]) {
            int index = p[i] - 'a';
            if(!cur->children[index]) {
                cur->children[index] = new node(p[i]);
            }

            cur = cur->children[index];
            i++;
        }

        cur->is_word = true;
    }

    bool search(const char* word) {
        node* cur = root;
        int i = 0;

        while(word[i]) {
            int index = word[i] - 'a';
            if(cur->children[index] == NULL) {
                return false;
            }

            cur = cur->children[index];
            i++;
        }

        return cur != NULL && cur->is_word;
    }

    bool is_empty_node(node* p) {
        for(int i = 0; i < 26; i++) {
            if(p->children[i] != NULL) {
                return false;
            }
        }

        return true;
    }

    void delete_key(const char* key) {
        delete_key(root, key, 0);
    }

    void delete_key(node*& root, const char* t, int depth) {
        if(root) {
            if(depth == strlen(t)) {
                root->is_word = false;

                bool is_empty = is_empty_node(root);

                if(is_empty) {
                    delete root;
                    root = NULL;
                }

                return;
            }

            int index = t[depth] - 'a';
            delete_key(root->children[index], t, depth + 1);
            if(is_empty_node(root->children[index]) && root->children[index]->is_word == false) {
                delete root->children[index];
                root->children[index] = NULL;
            }
        }
    }

private:
    node* root;
};
int main() {
    trie tr;

    tr.insert("asphalt");
    tr.insert("asphalt");
    tr.insert("aspha");
    tr.delete_key("aspha");
    cout << tr.search("aspha");
}
