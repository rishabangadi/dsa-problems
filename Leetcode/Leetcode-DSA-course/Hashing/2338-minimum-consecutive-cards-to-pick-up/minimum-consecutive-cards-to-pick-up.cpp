class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> counts;
        int ans = INT_MAX;
        int left=0;
        for (int right = 0; right < cards.size(); right++) {
            counts[cards[right]]++;
            while (counts[cards[right]] >= 2) {
                ans = min(ans, right - left + 1);
                counts[cards[left]]--;
                left++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};