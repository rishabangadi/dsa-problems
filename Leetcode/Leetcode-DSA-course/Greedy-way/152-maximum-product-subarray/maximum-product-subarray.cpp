class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int temp_max = max(curr, max(curr * max_so_far, curr * min_so_far));
            min_so_far = min(curr, min(curr * min_so_far, curr * max_so_far));
            max_so_far = temp_max;
            result = max(result, max_so_far);
        }
        return result;
    }
};