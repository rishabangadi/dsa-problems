class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewel_set(jewels.begin(), jewels.end());
        int ans = 0;
        for (char ch : stones) {
            if (jewel_set.find(ch) != jewel_set.end())
                ans++;
        }
        return ans;
    }
};