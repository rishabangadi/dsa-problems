from typing import List

class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        n = len(nums)
        prefix = [nums[0]]
        for i in range(1, n):
            prefix.append(prefix[len(prefix) - 1] + nums[i])

        ans = 0
        for i in range(n - 1):
            leftSection = prefix[i]
            rightSection = prefix[n - 1] - prefix[i]
            if leftSection >= rightSection:
                ans += 1

        return ans
