#include <iostream>
using namespace std;

void printArray(int* arr, int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

}

void bubble_sort(int* arr, int size){
    int temp;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int* arr, int size){
    int j;
    int temp;
    for(int i = 1; i < size; i++){
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]){
            temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }


}

void selection_sort(int* arr, int size){
    int min;
    int temp;
    for(int i = 0; i < size; i++){
        min = i;
        for(int j = i + 1; j < size; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main(){

    int arr[5] {5,4,3,2,1};

    // insertion_sort(arr, 5);

    selection_sort(arr, 5);

    // bubble_sort(arr, 5);

    printArray(arr, 5);



    return 0;    
}