class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        freq = defaultdict(int)
        for i in arr:
            freq[i] += 1
        freqSet = set(freq.values())
        return len(freqSet) == len(freq)
