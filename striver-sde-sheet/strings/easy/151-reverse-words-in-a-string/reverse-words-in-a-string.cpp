class Solution {
public:
    string reverseWords(string s) {

        string curr_word = "", res = "";

        int start_pos=0;
        while(s[start_pos] == ' ')
        {
            start_pos++;
        }

        for (int i = s.size() - 1; i >= start_pos; i--) {
            if (i != 0 && s[i] == ' ' && s[i] == s[i - 1])
                continue;

            if (s[i] == ' ') {
                res = res + curr_word;
                curr_word = "";
            } else {
                curr_word = s[i] + curr_word;
                if(i!=start_pos && s[i-1] == ' ')
                    curr_word += " ";
            }
        }
    
        res = res + curr_word;
        return res;
    }
};