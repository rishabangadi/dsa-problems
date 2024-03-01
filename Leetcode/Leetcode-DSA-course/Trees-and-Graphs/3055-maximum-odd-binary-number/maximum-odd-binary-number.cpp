class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int countOf1 = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1')
                countOf1++;
        for (int i = 0; i < countOf1 - 1; i++) {
            s[i] = '1';
        }
        for (int i = countOf1 - 1; i < s.size() - 1; i++)
            s[i] = '0';
        s.back() = '1';
        return s;
    }
};