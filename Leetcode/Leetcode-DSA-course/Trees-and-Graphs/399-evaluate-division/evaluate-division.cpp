class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            string num = equations[i][0], den = equations[i][1];
            graph[num][den] = values[i];
            graph[den][num] = 1 / values[i];
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(dfs(queries[i][0], queries[i][1]));
        }
        return ans;
    }

    double dfs(string& start, string& end) {
        if (graph.find(start) == graph.end())
            return -1;

        stack<pair<string, double>> stack({pair(start, 1)});
        unordered_set<string> seen({start});

        while (!stack.empty()) {
            auto [node, ratio] = stack.top();
            stack.pop();
            if (node == end)
                return ratio;
            for (auto [neighbour, val] : graph[node]) {
                if (seen.find(neighbour) == seen.end()) {
                    seen.insert(neighbour);
                    stack.push(pair(neighbour, val * ratio));
                }
            }
        }
        return -1;
    }
};