class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        vector<int> counts(2001, -1);

        for (int num : nums) {
            counts[num]++;
        }
        for (int i = 2000; i >= 0; i--) {
            if (counts[i] == 0)
                return i;
        }
        return -1;
    }
};