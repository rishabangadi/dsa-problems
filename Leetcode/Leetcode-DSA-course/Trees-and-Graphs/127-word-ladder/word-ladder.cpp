class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<pair<string, int>> queue({pair(beginWord, 1)});
        unordered_set<string> seen({beginWord});

        while (!queue.empty()) {
            auto [node, val] = queue.front();
            queue.pop();
            if (node == endWord)
                return val;

            for (string& neighbour : neighbours(node, dict)) {
                if (seen.find(neighbour) == seen.end()) {
                    seen.insert(neighbour);
                    queue.push(pair(neighbour, val + 1));
                }
            }
        }
        return 0;
    }

    vector<string> neighbours(string node, unordered_set<string>& dict) {
        vector<string> ans;
        for (int i = 0; i < node.size(); i++) {
            for (int j = 0; j < 26; j++) {
                char ch = 'a' + j;
                if (node[i] != ch) {
                    string neighbour = node;
                    neighbour[i] = ch;
                    if (dict.find(neighbour) != dict.end())
                        ans.push_back(neighbour);
                }
            }
        }
        return ans;
    }
};