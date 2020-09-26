#include <bits/stdc++.h>

using namespace std;

char corresponding(char s) {
    if(s == ')') return '(';
    if(s == ']') return '[';
    if(s == '}') return '{';
}

// Complete the isBalanced function below.
string isBalanced(string s) {
    if(s.length() == 0) {
        return "YES";
    }
    int n = s.length();

    stack<char> st;

    int i = 0;
    while(i < n || !st.empty()) {
        if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if(st.empty()) {
                return "NO";
            } else {
                char m = st.top();
                if(m != corresponding(s[i])) {
                    //cout << "Checking " << s[i] << " and " << m << endl;
                    return "NO";
                }
                st.pop();
            }
        } else st.push(s[i]);
        i++;
    }

    return "YES";
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    ostream& fout = cout;

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    //fout.close();

    return 0;
}
