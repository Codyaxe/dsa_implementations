#include <iostream>
#include <limits>
using namespace std;


const int MAX_SIZE = 100;

class Queue{

private: 

    int arr[MAX_SIZE];
    int front;
    int rear;

public:

    Queue() : 
    front(-1), rear(-1)
    {for(int i = 0; i < MAX_SIZE; i++){
        arr[i] = numeric_limits<int>::min();
    }
    };

    void enqueue(int x){
        if (front == -1){
            ++front;
            arr[++rear] = x;
            return;
        }
        arr[++rear] = x;
    }

    void dequeue(){
        if (front == -1 || arr[front] == numeric_limits<int>::min()){
            cout << "Queue is empty!" << '\n';
            return;
        }
        arr[front] = numeric_limits<int>::min();
        ++front;
    }

    int first(){
        if (front == -1){
            cout << "Empty!" << '\n';
            return -1;
        }
        return arr[front];
    }

    int back(){
        if (rear == -1){
            cout << "Empty!" << '\n';
            return -1;
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
    cout << q.first() << '\n';
    q.dequeue();
    cout << q.first() << '\n';
    q.dequeue();
    cout << q.first() << '\n';
    q.enqueue(666);
    q.dequeue();
    cout << q.first() << '\n';
    q.dequeue();
    cout << q.first() << '\n';
    q.dequeue();
    cout << q.first() << '\n';
    q.dequeue();
    q.dequeue();



    return 0;
}