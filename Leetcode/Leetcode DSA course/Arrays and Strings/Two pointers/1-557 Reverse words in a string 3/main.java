class Solution {
    public String reverseWords(String s) {
        int lastSpaceIndex = -1;
        char[] chArray = s.toCharArray();
        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || chArray[i] == ' ') {
                int startIndex = lastSpaceIndex + 1;
                int endIndex = i - 1;
                while (startIndex < endIndex) {
                    char ch = chArray[startIndex];
                    chArray[startIndex] = chArray[endIndex];
                    chArray[endIndex] = ch;
                    startIndex++;
                    endIndex--;
                }
                lastSpaceIndex = i;
            }
        }
        return new String(chArray);
    }

}