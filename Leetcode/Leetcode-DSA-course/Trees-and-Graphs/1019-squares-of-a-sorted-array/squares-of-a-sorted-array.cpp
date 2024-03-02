class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int j = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int i = j - 1;
        vector<int> ans;
        while (i >= 0 && j < nums.size()) {
            if (abs(nums[i]) <= nums[j]) {
                ans.push_back(nums[i] * nums[i]);
                i--;
            } else {
                ans.push_back(nums[j] * nums[j]);
                j++;
            }
        }
        while (i >= 0) {
            ans.push_back(nums[i] * nums[i]);
            i--;
        }
        while (j < nums.size()) {
            ans.push_back(nums[j] * nums[j]);
            j++;
        }
        return ans;
    }
};