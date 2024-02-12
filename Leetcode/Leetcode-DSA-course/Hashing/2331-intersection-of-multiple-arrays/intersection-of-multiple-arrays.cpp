class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> counts;
        for (vector<int>& arr : nums) {
            for (int x : arr)
                counts[x]++;
        }
        vector<int> ans;
        int n = nums.size();
        for (auto [key, val] : counts) {
            if (val == n)
                ans.push_back(key);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};