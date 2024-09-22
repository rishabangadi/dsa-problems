class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        max_so_far = nums[0]
        min_so_far = nums[0]
        result = nums[0]

        for i in range(1, len(nums)):
            curr = nums[i]
            temp_max = max(curr, max(curr * max_so_far, curr * min_so_far))
            min_so_far = min(curr, min(curr * max_so_far, curr * min_so_far))

            max_so_far = temp_max
            result = max(result, max_so_far)

        return result
