class Solution {
    public int maxProduct(int[] nums) {
        if (nums.length == 0)
            return 0;
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.length; i++) {
            int curr = nums[i];
            int temp_max = Math.max(curr, Math.max(curr * max_so_far, curr * min_so_far));
            min_so_far = Math.min(curr, Math.min(curr * min_so_far, curr * max_so_far));
            max_so_far = temp_max;
            result = Math.max(result, max_so_far);
        }
        return result;
    }
}