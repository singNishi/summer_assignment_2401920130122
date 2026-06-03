#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        nums[i] = nums[i] * nums[i];
    }

    sort(nums.begin(), nums.end());

    return nums;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = sortedSquares(nums);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}