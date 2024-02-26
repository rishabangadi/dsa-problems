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

class Pair {
    TreeNode p, q;

    Pair(TreeNode p, TreeNode q) {
        this.p = p;
        this.q = q;
    }
}

class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        Stack<Pair> stack = new Stack<>();
        stack.push(new Pair(p, q));
        while (!stack.isEmpty()) {
            Pair pair = stack.pop();
            TreeNode p1 = pair.p;
            TreeNode q1 = pair.q;
            if (p1 == null && q1 == null)
                continue;
            if (p1 == null || q1 == null)
                return false;

            if (p1.val != q1.val)
                return false;

            stack.push(new Pair(p1.left, q1.left));
            stack.push(new Pair(p1.right, q1.right));
        }
        return true;
    }
}