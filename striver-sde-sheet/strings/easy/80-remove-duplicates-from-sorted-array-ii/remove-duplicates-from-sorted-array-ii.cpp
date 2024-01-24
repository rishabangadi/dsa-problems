class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int freq=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] != nums[k])
            {
                nums[++k] = nums[i];
                freq=1;
            }
            else{
                if(freq<2)
                {
                    nums[++k] = nums[i];
                    freq++;
                }
            }
        }
        return ++k;
    }
};