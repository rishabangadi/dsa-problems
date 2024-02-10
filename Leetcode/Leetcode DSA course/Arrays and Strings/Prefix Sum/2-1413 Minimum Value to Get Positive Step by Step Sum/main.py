from typing import List

class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        minVal = 0
        total = 0
        for num in nums:
            total += num
            minVal = min(minVal, total)

        return -minVal + 1
