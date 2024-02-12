// If an element majority_element occurs more than n/2 times, then there are at least n/2 elements of identical values with num at each bit. 
// That is, we can reconstruct the exact value of num by combining the most frequent value (0 or 1) at each bit.


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority_element = 0;
        for (int i = 0;i < 32;i++) {
            int bit = 1 << i;
            int bit_count = 0;
            for (int num : nums)
                if ((num & bit) != 0)
                    bit_count++;
            if (bit_count > n / 2) {
                majority_element |= bit;
            }
        }
        return majority_element;
    }
};