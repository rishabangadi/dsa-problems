class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> freq1 = new HashMap<>();
        for (char ch : ransomNote.toCharArray()) {
            freq1.put(ch, freq1.getOrDefault(ch, 0) + 1);
        }
        Map<Character, Integer> freq2 = new HashMap<>();
        for (char ch : magazine.toCharArray()) {
            freq2.put(ch, freq2.getOrDefault(ch, 0) + 1);
        }
        for (char ch : freq1.keySet()) {
            if (freq1.get(ch) > freq2.getOrDefault(ch, 0))
                return false;
        }
        return true;
    }
}