class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> map;
        int sum = 0;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < nums.size(); right++) {
            map[nums[right]]++;
            sum += nums[right];
            while (map[nums[right]] > 1) {
                map[nums[left]]--;
                sum -= nums[left];
                left++;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};