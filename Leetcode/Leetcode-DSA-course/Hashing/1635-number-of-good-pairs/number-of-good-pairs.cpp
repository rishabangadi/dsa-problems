class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> map;
        map[nums[0]]++;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end()) {
                ans += map[nums[i]];
            }
            map[nums[i]]++;
        }
        return ans;
    }
};