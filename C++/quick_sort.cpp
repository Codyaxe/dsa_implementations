#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

<<<<<<< HEAD
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

=======
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
    
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
}

int main(){

<<<<<<< HEAD
    vector<int> test {5,6,7,4,3,46,6};
    quick_sort(test, 0, test.size() - 1);

    for(auto x :  test){
=======
    vector<int> test {4,8,9,7,6,5,3,5};

    quick_sort(test, 0, test.size() - 1);

    for(const auto& x :  test){
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
        cout << x << " ";
    }


<<<<<<< HEAD
=======
    return 0;
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
}