#include <iostream>
#include <vector>
using namespace std;


int maxSum(vector<int>& nums, int k) {
    int windowSum = 0, maxSum = 0;

    for (int i = 0; i < k; ++i) {
        windowSum += nums[i];  // sum first window
    }

    maxSum = windowSum;

    cout << "Current " << windowSum << '\n';

    for (int i = k; i < nums.size(); ++i) {
        windowSum += nums[i] - nums[i - k];  // slide window
        cout << "IND: " << i << " VALUE: " << nums[i] << " IND_2: " << i - k << " VALUE_2: " << nums[i - k] << " " << windowSum << "\n";
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main(){

    vector<int> test {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int result = maxSum(test, 4);
    cout << "Result: " << result;

    return 0;
}