class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            if(nums[0] == 1) return 2;
            return 1;
        }
        bool is1 = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                is1 = true;
            else if (nums[i] < 1 || nums[i] > n)
                nums[i] = 1;
        }
        if (!is1)
            return 1;
        for (int i = 0; i < n; i++) {
            if(abs(nums[i]) == n){
                if(nums[0] > 0){
                    nums[0] = -nums[0];
                }
                continue;
            }
            if (nums[abs(nums[i])] > 0)
                nums[abs(nums[i])] = -nums[abs(nums[i])];
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0)
                return i;
        }
        if(nums[0] < 0) return n+1;
        return n;
    }
};