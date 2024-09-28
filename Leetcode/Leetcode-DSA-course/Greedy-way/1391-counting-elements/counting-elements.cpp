class Solution {
public:
    int countElements(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int count = 0, runLength = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] != arr[i]) {
                if (arr[i - 1] + 1 == arr[i])
                    count += runLength;
                runLength = 0;
            }
            runLength++;
        }
        return count;
    }
};