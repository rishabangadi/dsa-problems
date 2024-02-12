class Solution {
public:
    string reverse(string& word, int end) {
        int i = 0;
        while (i < end) {
            swap(word[i++], word[end--]);
        }

        return word;
    }

    string reversePrefix(string word, char ch) {
        for (int i = 0;i < word.length();i++) {
            if (word[i] == ch) {
                string ans = reverse(word, i);
                return ans;
            }
        }
        return word;
    }
};