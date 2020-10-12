#include<bits/stdc++.h>
using namespace std;

int swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

class heap {
public:
    heap(int initial_capacity = 6): size(0), capacity(initial_capacity) {
        data = new int[capacity];
    }

    heap(const heap& hp) {
        copy_heap(hp);
    }

    heap& operator=(const heap& hp) {
        if(this != &hp) {
            delete_heap();
            copy_heap(hp);
        }
    }

    ~heap() {
        delete_heap();
    }

    void insert(const int& x) {
        if(size >= 0.75 * capacity) {
            resize();
        }

        data[size++] = x;


        int i = size - 1;
        while(i != 0 && data[get_parent(i)] > data[i]) {
            swap(data[get_parent(i)], data[i]);
            i = get_parent(i);
        }
    }

    int extract_min() {
        if(size < 1) {
            return INT_MIN;
        }

        if(size == 1) {
            size--;
            return data[0];
        }

        int temp = data[0];
        data[0] = data[size - 1];
        size--;

        min_heapify(0);

        return temp;
    }

    bool is_empty() const {
        return size == 0;
    }

    void delete_at_index(int index) {
        decrease_at_index(index, INT_MIN);
        extract_min();
    }

private:
    int* data;
    int size;
    int capacity;

    void copy_heap(const heap& hp) {
        size = hp.size;
        capacity = hp.capacity;

        for(int i = 0; i < size; i++) {
            data[i] = hp.data[i];
        }
    }

    void delete_heap() {
        delete[] data;
    }

    void resize() {
        capacity *= 2;
        int* new_data = new int[capacity];

        for(int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }

        delete[] data;

        data = new_data;
    }

    void min_heapify(int index) {
        int left = get_left(index);
        int right = get_right(index);

        int min_index = index;

        if(left < size && data[left] < data[index]) {
            min_index = left;
        }

        if(right < size && data[right] < data[min_index]) {
            min_index = right;
        }

        if(min_index != index) {
            swap(data[min_index], data[index]);
            min_heapify(min_index);
        }
    }

    int get_parent(int index) {
        return (index - 1) / 2;
    }

    int get_left(int index) {
        return 2 * index + 1;
    }

    int get_right(int index) {
        return 2 * index + 2;
    }

    void decrease_at_index(int index, int value) {
        data[index] = value;

        int i = index;
        while(i != 0 && data[get_parent(i)] > data[index]) {
            swap(data[i], data[get_parent(i)]);
            i = get_parent(i);
        }
    }
};

int main() {
    heap p;

    p.insert(3);
    p.insert(1);
    p.insert(6);
    p.insert(12);
    p.insert(111);

    while(!p.is_empty()) {
        cout << p.extract_min() << " ";
    }
}
