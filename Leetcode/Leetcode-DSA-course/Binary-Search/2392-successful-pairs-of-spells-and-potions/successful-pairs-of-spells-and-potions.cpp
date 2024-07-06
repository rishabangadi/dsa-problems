class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {

        sort(potions.begin(), potions.end());
        vector<int> ans;
        int m = potions.size();
        for (double spell : spells) {
            int i = binarySearch(potions, success / spell);
            ans.push_back(m - i);
        }
        return ans;
    }

    int binarySearch(vector<int>& arr, double target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
     
};