class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (int num : arr)
            counts[num]++;

        unordered_map<int, int> freq;
        for (auto [key, val] : counts) {
            freq[val]++;
            if (freq[val] > 1)
                return false;
        }

        return true;
    }
};