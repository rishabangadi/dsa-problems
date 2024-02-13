function maxFrequencyElements(nums: number[]): number {
        let freq = new Array(101).fill(0);
        let max_freq = 1;
        for (let num of nums) {
            freq[num]++;
            max_freq = Math.max(max_freq, freq[num]);
        }
        let sum = 0;
        for (let i = 1; i < 101; i++) {
            if (freq[i] == max_freq)
                sum += freq[i];
        }
        return sum;
};