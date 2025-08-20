#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 5;

struct Node {
    int data;
    int priority;

    Node():
        data(numeric_limits<int>::min()), priority(numeric_limits<int>::min()) {}

    Node(int x, int y):
        data(x), priority(y) {}
};

struct Comparator {
    bool operator()(const Node& x, const Node& y) {
        return x.priority < y.priority;
    }
};

class Queue {
private:
    Node arr[MAX_SIZE];
    int size;

    void sort_array() {
        sort(arr, arr + MAX_SIZE, Comparator());
    }

public:
    Queue() : size(0) {
        for (int i = 0; i < MAX_SIZE; ++i)
            arr[i] = Node();
    }

    void enqueue(int data, int priority) {
        if (size == MAX_SIZE) {
            cout << "Queue is full\n";
            return;
        }

        for (int i = 0; i < MAX_SIZE; ++i) {
            if (arr[i].priority == numeric_limits<int>::min()) {
                arr[i] = Node(data, priority);
                ++size;
                return;
            }
        }
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }

        sort_array();

        for (int i = MAX_SIZE - 1; i >= 0; --i) {
            if (arr[i].priority != numeric_limits<int>::min()) {
                arr[i] = Node(); 
                --size;
                return;
            }
        }
    }

    int first() {
        if (size == 0) {
            cout << "Empty!\n";
            return numeric_limits<int>::min();
        }

        sort_array();
        for (int i = 0; i < MAX_SIZE; ++i) {
            if (arr[i].priority != numeric_limits<int>::min())
                return arr[i].data;
        }

        cout << "Empty!\n";
        return numeric_limits<int>::min();
    }

    int back() {
        if (size == 0) {
            cout << "Empty!\n";
            return numeric_limits<int>::min();
        }

        sort_array();
        for (int i = MAX_SIZE - 1; i >= 0; --i) {
            if (arr[i].priority != numeric_limits<int>::min())
                return arr[i].data;
        }

        cout << "Empty!\n";
        return numeric_limits<int>::min();
    }

    void print() {
        sort_array();
        for (int i = 0; i < MAX_SIZE; ++i) {
            if (arr[i].priority != numeric_limits<int>::min())
                cout << "(" << arr[i].data << ", " << arr[i].priority << ") ";
            else
                cout << "(null) ";
        }
        cout << '\n';
    }
};



int main(){

    Queue q;

    q.print();
    q.enqueue(12, 1);
    q.print();
    q.enqueue(2, 45);
    q.enqueue(4, 7);
    q.enqueue(5, 12);
    q.enqueue(7, 8);
    q.print();
    q.dequeue();
    q.enqueue(1, 99);
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();


    return 0;
}