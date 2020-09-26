#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/**
    Link: https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks/problem
    Description: Implement queue using 2 stacks:
    Approach one: when pushing element put all elements from stack1 to stack2 then push the element to stack2 and push all elements from stack2 to stack 1
        pop and top are straight forward just get the head element
    Approach two: When pushing element just push it onto stack1
    When poping/toping if stack2 is empty put all elements from stack1 in stack2 (this will reverse the order) and get the top of stack2

    @author angel.beshirov
**/

class MyQueue {

    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;
        void push(int x) {
            /*while(!stack_newest_on_top.empty()) {
                int x1 = stack_newest_on_top.top();
                stack_newest_on_top.pop();
                stack_oldest_on_top.push(x1);
            }*/

            stack_newest_on_top.push(x);

            /*while(!stack_oldest_on_top.empty()) {
                int x1 = stack_oldest_on_top.top();
                stack_oldest_on_top.pop();
                stack_newest_on_top.push(x1);
            }*/
        }

        void pop() {
            if(stack_oldest_on_top.empty()) {
                while(!stack_newest_on_top.empty()) {
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
            }

            stack_oldest_on_top.pop();
        }

        int front() {
            if(stack_oldest_on_top.empty()) {
                while(!stack_newest_on_top.empty()) {
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
            }

            return stack_oldest_on_top.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
