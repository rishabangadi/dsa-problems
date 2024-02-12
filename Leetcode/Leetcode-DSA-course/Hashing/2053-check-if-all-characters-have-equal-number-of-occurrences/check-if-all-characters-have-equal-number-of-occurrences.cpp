class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> counts;
        for (auto& ch : s)
            counts[ch]++;

        unordered_set<int> hashSet;
        for (auto [key, value] : counts) {
            hashSet.insert(value);
        }
        return hashSet.size() == 1;
    }
};