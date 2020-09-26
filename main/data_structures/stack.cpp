#include<iostream>
using namespace std;


template<typename T>
struct node {
    T el;
    node<T>* next;

    node(T _el, node<T>* _next) {
        el = _el;
        next = _next;
    }

    node() {};
};

template<typename T>
class lstack {
public:
    lstack();
    lstack(const lstack<T>&);
    lstack& operator=(const lstack<T>&);
    ~lstack();

    // operations
    bool isEmpty() const;
    void push(const T&);
    T pop();
    T top() const;
    void print() const;
    int length() const;
private:
    node<T>* head;
    void copyStack(const lstack<T>&);
    void deleteStack();
};


template<typename T>
lstack<T>::lstack() : head(NULL) {};

template<typename T>
lstack<T>::lstack(const lstack<T>& s) {
    copyStack(s);
};

template<typename T>
lstack<T>& lstack<T>::operator=(const lstack<T>& s1) {
    if(this != &s1) {
        deleteStack();
        copyStack(s1);
    }

    return *this;
}

template<typename T>
lstack<T>::~lstack() {
    deleteStack();
}

template<typename T>
void lstack<T>::copyStack(const lstack<T>& s1) {
    if(s1.head) {
        node<T>* pointer = s1.head;
        head = new node<T>(pointer->el, NULL);

        node<T>* temp = head;
        pointer = pointer->next;

        while(pointer) {
            node<T>* newNode = new node<T>(pointer->el, temp);
            temp = newNode;
            pointer = pointer->next;
        }

        head = temp;

    } else {
        head = NULL;
    }
}

template<typename T>
void lstack<T>::deleteStack() {
    while(head) {
        node<T>* p = head;
        head = head->next;
        delete p;
    }
}

template<typename T>
bool lstack<T>::isEmpty() const {
    return head == NULL;
}

template<typename T>
void lstack<T>::push(const T& element) {
    node<T>* k = head;
    node<T>* newNode = new node<T>(element, k);
    head = newNode;
}

template<typename T>
T lstack<T>::pop() {
    if(head != NULL) {
        T el = head->el;
        node<T>* temp = head;
        head = head->next;
        delete temp;
        return el;
    } else {
        cout << "The stack is empty." << endl;
    }
}

template<typename T>
T lstack<T>::top() const {
    if(head != NULL) {
        T el = head->el;
        return el;
    } else {
        cout << "The stack is empty." << endl;
    }
}

template<typename T>
void lstack<T>::print() const {
    node<T>* temp = head;
    while(temp) {
        cout << temp->el << " ";
        temp = temp->next;
    }
}

template<typename T>
int lstack<T>::length() const {
    node<T>* temp = head;
    int n = 0;
    while(temp) {
        n++;
        temp = temp->next;
    }

    return n;
}

int main() {
    lstack<int> s;
    s.push(1);
    s.push(3);
    s.push(6);
    s.push(1);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.push(4);s.push(3);s.push(2);s.push(1);s.push(12);

    lstack<int> s1 = s;
    s1.print();

    cout << s1.length();
}
