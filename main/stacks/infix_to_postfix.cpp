#include<bits/stdc++.h>
using namespace std;

bool is_operator(char p) {
    return p == '+' || p == '-' || p == '*' || p == '/' || p == '^';
}

short precedence(char op) {
    switch(op) {
        case '^': {
            return 3;
            break;
        }
        case '*': {

        }
        case '/': {
            return 2;
            break;
        }

        case '+' : {

        }
        case '-': {
            return 1;
            break;
        }

        default: {
            return -1;
        }
    }
}

string infix_to_postfix(string& s) {
    int n = s.size();
    string res = "";
    stack<char> st;
    for(int i = 0; i < n; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            res += s[i];
        } else if(s[i] == '(') {
            st.push('(');
        } else if(is_operator(s[i])) {
            while(!st.empty() && is_operator(st.top()) && precedence(st.top()) >= precedence(s[i])) {
                res += st.top();
                st.pop();
            }

            st.push(s[i]);

        } else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }

            if(!st.empty()) {
                st.pop();
            }
        }
    }

    while(!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

int main() {
    string s = "(a+b)*c+d";

    cout << infix_to_postfix(s);
}
