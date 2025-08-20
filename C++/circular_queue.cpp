#include <iostream>
#include <limits>
using namespace std;

const int MAX_SIZE = 5;

class Queue{
private: 
    int arr[MAX_SIZE];
    int front;
    int rear;
    int capacity;

public:
    Queue() : front(-1), rear(-1), capacity(0) {
        for(int i = 0; i < MAX_SIZE; i++){
            arr[i] = numeric_limits<int>::min();
        }
    }

    void enqueue(int x){
        if (front == -1 ){
            ++front;
            ++capacity;
            arr[++rear] = x;
            return;
        }
        if (capacity == MAX_SIZE){
            cout << "Queue is full" << '\n';
            return;
        }
        rear = ++rear % MAX_SIZE;
        arr[rear] = x;
        ++capacity;
    }

    void dequeue(){
        if (front == -1 || capacity == 0){
            cout << "Queue is empty!" << '\n';
            front = -1;
            rear = -1;
            return;
        }
        arr[front] = numeric_limits<int>::min();
        front = ++front % MAX_SIZE;
        --capacity;
    }

    int first(){
        if (front == -1 || arr[front] == numeric_limits<int>::min()){
            cout << "Empty!" << '\n';
            return numeric_limits<int>::min();
        }
        return arr[front];
    }

    int back(){
        if (rear == -1 || arr[front] == numeric_limits<int>::min()){
            cout << "Empty!" << '\n';
            return numeric_limits<int>::min();
        }
        return arr[rear];
    }
};

int main(){
    Queue q;

    q.enqueue(12);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(666);
    cout << q.first() << '\n';
    q.dequeue();
    cout << q.first() << '\n';
    q.dequeue();
    cout << q.first() << '\n';
    q.dequeue();
    cout << q.first() << '\n';
    q.dequeue();
    cout << q.first() << '\n';
    q.dequeue();
    cout << q.first() << '\n';
    q.dequeue();
    q.dequeue();
    q.enqueue(661);
    q.enqueue(662);
    cout << q.first() << '\n';
    cout << q.back() << '\n';
    q.enqueue(663);
    cout << q.back() << '\n';
    q.enqueue(664);
    cout << q.back() << '\n';
    q.enqueue(665);
    cout << q.back() << '\n';
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.back() << '\n';
    cout << q.first() << '\n';
    q.dequeue();
    q.dequeue();
    q.enqueue(666);
    cout << q.back() << '\n';
    cout << q.first() << '\n';
    q.dequeue();

    return 0;
}
