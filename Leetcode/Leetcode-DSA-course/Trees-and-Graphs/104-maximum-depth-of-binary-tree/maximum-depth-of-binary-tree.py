# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        stack = [(root, 1)]
        ans = 0
        while stack:
            node, depth = stack.pop()
            ans = max(ans, depth)
            if node.left != None:
                stack.append((node.left, depth + 1))
            if node.right != None:
                stack.append((node.right, depth + 1))
        return ans
