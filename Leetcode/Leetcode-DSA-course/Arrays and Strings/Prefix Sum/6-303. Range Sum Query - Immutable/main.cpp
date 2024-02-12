class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int prev = 0;
        for (int num : nums) {
            prefix.push_back(prev + num);
            prev = prev + num;
        }
    }

    int sumRange(int left, int right) {
        if (left == 0)
            return prefix[right];
        return prefix[right] - prefix[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */