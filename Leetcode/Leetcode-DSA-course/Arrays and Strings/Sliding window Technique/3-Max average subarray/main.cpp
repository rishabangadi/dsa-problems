class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int curr = 0;
        for (int i = 0; i < k; i++)
            curr += nums[i];
        double ans = curr;
        for (int i = k; i < nums.size(); i++) {
            curr += nums[i] - nums[i - k];
            ans = max(ans, (double)curr);
        }
        return ans / k;
    }
};