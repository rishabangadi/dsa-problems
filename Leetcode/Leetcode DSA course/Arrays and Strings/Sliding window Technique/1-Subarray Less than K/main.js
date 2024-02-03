// https://leetcode.com/problems/subarray-product-less-than-k/description/

// Given an array of positive integers nums and an integer k, return the number of subarrays where the product of all the elements in the subarray is strictly less than k.
// For example, given the input nums = [10, 5, 2, 6], k = 100, the answer is 8. The subarrays with products less than k are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]

function getCount(nums, k) {
  if (k <= 1) return 0;
  let curr = 1,
    left = 0,
    ans = 0;
  for (let right = 0; right < nums.length; right++) {
    curr *= nums[right];
    while (curr >= k) {
      curr /= nums[left++];
    }
    ans += right - left + 1;
    // console.log(curr, left, right);
  }

  return ans;
}

let nums = [10, 5, 2, 6];
let k = 100;
console.log(getCount(nums, k));
