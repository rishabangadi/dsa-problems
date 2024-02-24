/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        stack<pair<TreeNode*, int>> stack;
        stack.push(pair(root, INT_MIN));
        int ans = 0;
        while (!stack.empty()) {
            auto [node, maxSoFar] = stack.top();
            stack.pop();
            if (node->val >= maxSoFar)
                ans++;
            if (node->left != nullptr)
                stack.push(pair(node->left, max(maxSoFar, node->val)));
            if (node->right != nullptr)
                stack.push(pair(node->right, max(maxSoFar, node->val)));
        }
        return ans;
    }
};