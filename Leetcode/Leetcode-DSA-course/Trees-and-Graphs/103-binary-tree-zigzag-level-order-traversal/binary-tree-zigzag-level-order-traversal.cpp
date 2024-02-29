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
    static void reverseNums(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j)
            swap(nums[i++], nums[j--]);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return {};
        queue<TreeNode*> queue;
        queue.push(root);
        int level = 0;
        while (!queue.empty()) {
            int length = queue.size();
            vector<int> currLevel;
            for (int i = 0; i < length; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                currLevel.push_back(node->val);
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            if (level & 1) {
                reverseNums(currLevel);
            }
            ans.push_back(currLevel);
            level++;
        }
        return ans;
    }
};