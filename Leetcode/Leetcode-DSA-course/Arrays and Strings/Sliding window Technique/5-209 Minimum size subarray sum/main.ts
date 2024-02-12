function minSubArrayLen(target: number, nums: number[]): number {
  let left = 0,
    ans = Number.POSITIVE_INFINITY,
    sum = 0;
  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
    while (sum >= target) {
      ans = Math.min(ans, i - left + 1);
      sum -= nums[left++];
    }
  }
  return ans != Number.POSITIVE_INFINITY ? ans : 0;
}
