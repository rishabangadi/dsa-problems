/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function maxAncestorDiff(root: TreeNode | null): number {
    let ans = 0;
    function dfs(node, currMax, currMin) {
        if (!node) return;
        currMax = Math.max(currMax, node.val);
        currMin = Math.min(currMin, node.val);
        if (node.left == null && node.right == null) {

            ans = Math.max(ans, currMax - currMin)
            return
        }
        dfs(node.left, currMax, currMin)
        dfs(node.right, currMax, currMin)
    }
    dfs(root, root.val, root.val)
    return ans
};