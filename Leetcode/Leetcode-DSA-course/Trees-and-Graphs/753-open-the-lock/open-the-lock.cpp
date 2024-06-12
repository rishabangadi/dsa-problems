class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (find(deadends.begin(), deadends.end(), "0000") != deadends.end())
            return -1;

        queue<pair<string, int>> queue;
        queue.push(pair("0000", 0));
        unordered_set<string> seen(deadends.begin(), deadends.end());
        seen.insert("0000");

        while (!queue.empty()) {
            auto [node, steps] = queue.front();
            queue.pop();
            if (node == target)
                return steps;

            for (string& n : neighbours(node)) {
                if (seen.find(n) == seen.end()) {
                    seen.insert(n);
                    queue.push(pair(n, steps + 1));
                }
            }
        }
        return -1;
    }

    vector<string> neighbours(string node) {
        vector<string> ans;
        for (int i = 0; i < 4; i++) {
            int num = node[i];
            for (int change : {-1, 1}) {
                int x = (num - '0' + change + 10) % 10 + '0';
                string neighbour = node;
                neighbour[i] = x;
                ans.push_back(neighbour);
            }
        }
        return ans;
    }
};