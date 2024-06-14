class Solution {
public:
    int maximum69Number(int num) {
        int copy = num;
        vector<int> digits;
        while (num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        int j = digits.size() - 1;
        while (j >= 0 && digits[j] != 6) {
            j--;
        }
        if (j < 0)
            return copy;
        digits[j] = 9;
        int number = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            number += digits[i] * pow(10, i);
        }
        return number;
    }
};