#include<iostream>
using namespace std;

template<typename T>
struct node {
    T element;
    node<T>* next;

    node(T _element, node<T>* _next) {
        element = _element;
        next = _next;
    }
};

template<typename T>
class lqueue {
public:
    lqueue();
    lqueue(const lqueue&);
    lqueue<T>& operator=(const lqueue&);
    ~lqueue();

    // main functions
    void push(const T&);
    T pop();

    T top() const;
    bool isEmpty() const;
    int length() const;
    void print() const;


private:
    node<T>* head;
    node<T>* tail;

    void copyQueue(const lqueue<T>&);
    void deleteQueue();
};

template<typename T>
lqueue<T>::lqueue() {
    head = tail = NULL;
}

template<typename T>
lqueue<T>::lqueue(const lqueue<T>& q1) {
    copyQueue(q1);
}

template<typename T>
lqueue<T>& lqueue<T>::operator=(const lqueue<T>& q1) {
    if(this != &q1) {
        deleteQueue();
        copyQueue(q1);
    }

    return *this;
}

template<typename T>
lqueue<T>::~lqueue() {
    deleteQueue();
}

template<typename T>
void lqueue<T>::push(const T& element) {
    if(head == NULL) {
        head = new node<T>(element, NULL);
    } else if(head != NULL && tail == NULL) {
        tail = new node<T>(element, NULL);
        head->next = tail;
    } else {
        node<T>* s = new node<T>(element, NULL);
        tail->next = s;
        tail = s;
    }
}

template<typename T>
T lqueue<T>::pop() {
    T element;
    if(head == NULL) {
        cout << "The queue is empty!";
        exit(1);
    } else {
        node<T>* nodeToDelete = head;
        head = head->next;
        T element = nodeToDelete->element;
        delete nodeToDelete;
        return element;
    }
}

template<typename T>
T lqueue<T>::top() const {
    T element;
    if(head == NULL) {
        cout << "The queue is empty!";
        exit(1);
    } else {
        return head->element;
    }
}
template<typename T>
bool lqueue<T>::isEmpty() const {
    return head == NULL && tail == NULL;
}

template<typename T>
int lqueue<T>::length() const {
    node<T>* temp = head;
    int n = 0;

    while(temp) {
        n++;
        temp = temp->next;
    }

    return n;
}

template<typename T>
void lqueue<T>::print() const {
    node<T>* temp = head;
    int n = 0;

    while(temp) {
        cout << temp->element << " ";
        temp = temp->next;
    }
}

template<typename T>
void lqueue<T>::copyQueue(const lqueue<T>& other) {
    if(other.head) {
        node<T>* s = other.head;
        head = new node<T>(s->element, NULL);
        s = s->next;

        if(s) {
            tail = new node<T>(s->element, NULL);
            head->next = tail;
            s = s->next;
            while(s) {
                node<T>* newNode = new node<T>(s->element, NULL);
                tail->next = newNode;
                tail = newNode;
                s = s->next;
            }
        } else {
            tail = NULL;
        }
    } else {
        head = NULL;
    }
}

template<typename T>
void lqueue<T>::deleteQueue() {
    while(head) {
        node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    head = tail = NULL;
}

int main() {
    lqueue<int> s;
    s.push(1);
    s.push(3);
    s.push(6);
    s.push(1);
    s.push(4);
    lqueue<int> s1 = s;
    s1.print();
    s.print();
}
