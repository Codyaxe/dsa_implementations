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
    int min;
    int temp;
    for(int i = 0; i < size; i++){
        min = i;
        for (int j = i + 1; j < size; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printArray(arr, size);


    return 0;
}