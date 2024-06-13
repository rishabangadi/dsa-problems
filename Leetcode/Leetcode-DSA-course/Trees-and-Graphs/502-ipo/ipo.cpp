class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++)
            projects.push_back({capital[i], profits[i]});

        sort(projects.begin(), projects.end());
        int i = 0;
        priority_queue<int> heap;
        for (int j = 0; j < k; j++) {
            while (i < n && projects[i].first <= w) {
                heap.push(projects[i].second);
                i++;
            }
            if (heap.size() == 0)
                return w;
            w += heap.top();
            heap.pop();
        }
        return w;
    }
};