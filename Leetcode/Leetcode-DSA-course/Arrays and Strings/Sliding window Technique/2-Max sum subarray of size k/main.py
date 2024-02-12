
from typing import List
class Solution:
    def getMaxSum(self, nums:List[int], k:int) -> int:
        curr=0
        for i in range(k):
            curr+=nums[i]
        ans=curr
        for i in range(k,len(nums)):
            curr+=nums[i]-nums[i-k]
            ans = max(ans, curr)
        return ans

nums = [3,-1,4,12 ,-8,5,6]
k=4
solution = Solution()
print(solution.getMaxSum(nums,k))

