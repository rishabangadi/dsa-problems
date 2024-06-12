class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(piles.begin(), piles.end());

        for (int i = 0; i < k; i++) {
            int x = heap.top();
            heap.pop();
            heap.push(x - x / 2);
        }

        int ans = 0;
        while (!heap.empty()) {
            ans += heap.top();
            heap.pop();
        }

        return ans;
    }
};