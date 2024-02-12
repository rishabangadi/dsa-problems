class Solution {
    public boolean areOccurrencesEqual(String s) {
        Map<Character, Integer> counts = new HashMap<>();
        for (char ch : s.toCharArray())
            counts.put(ch, counts.getOrDefault(ch, 0) + 1);
        Set<Integer> frequencies = new HashSet<>(counts.values());
        return frequencies.size() == 1;
    }
}