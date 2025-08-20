#include <iostream>
#include <queue>
using namespace std;

struct Node{

    int value;
    Node* left;
    Node* right;

    Node() : value(-1), left(nullptr), right(nullptr)  
    {}

    Node(int x) : value(x), left(nullptr), right(nullptr)  
    {}

    Node(int x, Node* l, Node* r) : value(x), left(l), right(r)  
    {}

};

class BST{

private:

    Node* root;

    Node* findsuccesor(Node* current){
        while(current->left != nullptr){
            current = current->left;
        }
        return current;
    } 

    void inordertraversal(Node* current){
        if (current != nullptr){
            inordertraversal(current->left);
            cout << current->value;
            inordertraversal(current->right);
        }
    }

    void preordertraversal(Node* current){
        if (current != nullptr){
            cout << current->value;
            preordertraversal(current->left);
            preordertraversal(current->right);
        }
    }

    void postordertraversal(Node* current){
        if (current != nullptr){
            postordertraversal(current->left);
            postordertraversal(current->right);
            cout << current->value;
        }
    }

    void breadthfirsttraversal(Node* current){

        if (current) {

            queue<Node*> q;
            q.push(current);

            while(!q.empty()){
                Node* front = q.front();
                q.pop();
                cout << front->value << " ";
                if (front->left){
                    q.push(front->left);
                } 
                if (front->right){
                    q.push(front->right);
                }
            }
        }
    }

public:

    BST() : root(nullptr)
    {}

    void insert(int data){
        root = intrec(data, root);
    }

    Node* intrec(int data, Node* current){

        if (current == nullptr){
            Node* newNode = new Node(data);
            current = newNode;
        } else {
            if(data >= current->value){
                current->right = intrec(data, current->right);
            } else {
                current->left = intrec(data, current->left);
            }
        }
        return current;
    }

    void del(int data){
        root = delrec(data, root);
    }

    Node* delrec(int data, Node* current){

        if (current == nullptr){
            cout << "Value does not exist!" << '\n';
        } else if (current->value != data){
            if (data >= current->value){
                current->right = delrec(data, current->right);
            } else {
                current->left = delrec(data, current->left);
            }
        } else {
            if (current->left == nullptr && current->right == nullptr){
                Node* temp = current;
                current = nullptr;
                delete temp;
            } else if (current->left == nullptr || current->right == nullptr){
                if (current->right == nullptr){
                    Node* temp = current;
                    current = current->left;
                    delete temp;
                } else {
                    Node* temp = current;
                    current = current->right;
                    delete temp;
                }
            } else {
                Node* successor = findsuccesor(current->right);
                current->value = successor->value;
                current->right = delrec(successor->value, current->right);
            }
        } 
        return current;
    }

    void preordertraversal(){
        preordertraversal(root);
    }

    void inordertraversal(){
        inordertraversal(root);
    }

    void postordertraversal(){
        postordertraversal(root);
    }

};




int main(){






    return 0;
}