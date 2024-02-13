class Solution {
    public int maxFrequencyElements(int[] nums) {
        int freq[] = new int[101];
        Arrays.fill(freq,0);
        int max_freq = 1;
        for (int num : nums) {
            freq[num]++;
            max_freq = Math.max(max_freq, freq[num]);
        }
        int sum = 0;
        for (int i = 1; i < 101; i++) {
            if (freq[i] == max_freq)
                sum += freq[i];
        }
        return sum;
    }
}