class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int num : nums)
            counts[num]++;
        pair<int, int> p; // first -> num, second -> count
        for (auto entry : counts) {
            if (entry.second > p.second) {
                p = entry;
            }
        }
        return p.first;
    }
};