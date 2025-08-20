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

    vector<int> test {5,6,7,4,3,46,6};
    quick_sort(test, 0, test.size() - 1);

    for(auto x :  test){
        cout << x << " ";
    }


}