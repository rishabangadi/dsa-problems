class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        def getDigitSum(n):
            sum = 0
            while n:
                sum += n % 10
                n //= 10
            return sum

        dic = defaultdict(int)
        ans = -1
        for num in nums:
            digitSum = getDigitSum(num)
            if digitSum in dic:
                ans = max(ans, dic[digitSum] + num)
            dic[digitSum] = max(dic[digitSum], num)
        return ans
