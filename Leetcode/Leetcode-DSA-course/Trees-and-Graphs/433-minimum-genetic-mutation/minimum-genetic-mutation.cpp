class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> geneBank(bank.begin(), bank.end());
        unordered_set<string> seen({startGene});
        queue<pair<string, int>> queue({pair(startGene, 0)});
        while (!queue.empty()) {
            auto [node, val] = queue.front();
            queue.pop();
            if (node == endGene)
                return val;
            for (string& n : neighbours(node, geneBank)) {
                if (seen.find(n) == seen.end()) {
                    seen.insert(n);
                    queue.push(pair(n, val + 1));
                }
            }
        }
        return -1;
    }

    vector<string> neighbours(string node, unordered_set<string>& bank) {
        vector<string> ans;
        for (int i = 0; i < 8; i++) {
            for (char c : {'A', 'C', 'G', 'T'}) {
                if (node[i] != c) {
                    string neighbour = node;
                    neighbour[i] = c;
                    if (bank.find(neighbour) != bank.end())
                        ans.push_back(neighbour);
                }
            }
        }
        return ans;
    }
};