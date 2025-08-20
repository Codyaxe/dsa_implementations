#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x, Node* y): 
    data(x), next(y)
    {}
};


class LinkedList{

public:
    Node* head;
    int size;

    LinkedList() :
    head(nullptr), size(0)
    {};

    void append_node(int x){
        if (!head){
            Node* new_node = new Node(x, nullptr);
            head = new_node;
            size += 1;
        } else {
            Node* current = head;
            while (current->next){
                current = current->next;
            }
            Node* new_node = new Node(x, nullptr);
            current->next = new_node;
            size += 1;
        }
    }

    void insert_node(int x, int index){
        if (!head){
            Node* new_node = new Node(x, nullptr);
            head = new_node;
            size += 1;
        } else {
            Node* current = head;
            if (index == 0){
                Node* new_node = new Node(x, current);
                head = new_node;
                size += 1;
            } else {
                for(int i = 0; i < index - 1; i++){
                    current = current->next;
                }
                Node* new_node = new Node(x, current->next);
                current->next = new_node;
                size += 1;
            }

        }
    }

    void delete_node(int index){
        if (!head){
            cout << "Linked List is empty!" << '\n';
            return;
        } else if (index > size){
            cout << "Index is out of range: Linked List" << '\n';
            return;
        } else {
            Node* current = head;
            if (index == 0){
                head = current->next;
                delete current;
                size -= 1;
            } else if (index == size){
                Node* current_2 = current->next;
                while (current_2->next){
                    current = current->next;
                    current_2 = current_2->next;
                }
                current->next = nullptr;
                delete current_2;
                size -= 1;
            } else {
                for(int i = 0;  i < index - 1; i++){
                    current = current->next;
                }
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                size -= 1;
            }
        }
    }

    void print_linked_list(){
        Node* current = head;
        for(int i = 0; i < size; i++){
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << '\n';
    }
};

int main(){

    LinkedList* test = new LinkedList();

    test->append_node(10);
    test->append_node(30);
    test->append_node(60);
    test->append_node(70);
    test->print_linked_list();
    test->delete_node(4);
    test->print_linked_list();
}