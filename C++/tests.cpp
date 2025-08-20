#include <iostream>
using namespace std;

int main(){
    
    int size;            
    cout << "Enter the size of the array: ";
    cin >> size;
    
    cout << "Enter the elements of the array:" << '\n';
    int arr[size];

    for(int i = 0; i < size; i++){
        cout << "Element " << i << ": ";
        cin >> arr[i];
        
    }
    
    
    for(int i = 0; i < size; i++){
        if (arr[i] == 0) {
            int j = i;
            while (j < size - 1){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                j++;
            }
        }
    }

    cout << "Array with zeros moved to the end: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    
    
    
    return 0;
}