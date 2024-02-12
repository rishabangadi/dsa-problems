class Solution {
public:
    int getDigitSum(int n) {
        int digitSum = 0;
        while (n) {
            digitSum += n % 10;
            n /= 10;
        }
        return digitSum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> dic;
        int ans = -1;
        for (int num : nums) {
            int digitSum = getDigitSum(num);
            if (dic.find(digitSum) != dic.end()) {
                ans = max(ans, dic[digitSum] + num);
            }
            dic[digitSum] = max(dic[digitSum], num);
        }
        return ans;
    }
};