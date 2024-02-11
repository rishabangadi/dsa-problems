class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int left = 0, ans = Integer.MAX_VALUE, sum = 0;
        for (int right = 0; right < nums.length; right++) {
            sum += nums[right];
            while (sum >= target) {
                ans = Math.min(ans, right - left + 1);
                sum -= nums[left++];
            }
        }
        return (ans == Integer.MAX_VALUE) ? 0 : ans;
    }
}