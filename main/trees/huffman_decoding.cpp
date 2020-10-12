/**
    Link: https://www.hackerrank.com/challenges/tree-huffman-decoding/problem

    Description: Huffman encoding described in the problem. 0 - left, 1 - right if leaf return path, left contains chars

    Approach: if 0 go left, if 1 go right keep track of the index, if leaf return the path, while index < n do this.

    @author angel.beshirov
**/

#include<bits/stdc++.h>
using namespace std;

typedef struct node {
    int freq;
    char data;
    node * left;
    node * right;
} node;

struct deref:public binary_function<node*, node*, bool> {
  	bool operator()(const node * a, const node * b)const {
        return a->freq > b->freq;
    }
};

typedef priority_queue<node *, vector<node*>, deref> spq;

node * huffman_hidden(string s) {

    spq pq;
    vector<int>count(256,0);

    for(int i = 0; i < s.length(); i++ ) {
        count[s[i]]++;
    }

    for(int i=0; i < 256; i++) {

        node * n_node = new node;
        n_node->left = NULL;
        n_node->right = NULL;
        n_node->data = (char)i;
        n_node->freq = count[i];

        if( count[i] != 0 )
        	pq.push(n_node);

    }

    while( pq.size() != 1 ) {

        node * left = pq.top();
        pq.pop();
        node * right = pq.top();
        pq.pop();
        node * comb = new node;
        comb->freq = left->freq + right->freq;
        comb->data = '\0';
        comb->left = left;
        comb->right = right;
        pq.push(comb);

    }

    return pq.top();

}

void print_codes_hidden(node * root, string code, map<char, string>&mp) {

  	if(root == NULL)
        return;

  	if(root->data != '\0') {
        mp[root->data] = code;
    }

    print_codes_hidden(root->left, code+'0', mp);
    print_codes_hidden(root->right, code+'1', mp);

}

/*
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;

} node;

*/

char get_char(node* root, string s, int& index, int n) {
    if(root->data != '\0' && !root->left && !root->right) {
        return root->data;
    }

    if(index < n && s[index] == '0') {
        return get_char(root->left, s, ++index, n);
    } else if(index < n && s[index] == '1') {
        return get_char(root->right, s, ++index, n);
    }

    return '\0';
}

void decode_huff(node* root, string s) {
    int index = 0;
    int n = s.size();
    string output_string = "";

    while(index < n) {
        output_string += (get_char(root, s, index, n));
    }

    cout << output_string << endl;
}

int main() {

    string s;
    std::cin >> s;

    node * tree = huffman_hidden(s);
    string code = "";
    map<char, string>mp;

    print_codes_hidden(tree, code, mp);

    string coded;

    for( int i = 0; i < s.length(); i++ ) {
        coded += mp[s[i]];
    }

    decode_huff(tree,coded);

    return 0;
}
