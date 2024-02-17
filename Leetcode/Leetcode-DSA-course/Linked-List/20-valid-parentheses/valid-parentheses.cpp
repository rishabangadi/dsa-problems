class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> matching{
            {'(' , ')'}, {'[' , ']'}, {'{' , '}'}};
        for (char c : s) {
            if (matching.find(c) != matching.end())
                stack.push(c);
            else {
                if (stack.empty())
                    return false;
                char previousOpening = stack.top();
                if (matching[previousOpening] != c)
                    return false;
                stack.pop();
            }
        }
        return stack.empty();
    }
};