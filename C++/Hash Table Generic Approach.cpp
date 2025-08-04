#include <iostream>
#include <utility>
#include <functional>
using namespace std;

template <typename K, typename V, typename Hash = std::hash<K>>
class HashTable {
private:
    pair<K, V>* arr;
    bool* occupied;
    bool* deleted;
    int size;
    Hash hasher;

public:
    HashTable(int x) : size(x) {
        arr = new pair<K, V>[x];
        occupied = new bool[x]{};
        deleted = new bool[x]{};
    }

    ~HashTable() {
        delete[] arr;
        delete[] occupied;
        delete[] deleted;
    }

    int hashFunction(const K& key) {
        return hasher(key) % size;
    }

    void insert(const K& key, const V& value) {
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

    void del(const K& key) {
        int hash = hashFunction(key);
        int i = hash;
        int start = hash;

        do {
            if (occupied[i] && arr[i].first == key) {
                arr[i] = pair<K, V>(); 
                occupied[i] = false;
                deleted[i] = true; // tombstone
                return;
            }
            i = (i + 1) % size;
        } while (i != start);

        cerr << "No key to delete!" << '\n';
    }

    V retrieve(const K& key) {
        int hash = hashFunction(key);
        int i = hash;
        int start = hash;
        int firstDeleted = -1;

        do {
            if (!occupied[i] && !deleted[i]) break;
            if (deleted[i] && firstDeleted == -1) {
                firstDeleted = i;
            }
            if (occupied[i] && arr[i].first == key) {
                if (firstDeleted != -1) {
                    arr[firstDeleted] = arr[i];
                    occupied[firstDeleted] = true;
                    deleted[firstDeleted] = false;

                    arr[i] = pair<K, V>();
                    occupied[i] = false;

                    return arr[firstDeleted].second;
                }
                return arr[i].second;
            }
            i = (i + 1) % size;
        } while (i != start);

        cerr << "Key does not exist!" << '\n';
        return V();
    }
};

int main(){

    HashTable<int, string> ht(10);

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