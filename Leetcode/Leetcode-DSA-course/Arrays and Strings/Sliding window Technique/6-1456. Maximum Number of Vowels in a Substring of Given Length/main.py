class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = {"a", "i", "o", "e", "u"}
        count = 0
        for i in range(k):
            count += int(s[i] in vowels)
        ans = count
        for i in range(k, len(s)):
            count += int(s[i] in vowels) - int(s[i - k] in vowels)
            ans = max(ans, count)

        return ans
