class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> words;
        int left = 0;
        int n = s.length();
        int right = n-1;
        while(right>=left && s[right]==' ')
            right--;
        int count = 0;
        while(right>=left){
            if(s[right]!=' '){
                count++;
                right--;
            }
            else{
                break;
            }
        }
        return count;
    }
};