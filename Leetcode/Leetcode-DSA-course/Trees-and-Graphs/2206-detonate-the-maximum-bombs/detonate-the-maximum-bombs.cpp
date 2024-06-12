class Solution {
public:
    unordered_map<int, vector<int>> graph;
    int n;
    int maximumDetonation(vector<vector<int>>& bombs) {
        n = bombs.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = bombs[i][0], y1 = bombs[i][1];
                int x2 = bombs[j][0], y2 = bombs[j][1];
                double d = distance(x1, x2, y1, y2);
                if (d <= (double)bombs[i][2])
                    graph[i].push_back(j);
                if (d <= (double)bombs[j][2])
                    graph[j].push_back(i);
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }

    int dfs(int node) {
        vector<bool> seen(n, false);
        int ans = 0;

        stack<int> stack({node});
        seen[node] = true;
        while (!stack.empty()) {
            int curr = stack.top();
            stack.pop();
            ans++;
            for (int neighbour : graph[curr]) {
                if (!seen[neighbour]) {
                    seen[neighbour] = true;
                    stack.push(neighbour);
                }
            }
        }
        return ans;
    }

    double distance(double x1, double x2, double y1, double y2) {
        return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
};