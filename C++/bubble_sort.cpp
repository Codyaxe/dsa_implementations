#include <iostream>
using namespace std;

void printArray(int* arr, int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

}

int main(){

    int size = 9;
    int arr[size] = {6,9,1,3,6,7,4,3,2};
    int temp;
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printArray(arr, size);


    return 0;
}