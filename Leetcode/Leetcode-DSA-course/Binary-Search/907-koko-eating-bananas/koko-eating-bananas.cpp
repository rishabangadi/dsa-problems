class Solution {
public:
    int limit;
    int minEatingSpeed(vector<int>& piles, int h) {
        limit = h;
        int left = 1, right = 0;
        for (int bananas : piles)
            right = max(right, bananas);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, piles))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

    bool check(int mid, vector<int>& piles) {
        long hours = 0;
        for (double bananas : piles) {
            hours += ceil(bananas / mid);
        }
        return hours <= limit;
    }
};