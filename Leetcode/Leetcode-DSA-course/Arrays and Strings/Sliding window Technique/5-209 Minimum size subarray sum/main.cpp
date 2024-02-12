class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, ans = INT_MAX, sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};