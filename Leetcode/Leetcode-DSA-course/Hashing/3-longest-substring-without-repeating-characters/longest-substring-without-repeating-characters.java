class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> counts = new HashMap<>();
        int left = 0, ans = 0;
        for (int right = 0; right < s.length(); right++) {
            char r = s.charAt(right);
            counts.put(r, counts.getOrDefault(r, 0) + 1);
            while (counts.get(r) > 1) {
                char l = s.charAt(left);
                counts.put(l, counts.get(l) - 1);
                left++;
            }
            ans = Math.max(ans, right - left + 1);
        }
        return ans;
    }
}