#include <iostream>
using namespace std;

int* insertion_sort(int* arr, int size){
    for(int i = 0; i < size; i++){
        int j = i + 1;
        while(j > 0 && arr[j] < arr[j - 1]){
            int temp;
            temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int* selection_sort(int* arr, int size){
    int min;
    for(int i = 0; i < size; i++){
        for (int j = i; j < size; j++){
            if(arr[j] > arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int* bubble_sort(int* arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size -  1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}