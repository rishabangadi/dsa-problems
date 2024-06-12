class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int cost = 0;
        priority_queue<int, vector<int>, greater<int>> heap(sticks.begin(),
                                                            sticks.end());
        while (heap.size() > 1) {
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            cost += x + y;
            heap.push(x + y);
        }
        return cost;
    }
};