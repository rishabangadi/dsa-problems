class Solution {
    public int[] getAverages(int[] nums, int k) {
        if (k == 0)
            return nums;
        int n = nums.length;
        int windowSize = 2*k +1;
        int avgs[] = new int[n];
        Arrays.fill(avgs,-1);

        if(windowSize > n) return avgs;
        long windowSum = 0;
        for(int i=0;i<windowSize;i++)
            windowSum += nums[i];
        
        avgs[k] = (int)(windowSum/windowSize);

        for(int i=windowSize;i<n;i++){
            windowSum += nums[i] - nums[i-windowSize];
            avgs[i-k] = (int)(windowSum/windowSize);
        }

        return avgs;
    }
}