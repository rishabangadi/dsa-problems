class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0;
        int curr_cost = 0;
        int ans = 0;
        for (int right = 0;right < s.length();right++) {
            curr_cost += abs(s[right] - t[right]);
            while (curr_cost > maxCost) {
                curr_cost -= abs(s[left] - t[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};