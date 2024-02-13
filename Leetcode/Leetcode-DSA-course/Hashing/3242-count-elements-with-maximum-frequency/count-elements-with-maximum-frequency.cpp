class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        int max_freq = 1;
        for (int num : nums) {
            freq[num]++;
            max_freq = max(max_freq, freq[num]);
        }
        int sum = 0;
        for (int i = 1; i < 101; i++) {
            if (freq[i] == max_freq)
                sum += freq[i];
        }
        return sum;
    }
};