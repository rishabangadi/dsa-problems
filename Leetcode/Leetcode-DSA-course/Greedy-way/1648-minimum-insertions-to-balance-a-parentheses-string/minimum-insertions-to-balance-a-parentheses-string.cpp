class Solution {
public:
    int minInsertions(string s) {
        int count = 0;
        stack<char> stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                stack.push(s[i]);
            else {
                if(stack.empty()){
                    if(i<s.size()-1 && s[i+1]==')')
                     {
                        count++;
                        i++;
                     }   
                    else count+=2;
                }else if(i<s.size()-1 && s[i+1]==')'){
                    stack.pop();i++;
                }
                else{
                    stack.pop();count++;
                }
            }
        }
        if (!stack.empty())
            count += stack.size() * 2;
        return count;
    }
};