#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& vect, int low, int high){
    int pivot = vect[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++){
        if(vect[j] < pivot){
            i++;
            swap(vect[i], vect[j]);
        }
    }
    swap(vect[i + 1], vect[high]);

    return i + 1;
}

void quick_sort(vector<int>& vect, int low, int high){
    if(low < high){
        int pi = partition(vect, low, high);
        quick_sort(vect, low, pi - 1);
        quick_sort(vect, pi + 1, high);
    }
}

int main(){
    vector<int> test {4,8,9,7,6,5,3,5};

    quick_sort(test, 0, test.size() - 1);

    for(const auto& x : test){
        cout << x << " ";
    }

    return 0;
}