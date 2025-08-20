#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& vect, int left, int mid, int right){
    vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right){
        if(vect[i] <= vect[j]){
            temp.push_back(vect[i]);
            i++;
        } else {
            temp.push_back(vect[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(vect[i]);
        i++;
    }

    while(j <= right){
        temp.push_back(vect[j]);
        j++;
    }

    int k = left;
    for(int l = 0; l <= temp.size() - 1; l++){
        vect[k] = temp[l];
        k++;
    }
}

void merge_sort(vector<int>& vect, int left, int right){
    if (left >= right) return;

    int mid = left + (right - left)/2;
    merge_sort(vect, left, mid);
    merge_sort(vect, mid + 1, right);
    merge(vect, left, mid, right);
}

int main(){
    vector<int> test {2,3,4,5,6,14,6,7,8,4,3,65,99,7};

    merge_sort(test, 0, test.size() - 1);

    for(const auto& x : test){
        cout << x << " ";
    }

    return 0;
}