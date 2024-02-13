class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> map;
        for (auto c : s)
            map[c]++;
        string ans = "";
        for (auto c : order) {
            if (map.find(c) != map.end()) {
                for (int i = 0; i < map[c]; i++)
                    ans += c;
                map.erase(c);
            }
        }
        for (auto [key, val] : map) {
            for (int i = 0; i < val; i++)
                ans += key;
        }
        return ans;
    }
};