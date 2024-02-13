class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> freq(101, 0);

        for (int num : nums) {
            freq[num]++;
        }
        int sum = 0;
        for (int i = 1; i < 101; i++) {
            if (freq[i] == 1)
                sum += i;
        }
        return sum;
    }
};