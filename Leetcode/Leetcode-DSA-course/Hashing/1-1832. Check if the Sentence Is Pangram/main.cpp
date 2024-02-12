class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> hashSet(sentence.begin(), sentence.end());
        return hashSet.size() == 26;
    }
};