class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map;
        unordered_set<string> set;
        int start = 0;
        int end = 0;
        int i;
        for (i = 0; i < pattern.length() && end < s.length(); i++) {
            while (end < s.length() && s[end] != ' ') {
                end++;
            }
            string word = s.substr(start,end-start);
            start = end + 1;
            end++;

            if (map.find(pattern[i]) == map.end()) {
                if (set.find(word) != set.end())
                    return false;
                map[pattern[i]] = word;
                set.insert(word);
            } else {
                if (map[pattern[i]] != word)
                    return false;
            }
        }
        if(end < s.length()) return false;
        return i == pattern.length();
    }
};