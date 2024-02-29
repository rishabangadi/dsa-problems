# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        ans = 0

        def dfs(node, currMax, currMin):
            nonlocal ans
            if not node:
                return
            currMax = max(currMax, node.val)
            currMin = min(currMin, node.val)
            if node.left == None and node.right == None:
                ans = max(ans, currMax - currMin)
                return
            dfs(node.left, currMax, currMin)
            dfs(node.right, currMax, currMin)

        dfs(root, root.val, root.val)
        return ans
