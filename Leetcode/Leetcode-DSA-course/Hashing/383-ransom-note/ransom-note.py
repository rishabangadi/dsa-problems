class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        freq1 = Counter(ransomNote)
        freq2 = Counter(magazine)
        for key in freq1:
            if freq1[key] > freq2[key]:
                return False
        return True