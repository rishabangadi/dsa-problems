class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        averages = [-1] * len(nums)
        if k == 0:
            return nums
        windowSize = 2 * k + 1
        n = len(nums)
        if windowSize > n:
            return averages
        
        windowSum = sum(nums[:windowSize])
        averages[k] = windowSum // windowSize

        for i in range(windowSize,n):
            windowSum += nums[i] - nums[i-windowSize]
            averages[i-k] = windowSum // windowSize

        return averages
