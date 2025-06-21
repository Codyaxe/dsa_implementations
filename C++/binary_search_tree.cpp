#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//Implementation using raw pointers
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
            root = new Node(value, nullptr, nullptr);
            return;
        }
        root = insertRec(value, root);
    }
    Node* insertRec(int value, Node* currentRoot){
        if (currentRoot == nullptr){
            currentRoot = new Node(value, nullptr, nullptr);
            return currentRoot;
        } 
        //Comparator
        if (value >= currentRoot->value){
            currentRoot->right = insertRec(value, currentRoot->right);
        } else {
            currentRoot->left = insertRec(value, currentRoot->left);
        }
        return currentRoot;
    }

    void deleteNode(int value){
        if (!root){
            cout << "Your Tree is Empty";
            return;
        }
        deleteRec(value, root);
    }

    Node* deleteRec(int value, Node* currentRoot){
        if (!currentRoot){
            return nullptr;
        }
        if (value > currentRoot->value){
            currentRoot->right = deleteRec(value, currentRoot->right);
        } else if (value < currentRoot->value) {
            currentRoot->left = deleteRec(value, currentRoot->left);
        } else {
            if (!currentRoot->left && !currentRoot->right){
                delete currentRoot;
                return nullptr;
            } else if (currentRoot->left != nullptr || currentRoot->right != nullptr){
                Node* child = currentRoot->left != nullptr ? currentRoot->left : currentRoot->right;
                delete currentRoot;
                return child;
            } else {
                //Find min on the right subtree, swap then "recurse delete" from the right child to found successor.
                Node* successor = searchSmallestNode(currentRoot->right);
                currentRoot->value = successor->value;
                deleteRec(successor->value, currentRoot->right);
            }
            
        }
        return currentRoot;
          
    }

    Node* searchSmallestNode(Node* rightNode){
        Node* current = rightNode;
        if (!current){
            return current;
        }
        return searchSmallestNode(current->left);
    }

    Node* searchNode(int value){
        if (!root){
            cout << "Your Tree is Empty";
            return nullptr;
        }
        return searchRec(value, root);
    }

    Node* searchRec(int value, Node* currentRoot){
        Node* current = currentRoot;

        if (!current){
            cout << "The value does not exist!";
            return nullptr;
        }

        if (current->value == value){
            return current;
        }

        //Comparator
        if (value >= current->value){
            return searchRec(value, current->right);
        } else {
            return searchRec(value, current->left);
        }
    }

    //BFS
    void traverse(){
        if (!root){
            return;
        }

        deque<Node*> queue {};
        queue.push_back(root);

        while(!queue.empty()){
            Node* current = queue.front();
            cout << current->value << '\n';

            if (current->left){
                queue.push_back(current->left);
            }
            if (current->right){
                queue.push_back(current->right);
            }
            queue.pop_front();
        }       
    }

};

int main(){

    BST test;

    test.insertNode(2);
    test.insertNode(6);
    test.insertNode(1);
    test.insertNode(8);
    test.insertNode(12);
    test.insertNode(1);
    test.traverse();
    cout << '\n';
    test.deleteNode(12);
    test.traverse();



    return 0;
}