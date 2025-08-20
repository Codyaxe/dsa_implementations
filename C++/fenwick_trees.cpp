#include <iostream>
using namespace std;

struct Node{

    int value;
    int index;

};


//First Non-Value In Prefix Sum is in Index 0;
struct Fenwick{

    private:

    Node* tree;
    int size;

    int lsb(int i){
        return i & -i;
    }

    public:

    Fenwick() : size{10}
    {tree = new Node[10];};

    Fenwick(int x) : size{x}
    {tree = new Node[x];};

    Fenwick(int x, int arr[]) : size{x}
    {   tree = new Node[x];

        tree[0].value = 0;

        for(int i = 1; i < x; ++i){
            (tree + i)->value = arr[i];
            (tree + i)->index = i;
        }
        
        for(int i = 1; i < x; ++i){
            int j = i + lsb(i);
            if (j < x){
                tree[j].value = tree[j].value + tree[i].value;
            }
        }

    };

    ~Fenwick(){
        delete[] tree;
    }

    int calcPrefix(int i){
        int sum {};
        while(i != 0){
            sum += (tree + i)->value;
            i = i - lsb(i);
        }
        return sum;
    }

    int rangeQuery(int i, int j){
        return calcPrefix(j) - calcPrefix(i - 1);
    }

    void pointrangeadd(int i, int val){
        while (i < size){
            (tree + i)->value = i + val;
            i = i + lsb(i);
        }
    }

    void print(){
        
        for(int i = 0; i < size; ++i){
            cout << (tree + i)->value << " ";
        }
        cout << '\n';
    }


};

int main(){

    int arr[10] {0,1,2,3,4,5,6,7,8,9};

    Fenwick fw(10, arr);

    fw.print();

    fw.pointrangeadd(1, 2);

    fw.print();
}

//0, 1, 3, 3, 10, 5, 11, 7, 36, 9
