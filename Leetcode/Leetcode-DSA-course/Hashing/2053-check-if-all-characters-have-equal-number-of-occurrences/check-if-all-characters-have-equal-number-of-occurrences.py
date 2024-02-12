class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        counts = defaultdict(int)
        for ch in s:
            counts[ch] += 1

        frequencies = counts.values()
        return len(set(frequencies)) == 1
