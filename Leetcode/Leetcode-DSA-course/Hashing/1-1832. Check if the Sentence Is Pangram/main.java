class Solution {
    public boolean checkIfPangram(String sentence) {
        Set<Character> hashSet = new HashSet<>();
        for(char ch:sentence.toCharArray())
            hashSet.add(ch);
        return hashSet.size() == 26;
    }
}