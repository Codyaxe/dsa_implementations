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
    for(int i = 1; i < size; i++){
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]){
            temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    printArray(arr, size);


    return 0;
}