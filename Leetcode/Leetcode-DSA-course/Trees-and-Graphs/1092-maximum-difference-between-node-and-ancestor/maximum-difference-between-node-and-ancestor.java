/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    int ans = 0;

    public int maxAncestorDiff(TreeNode root) {
        dfs(root, root.val, root.val);
        return ans;
    }

    void dfs(TreeNode node, int currMax, int currMin) {
        if (node == null)
            return;
        currMax = Math.max(currMax, node.val);
        currMin = Math.min(currMin, node.val);
        if (node.left == null && node.right == null) {
            ans = Math.max(currMax - currMin, ans);
            return;
        }
        dfs(node.left, currMax, currMin);
        dfs(node.right, currMax, currMin);
    }
}