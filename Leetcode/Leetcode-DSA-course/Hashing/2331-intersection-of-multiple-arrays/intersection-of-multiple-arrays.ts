function intersection(nums: number[][]): number[] {
    const counts = new Map();
    for (let arr of nums) {
        for (let x of arr)
            counts.set(x, (counts.get(x) || 0) + 1);
    }
    let n = nums.length;
    let ans = [];
    for (const [key, value] of counts) {
        if (value == n)
            ans.push(key);
    }
    ans.sort((a, b) => a - b);
    return ans;
};