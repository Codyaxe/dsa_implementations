#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& vect, int left, int right){

    int pivot = vect[right];

    int j = left - 1;
    for(int i = left; i <= right; i++){
        if(vect[i] < pivot){
            j++;
            swap(vect[j], vect[i]);
        }
    }
    swap(vect[j + 1], vect[right]);

    return j + 1;
}



void quick_sort(vector<int>& vect, int left, int right){

    if (left < right){
        int pi = partition(vect, left, right);
        quick_sort(vect, left, pi - 1);
        quick_sort(vect, pi + 1, right);
    }
    
}

int main(){

    vector<int> test {4,8,9,7,6,5,3,5};

    quick_sort(test, 0, test.size() - 1);

    for(const auto& x :  test){
        cout << x << " ";
    }


    return 0;
}