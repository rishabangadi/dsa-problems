# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        if not root:
            return ans
        queue = deque([root])
        level = 0
        while queue:
            length = len(queue)
            currList = []
            for _ in range(length):
                node = queue.popleft()
                currList.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            if level & 1:
                ans.append(currList[::-1])
            else:
                ans.append(currList)
            level += 1
        return ans
