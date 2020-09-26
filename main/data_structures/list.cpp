#include<iostream>
using namespace std;

template<typename T>
struct node {
    T element;
    node<T>* next;

    node(T _element, node<T>* _next) : element(_element), next(_next) {};
};

template<typename T>
class llist {
public:
    llist();
    llist(const llist&);
    llist& operator=(const llist&);
    ~llist();

    // main operations
    void push_back(const T&);
    void push_front(const T&);
    T pop_back();
    T pop_front();
    T front();
    T back();

    // const operations
    int length() const;

    bool is_empty() const;

    // operators
    const T& operator[](int);

    friend ostream& operator<<(ostream& os, const llist<T>& l) {
        return l.print(os);
    }

    friend istream& operator>>(istream& is, llist<T>& l) {
        T element;
        while(cin >> element) {
            l.push_back(element);
        }

        return is;
    }


private:
    node<T>* head;
    node<T>* tail;

    void copy_list(const llist&);
    void delete_list();
    ostream& print(ostream&) const;
};

template<typename T>
llist<T>::llist(): head(NULL), tail(NULL) {}

template<typename T>
llist<T>::llist(const llist<T>& other) {
    copy_list(other);
}

template<typename T>
llist<T>& llist<T>::operator=(const llist<T>& other) {
    if(this != &other) {
        delete_list();
        copy_list(other);
    }

    return *this;
}

template<typename T>
llist<T>::~llist() {
    delete_list();
}

template<typename T>
void llist<T>::push_back(const T& element) {
    if(head == NULL) {
        head = new node<T>(element, NULL);
    } else if(head != NULL && tail == NULL) {
        tail = new node<T>(element, NULL);
        head->next = tail;
    } else {
        node<T>* p = new node<T>(element, NULL);
        tail->next = p;
        tail = p;
    }
}

template<typename T>
void llist<T>::push_front(const T& element) {
    if(head == NULL) {
        head = new node<T>(element, NULL);
    } else if(head != NULL && tail == NULL) {
        tail = head;
        head = new node<T>(element, tail);
    } else {
        node<T>* p = new node<T>(element, head);
        head = p;
    }
}

template<typename T>
T llist<T>::pop_back() {
    if(head == NULL) {
        cout << "The list is empty!";
        exit(1);
    } else if(head != NULL && tail == NULL) {
        node<T>* temp = head;
        T value = temp->element;
        head = tail = NULL;
        delete temp;
        return value;
    } else {
        node<T>* p = head;
        T value;
        if(p->next->next) {
            while(p->next->next) {
                p = p->next;
            }
            value = tail->element;
            delete tail;
            tail = p;
            tail->next = NULL;
        } else {
            head->next = NULL;
            node<T>* p = tail;
            value = p->element;
            delete tail;
            tail = NULL;
        }

        return value;
    }
}

template<typename T>
T llist<T>::pop_front() {
    if(head == NULL) {
        cout << "The list is empty!";
        exit(1);
    } else if(head != NULL && tail == NULL) {
        node<T>* temp = head;
        head = tail = NULL;
        T value = temp->element;
        delete temp;
        return value;
    } else {
        node<T>* p = head;
        T value = head->element;
        head = head->next;
        delete p;

        if(head == tail) {
            tail = NULL;
        }
        return value;
    }
}

template<typename T>
T llist<T>::front() {
    if(head == NULL) {
        cout << "The list is empty!";
        exit(1);
    } else {
        return head->element;
    }
}

template<typename T>
T llist<T>::back() {
    if(head == NULL) {
        cout << "The list is empty!";
        exit(1);
    } else if(tail == NULL) {
        return head->element;
    } else {
        return tail->element;
    }
}

template<typename T>
int llist<T>::length() const {
    node<T>* p = head;
    int n = 0;
    while(p) {
        n++;
        p = p->next;
    }

    return n;
}

template<typename T>
bool llist<T>::is_empty() const {
    return head == NULL;
}

template<typename T>
ostream& llist<T>::print(ostream& os) const {
    node<T>* p = head;
    while(p) {
        os << p->element << " ";
        p = p->next;
    }

    return os;
}

template<typename T>
void llist<T>::copy_list(const llist& other) {
    if(other.head) {
        node<T>* p = other.head;
        head = new node<T>(p->element, NULL);
        p = p->next;

        if(p) {
            tail = new node<T>(p->element, NULL);
            head->next = tail;
            p = p->next;

            while(p) {
                node<T>* temp = new node<T>(p->element, NULL);
                tail->next = temp;
                tail = temp;
                p = p->next;
            }
        } else {
            tail = NULL;
        }
    } else {
        head = tail = NULL;
    }
}

template<typename T>
void llist<T>::delete_list() {
    while(head) {
        node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
const T& llist<T>::operator[](int index) {
    node<T>* p = head;

    while(index-- > 0) {
        p = p->next;
    }

    return p->element;
}

int main() {
    llist<double> s1;
    //s1.push_front(12);
    //s1.push_front(11);
    //s1.push_back(111);
    //s1.push_back(123);
    //s1.pop_front();
    //s1.pop_front();
    //s1.pop_back();

    //s1.print();

    //cout << s1[0] << endl;
    //cout << s1[1] << endl;
    //cout << s1[2] << endl;
    //cout << s1[3] << endl;

    //cout << endl;
    //cout << s1 << endl;

    cin >> s1;
    cout << s1;
}
