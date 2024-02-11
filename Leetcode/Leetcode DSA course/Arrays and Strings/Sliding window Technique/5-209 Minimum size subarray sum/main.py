class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left=0
        ans=float('inf')
        sum=0
        for i in range(len(nums)):
            sum+=nums[i]
            while sum>=target:
                ans = min(ans,i-left+1)
                sum-=nums[left]
                left+=1

        return ans if ans != float('inf') else 0
            