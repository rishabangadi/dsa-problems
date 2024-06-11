/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parents;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, nullptr);
        unordered_set<TreeNode*> seen;
        seen.insert(target);
        queue<TreeNode*> queue;
        queue.push(target);
        int distance = 0;
        while (!queue.empty() && distance < k) {
            int len = queue.size();
            for (int i = 0; i < len; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                for (TreeNode* n : {node->left, node->right, parents[node]}) {
                    if (n != nullptr && seen.find(n) == seen.end()) {
                        queue.push(n);
                        seen.insert(n);
                    }
                }
            }
            distance++;
        }
        vector<int> ans;
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            ans.push_back(node->val);
        }
        return ans;
    }

    void dfs(TreeNode* root, TreeNode* parent) {
        if (!root)
            return;
        parents[root] = parent;
        dfs(root->left, root);
        dfs(root->right, root);
    }
};