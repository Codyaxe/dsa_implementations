#include <iostream>
using namespace std;

//Simple Fixed Sized Array

class Stack {

    private:

    int arr[100];
    int size = -1;

    public:

    void push(int value){
        if (size < 100){
            arr[++size] = value;
        } else {
            cerr << "Stack Overflow!" << '\n';
        }
    }

    int pop(){
        if(size == -1){
            cerr << "Error! Stack is empty." << '\n';
            return -1;
        } else {
            int value = arr[--size];
            return value;
        }
    }

    bool isFull(){
        if(size == 100){
            return 1;
        } else {
            return 0;
        }
    }

    bool isEmpty(){
        if(size == -1){
            return 1;
        } else {
            return 0;
        }
    }

    void peek(){
        cout << arr[size] << '\n';
    }

};

int main(){
    Stack s;

    s.push(1);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(9);
    s.peek();
    s.pop();
    s.peek();


}