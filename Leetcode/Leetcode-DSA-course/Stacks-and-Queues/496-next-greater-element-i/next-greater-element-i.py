class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = []
        map = {}
        for i in range(len(nums2)):
            while stack and nums2[i] > stack[-1]:
                map[stack.pop()] = nums2[i]
            stack.append(nums2[i])
        while stack:
            map[stack.pop()] = -1

        ans = []
        for num in nums1:
            ans.append(map[num])
        return ans
