/**

    Description: Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

    A Node is defined as:
    struct Node {
        int data;
        Node* next;

        Node(int _data): data(_data) {

        }
    };

    Approach: Rabbit-Turtle approach, let 1 point be faster than the other if they ever meet there is a cycle.

    @author angel.beshirov
**/
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int _data): data(_data) {

    }
};

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(!head) {
        return false;
    }

    Node* turtle = head;
    Node* rabbit = head->next;

    while(turtle && rabbit && rabbit->next) {
        if(turtle == rabbit) {
            return true;
        }

        turtle = turtle->next;
        rabbit = rabbit->next->next;
    }

    return false;
}

int main() {
    {
        Node* t1 = new Node(1);
        Node* t2 = new Node(2);
        Node* t3 = new Node(3);
        Node* t4 = new Node(4);
        Node* t5 = new Node(5);

        t1->next = t2;
        t2->next = t3;
        t3->next = t4;
        t4->next = t5;
        t5->next = t3;

        cout << has_cycle(t1);
    }
    cout << endl;
    {
        Node* t1 = new Node(1);
        Node* t2 = new Node(2);
        Node* t3 = new Node(3);
        Node* t4 = new Node(4);
        Node* t5 = new Node(5);

        t1->next = t2;
        t2->next = t3;
        t3->next = t4;
        t4->next = t5;
        t5->next = NULL;

        cout << has_cycle(t1);
    }


}
