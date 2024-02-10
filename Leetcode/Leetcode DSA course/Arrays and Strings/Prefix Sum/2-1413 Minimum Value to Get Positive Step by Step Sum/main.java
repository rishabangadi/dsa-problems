class Solution {
    public int minStartValue(int[] nums) {
        int minVal = 0;
        int total = 0;
        for (int i = 0; i < nums.length; i++) {
            total += nums[i];
            minVal = Math.min(minVal, total);
        }

        return -minVal + 1;
    }
}