#include <iostream>
using namespace std;

struct Item{
    int id;
    int price;
    int quantity;
    string name;

    Item() : 
    id(0), price(0), quantity(0), name("")
    {}

    Item(int x, int y, int z, string a) : 
    id(x), price(y), quantity(z), name(a)
    {}
};

void storeInventory(Item* inventory, int& size){
    int id;
    int price;
    int quantity;
    string name;

    Item* ptr = inventory;

    cout << "Enter id: ";
    cin >> id;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter quantity: ";
    cin >> quantity;

    Item new_item = Item(id, price, quantity, name);
    ptr[size] = new_item;
    size++;
}

void printInventory(Item* inventory, int& size){
    Item* ptr = inventory;
    
    for(int i = 0; i < size; i++){
        cout << "Item " << i + 1 << '\n'; 
        cout << "ID: " << ptr[i].id << '\n'; 
        cout << "Name: " << ptr[i].name << '\n'; 
        cout << "Price: " << ptr[i].price << '\n'; 
        cout << "Quantity: " << ptr[i].quantity << "\n\n"; 
    }

}

void calculateTotal(Item* inventory, int& size){
    Item* ptr = inventory;
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += ptr[i].price * ptr[i].quantity;
    }

    cout << "The total value of the entire inventory is: " << sum << '\n';

}

void findUpdate(Item* inventory, int& size, int id, int value){
    Item* ptr = inventory;
    for(int i = 0; i < size; i++){
        if(ptr[i].id == id){
            ptr[i].quantity = value;
        }
    }
}

int main (){

    Item inventory[100];
    int size = 0;

    storeInventory(inventory, size);
    storeInventory(inventory, size);
    printInventory(inventory, size);
    calculateTotal(inventory, size);
    findUpdate(inventory, size, 1, 20);
    printInventory(inventory, size);



    return 0;
}