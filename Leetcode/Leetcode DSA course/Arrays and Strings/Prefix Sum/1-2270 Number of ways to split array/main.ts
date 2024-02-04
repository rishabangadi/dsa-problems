function waysToSplitArray(nums: number[]): number {
    let n = nums.length;

    let prefix: number[] = [nums[0]];
    for (let i = 1; i < n; i++)
        prefix.push(prefix[prefix.length - 1] + nums[i]);

    let ans = 0;
    for (let i = 0; i < n - 1; i++) {
        let leftSection = prefix[i];
        let rightSection = prefix[n - 1] - prefix[i];
        if (leftSection >= rightSection) ans++;
    }

    return ans;
};