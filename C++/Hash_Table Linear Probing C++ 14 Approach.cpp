#include <iostream>
#include <utility>
#include <string>
using namespace std;

class HashTable{

private:

    pair<int,string>* arr;
    bool* occupied;
    bool* deleted;
    int size;

public:

    HashTable(int x) : 
    size(x) 
    { arr = new pair<int,string>[x]; 
    occupied = new bool[x]{}; 
    deleted = new bool[x]{}; }


    int hashFunction(int key){
        return key * 2 % size;
    }

    void insert(int key, string value){
        int hash = hashFunction(key);
        int i = hash;
        int firstDeleted = -1;

        int count = 0;
        while ((occupied[i] || deleted[i]) && count < size) {
            if (occupied[i] && arr[i].first == key) {
                arr[i].second = value; 
                return;
            }
            if (deleted[i] && firstDeleted == -1) {
                firstDeleted = i;  
            }
            i = (i + 1) % size;
            count++;
        }

        if (count == size && firstDeleted == -1) {
            cerr << "HashTable is full!" << '\n';
            return;
        }

        int target = (firstDeleted != -1) ? firstDeleted : i;
        arr[target] = {key, value};
        occupied[target] = true;
        deleted[target] = false;
    }

    void del(int key){
        int hash = hashFunction(key);

        int i = hash;
        int start = hash;
        do {
            if(occupied[i] && arr[i].first == key){
                arr[i]= {0, ""};
                occupied[i] = false;
                deleted[i] = true; //tombstone
                return;
            }
            i = (i + 1) % size;   
        } while (i != start);

        cerr << "No key to delete!" << '\n';
    }

    string retrieve(int key){
        int hash = hashFunction(key);
        int i = hash;

        int start = hash;
        int firstDeleted = -1;
        do {
            if (!occupied[i] && !deleted[i]) break;
            if (deleted[i] && firstDeleted == -1){
                firstDeleted = i;
            }
            if (occupied[i] && arr[i].first == key) {
                if (firstDeleted != -1){
                    arr[firstDeleted] = arr[i];
                    occupied[firstDeleted] = true;
                    deleted[firstDeleted] = false;

                    arr[i] = {0, ""};
                    occupied[i] = false;
                    
                    return arr[firstDeleted].second;
                }
                return arr[i].second;
            }
            i = (i + 1) % size;
        } while (i != start);

        cerr << "Key does not exist!" << '\n';
        return "";
    }


};

int main(){

    HashTable ht(10);

    ht.insert(1, "Troy");
    cout << ht.retrieve(1) << '\n';
    ht.insert(2, "Jyv");
    cout << ht.retrieve(2) << '\n';
    ht.insert(11, "Vince");
    cout << ht.retrieve(11) << '\n';
    ht.del(11);
    cout << ht.retrieve(11) << '\n';




    return 0;
}