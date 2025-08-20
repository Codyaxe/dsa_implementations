#include <iostream>
#include <vector>
<<<<<<< HEAD
<<<<<<< HEAD
using namespace std;

void merge(vector<int>& vect, int left, int mid, int right){

    vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (vect[i] <= vect[j]) {
=======
=======
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1

using namespace std;


void merge(vector<int>& vect, int left, int mid, int right){

    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right){
        if(vect[i] <= vect[j]){
<<<<<<< HEAD
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
=======
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
            temp.push_back(vect[i]);
            i++;
        } else {
            temp.push_back(vect[j]);
            j++;
        }
    }

<<<<<<< HEAD
<<<<<<< HEAD
    while (i <= mid) {
=======

    while(i <= mid){
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
=======

    while(i <= mid){
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
        temp.push_back(vect[i]);
        i++;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    while (j <= right) {
=======
    while(j <= right){
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
=======
    while(j <= right){
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
        temp.push_back(vect[j]);
        j++;
    }

<<<<<<< HEAD
<<<<<<< HEAD
    for (int k = 0; k < temp.size(); ++k) {
        vect[left + k] = temp[k];
=======
=======
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
    int k = left;
    for(int l = 0; l <= temp.size() - 1; l++){
        vect[k] = temp[l];
        k++;
<<<<<<< HEAD
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
=======
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
    }

}

<<<<<<< HEAD
<<<<<<< HEAD
void merge_sort(vector<int>& vect, int left, int right){

    if (left >= right){
        return;
    }

    int mid = left + (right - left)/ 2;
=======
=======
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1


void merge_sort(vector<int>& vect, int left, int right){

    if (left >= right) return;

    int mid = left + (right - left)/2;
<<<<<<< HEAD
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
=======
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
    merge_sort(vect, left, mid);
    merge_sort(vect, mid + 1, right);
    merge(vect, left, mid, right);

<<<<<<< HEAD
<<<<<<< HEAD
=======
    
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
=======
    
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
}

int main(){

<<<<<<< HEAD
<<<<<<< HEAD

    vector<int> test {5,6,7,4,3,46,6};
    merge_sort(test, 0, test.size() - 1);

    for(auto x :  test){
        cout << x << " ";
    }

=======
=======
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
    vector<int> test {2,3,4,5,6,14,6,7,8,4,3,65,99,7};

    merge_sort(test, 0, test.size() - 1);

    for(const auto& x :  test){
        cout << x << " ";
    }


<<<<<<< HEAD
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
=======
>>>>>>> 71931ac6dfb76f9b833692e35eff62705f6f38e1
    return 0;
}