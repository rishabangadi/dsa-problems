// If the elements are sorted in monotonically increasing (or decreasing) order,
// the majority element can be found at index n/2 (and n/2 -1 if n is even )

int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}