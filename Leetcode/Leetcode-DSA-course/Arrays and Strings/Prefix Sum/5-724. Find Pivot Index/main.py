class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        Sum=0
        leftsum=0
        for num in nums:
            Sum+=num
        
        for i in range(len(nums)):
            if leftsum == Sum - leftsum - nums[i]:
                return i
            leftsum += nums[i]
        return -1 