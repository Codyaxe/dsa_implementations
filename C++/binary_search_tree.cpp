#include <iostream>
using namespace std;


struct Node{

    int value;
    Node* left;
    Node* right;

    Node(int x, Node *ptr, Node *ptr2) : 
    value(x), left(ptr), right(ptr2)
    {}
};

class BST{

public:

    Node* root;

    BST() : 
    root(nullptr)
    {}

    void insertNode(int value){
        if (root == nullptr){
            root = &Node(value, nullptr, nullptr);
        }
        insertRec(value, root);
    }
    void insertRec(int value, Node* currentRoot){
        Node* current = currentRoot;
        if (current == nullptr){
            current->value = value;
            return;
        } 
        
        if (value > current->value){
            insertRec(value, current->right);
        } else {
            insertRec(value, current->left);
        }
    }

    void deleteNode(int value){
        if (root == nullptr){
            cout << "Your Tree is Empty";
            return;
        }
        deleteRec(value, root);
    }

    void deleteRec(int value, Node* currentRoot){
        Node* current = currentRoot;

          
    }

    void searchNode(){
        //do nothing
    }

    void traverse(){
        //do nothing
    }


};

int main(){




    return 0;
}