class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> queue;
        for (int i = 0; i < nums.size(); i++) {
            while (!queue.empty() && nums[i] >= nums[queue.back()])
                queue.pop_back();
            queue.push_back(i);
            if (queue.front() <= i - k)
                queue.pop_front();
            if (i >= k - 1)
                ans.push_back(nums[queue.front()]);
        }
        return ans;
    }
};