#include <vector>
#include <algorithm>
using namespace std;
    
void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    int j;
    while(i >= 0 && nums[i] >= nums[i + 1]){
        --i;
    }
    if (i >= 0){
        j = nums.size() - 1;
    while(nums[j] <= nums[i]){
        --j;
    }
    swap(nums[i],nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}