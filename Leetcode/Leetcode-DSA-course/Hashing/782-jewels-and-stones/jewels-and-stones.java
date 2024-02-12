class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        Set<Character> jewel_set = new HashSet<>();
        for (char ch : jewels.toCharArray())
            jewel_set.add(ch);

        int ans = 0;
        for (char ch : stones.toCharArray()) {
            if (jewel_set.contains(ch))
                ans++;
        }
        return ans;
    }
}