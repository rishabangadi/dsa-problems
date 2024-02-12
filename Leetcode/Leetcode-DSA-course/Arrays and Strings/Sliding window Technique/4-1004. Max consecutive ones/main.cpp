class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int curr = 0, ans = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0)
                curr++;
            while (curr > k) {
                if (nums[left] == 0)
                    curr--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};