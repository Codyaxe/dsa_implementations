#include <iostream>
using namespace std;



class Queue{

    private:

    int* arr;
    int front;
    int rear;
    int size;

    public:

    Queue() : front(-1), rear(-1), size(10)
    { arr = new int[size]; }
    Queue(int s) : front(-1), rear(-1), size(s)
    { arr = new int[size]; }

    void enqueue(int val){
        if (rear == -1){
            arr[++rear] = val;
            ++front;
        } else {
            rear = (rear + 1) % size;
            if (front == rear){
                cout << "The Queue is full!";
                return;
            } else {
                arr[rear] = val;
            }
        }
    }
    int dequeue(){
        if (rear == -1){
            cout << "The Queue is empty";
            return -1;
        } else {
            int temp {arr[front]};
            arr[front] = -1;
            front = (front + 1) % size;
            return temp;
        }
    }

    ~Queue(){
        delete[] arr;
    }
};

int main(){
    Queue q(10);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    // cout << q.dequeue() << '\n';
    q.enqueue(6);
    // cout << q.dequeue() << '\n';


}
