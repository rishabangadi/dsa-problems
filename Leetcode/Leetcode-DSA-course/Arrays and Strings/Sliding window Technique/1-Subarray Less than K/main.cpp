// https://leetcode.com/problems/subarray-product-less-than-k/description/

// Given an array of positive integers nums and an integer k, return the number of subarrays where the product of all the elements in the subarray is strictly less than k.
// For example, given the input nums = [10, 5, 2, 6], k = 100, the answer is 8. The subarrays with products less than k are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCount(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int curr = 1, left = 0, ans = 0;
        for (int right = 0;right < nums.size();right++) {
            curr *= nums[right];
            while (curr >= k) {
                curr /= nums[left++];
            }
            ans += right - left + 1;
            // cout<<"["<<left<<" ,"<<right<<"]"<<endl; // print [left,right] subarray bound
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 10,5,2,6 };
    int k = 100;
    cout << solution.getCount(nums, 100) << endl;;
    return 0;
}