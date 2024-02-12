// Given an integer array nums and an integer k, find the sum of the subarray with the largest sum whose length is k.

#include <bits/stdc++.h>
using namespace std;

int getMaxSum(vector<int>& nums, int k) {
    int curr = 0;
    for (int i = 0;i < k;i++)
        curr += nums[i];
    int ans = curr;
    for (int i = k;i < nums.size();i++) {
        curr += nums[i] - nums[i - k];
        ans = max(ans, curr);
    }

    return ans;
}

int main() {
    vector<int> nums = { 3,-1,4,12 ,-8,5,6 };
    int k = 4;
    cout << getMaxSum(nums, k) << endl;
}
