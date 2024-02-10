class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0)
            return nums;
        int n = nums.size();
        int windowSize = 2 * k + 1;
        vector<int> avgs(nums.size(), -1);
        if (windowSize > n)
            return avgs;

        long long windowSum = 0;
        for (int i = 0;i < windowSize;i++)
            windowSum += nums[i];
        avgs[k] = windowSum / windowSize;

        for (int i = windowSize;i < n;i++)
        {
            windowSum += nums[i] - nums[i - windowSize];
            avgs[i - k] = windowSum / windowSize;
        }

        return avgs;
    }
};