function getAverages(nums: number[], k: number): number[] {
  if (k == 0) return nums;
  const n = nums.length;
  const windowSize = 2 * k + 1;
  const averages: number[] = new Array(n).fill(-1);

  if (windowSize > n) return averages;

  let windowSum = 0;
  for (let i = 0; i < windowSize; i++) windowSum += nums[i];

  averages[k] = Math.floor(windowSum / windowSize);

  for (let i = windowSize; i < n; i++) {
    windowSum += nums[i] - nums[i - windowSize];
    averages[i - k] = Math.floor(windowSum / windowSize);
  }

  return averages;
}
