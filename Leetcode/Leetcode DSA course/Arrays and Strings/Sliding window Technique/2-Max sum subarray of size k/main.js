function getMaxSum(nums, k) {
    var curr = 0;
    for (var i = 0; i < k; i++)
        curr += nums[i];
    var ans = curr;
    for (var i = k; i < nums.length; i++) {
        curr += nums[i] - nums[i - k];
        ans = Math.max(ans, curr);
    }
    return ans;
}
var nums = [3, -1, 4, 12, -8, 5, 6];
var k = 4;
console.log(getMaxSum(nums, k));
