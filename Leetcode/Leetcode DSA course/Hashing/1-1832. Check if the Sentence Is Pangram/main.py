class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        hashSet = set(sentence)
        return len(hashSet) == 26