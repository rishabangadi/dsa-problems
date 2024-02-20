class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack;
        vector<int> answer(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {
            while (!stack.empty() &&
                   temperatures[stack.top()] < temperatures[i]) {
                int j = stack.top();
                answer[j] = i - j;
                stack.pop();
            }
            stack.push(i);
        }
        return answer;
    }
};