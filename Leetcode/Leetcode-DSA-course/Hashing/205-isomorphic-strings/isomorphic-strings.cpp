class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> map;
        unordered_set<char> set;
        for (int i = 0; i < s.length(); i++) {
            if (map.find(s[i]) == map.end()) {
                if (set.find(t[i]) != set.end())
                    return false;
                map[s[i]] = t[i];
                set.insert(t[i]);
            } else {
                if (map[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};