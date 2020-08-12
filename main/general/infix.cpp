/**
    Evaluator of fully-parenthesized infix expressions using recursion.

    For every binary operation there should be an opening and closing bracket.
    The supported operations are: '+', '-', '*', '/' and '^'.
    Negative numbers are supported without brackets i.e. the following is a valid expression: (1+-1) should be equal to 0.

    @author angelbeshirov
**/

#include <bits/stdc++.h>

using namespace std;

enum Type {
    openingbracket,
    closingbracket,
    operand,
    binaryoperator
};

class Tokenizer {
public:
    void add(string token, Type type) {
        data.push_back(make_pair(token, type));
    }

    pair<string, Type> next() {
        pair<string, Type> r;
        if (counter < data.size()) {
            r = data[counter];
            counter++;
        }

        return r;
    }

    bool hasNext() {
        return counter < data.size();
    }

    pair<string, Type> peek() {
        pair<string, Type> r;
        if (counter < data.size()) {
            r = data[counter];
        }

        return r;
    }

private:
    vector<pair<string, Type>> data;
    int counter = 0;
};

bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

bool isOperator(char c) {
    return c == '+' || c == '-' ||
           c == '*' || c == '/' ||
           c == '^';
}

double applyOperation(double left, char op, double right) {
    double result;
    switch (op) {
        case '+': {
            result = left + right;
            break;
        }
        case '-': {
            result = left - right;
            break;
        }
        case '*': {
            result = left * right;
            break;
        }
        case '/': {
            result = left / right;
            break;
        }
        case '^': {
            result = pow(left, right);
            break;
        }
        default: {
            result = left;
            break;
        }
    }

    return result;
};

Tokenizer tokenize(string expression) {
    Tokenizer tokenizer;
    int i = 0;
    int n = expression.size();
    char prevChar = ' ';

    for(int i = 0; i < n; i++) {
        char c = expression[i];

        if (isOperator(c) && (prevChar == '(' || isOperator(prevChar))) { // special case for numbers with sign
            int sign = c == '+' ? 1 : -1;
            i = i + 1;
            if (isNumber(expression[i])) {
                int operand = expression[i] - '0';
                while (i + 1 < n && isNumber(expression[i + 1])) {
                    operand = 10 * operand + (expression[i + 1] - '0');
                    i = i + 1;
                }
                tokenizer.add(std::to_string(sign * operand), Type::operand);
                prevChar = expression[i - 1];
            }
            continue;
        }

        if (c == '(') {
            tokenizer.add(std::string(1, c), Type::openingbracket);
        } else if (c == ')')  {
            tokenizer.add(std::string(1, c), Type::closingbracket);
        } else if (isOperator(c)) {
            tokenizer.add(std::string(1, c), Type::binaryoperator);
        } else if (isNumber(c)) {
            int operand = c - '0';
            while (i + 1 < n && isNumber(expression[i + 1])) {
                operand = 10 * operand + (expression[i + 1] - '0');
                i = i + 1;
            }

            tokenizer.add(std::to_string(operand), Type::operand);
        }
        prevChar = c;
    }

    return tokenizer;
}

double subeval(Tokenizer& tokenizer) {
    if (!tokenizer.hasNext()) {
        return 0;
    }

    pair<string, Type> pr = tokenizer.next();

	if (pr.second == Type::operand) {
        double x = atof(pr.first.c_str());
        return x;
    }

	double a = subeval(tokenizer);

    if (tokenizer.hasNext()) {
        pair<string, Type> oppr = tokenizer.next();
        if (oppr.second == Type::binaryoperator) {
            double b = subeval(tokenizer);

            pair<string, Type> nxpr = tokenizer.peek();
            if (nxpr.second == Type::closingbracket) {
                tokenizer.next();
            }

            return applyOperation(a, oppr.first.c_str()[0], b);
        } else {
            return a;
        }
    } else  {
        return a;
    }
}

string preprocess(string expression) {
    string newStr = "";
    for(int i = 0; i < expression.size(); i++) {
        char c = expression[i];
        if (c == '(' || c == ')' || isOperator(c) || isNumber(c)) {
            newStr += std::string(1, c);
        }
    }

    return newStr;
}

double evaluate(string expression) {
    string preprocessed = preprocess(expression);
    Tokenizer tokenizer = tokenize(preprocessed);
    return subeval(tokenizer);
}

int main() {
    cout << "(-1)=" << evaluate("(-1)") << endl;
    cout << "(1 + (2 + (3 + (4 + (6 + (7))))))=" << evaluate("(1 + (2 + (3 + (4 + (6 + (7))))))") << endl; // 23
    cout << "(1 * 2)=" << evaluate("(1 * 2)") << endl; // 2
    cout << "(2)=" << evaluate("(2)") << endl; // 2
    cout << "2=" << evaluate("2") << endl; // 2
    cout << "(2^(3^(1 +1)))=" << evaluate("(2^(3^(1 +1)))") << endl; // 512
    cout << "((1 + 2) * 4)=" << evaluate("((1 + 2) * 4)") << endl; // 12
    cout << "((1 + (2 + 3)) * 4)=" << evaluate("((1 + (2 + 3)) * 4)") << endl; // 24
    cout << "((1 + 2) * (3 + 4))=" << evaluate("((1 + 2) * (3 + 4))") << endl; // 21
    cout << "((2 ^ (2 + 3)) * 5)=" << evaluate("((2 ^ (2 + 3)) * 5)") << endl; // 160
    cout << "(((((((1 + 2) + 3) + (2+(1^2))) + 5) + 6) + 7) + 8)=" << evaluate("(((((((1 + 2) + 3) + (2+(1^2))) + 5) + 6) + 7) + 8)") << endl; // 35
    cout << "(2 + (-1))=" << evaluate("(2 + (-1))") << endl; // 1
    cout << "(2 ^ (-2))=" << evaluate("(2 ^ (-2))") << endl; // 0.25
    cout << "(((3 + 2) ^ (2 + 1)) * 5)=" << evaluate("(((3 + 2) ^ (2 + 1)) * 5)") << endl; // 625
    cout << "((-2) + (-1))=" << evaluate("((-2) + (-1))") << endl; // -3
    cout << "((  -   2) + (  -  1))=" << evaluate("((  -   2) + (  -  1))") << endl; // -3
    cout << "(   ( 10 +    (   2    *    3)) / 8   )=" << evaluate("(   ( 10 +    (   2    *    3)) / 8   )") << endl; // 2
}


