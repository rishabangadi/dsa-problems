function subarraySum(nums: number[], k: number): number {
    const counts = new Map();
    counts.set(0, 1);
    let ans = 0, curr = 0;
    for (let num of nums) {
        curr += num;
        ans += counts.get(curr - k) || 0;
        counts.set(curr, (counts.get(curr) || 0) + 1)
    }
    return ans;
};