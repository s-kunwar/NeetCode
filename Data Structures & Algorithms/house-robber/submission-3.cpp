class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        if(size==0) return 0;
        if(size==1) return nums[0];
        if(size==2) return max(nums[0],nums[1]);
        if(size==3) return max((nums[0]+nums[2]),nums[1] );

        vector<int> sub2(nums.begin() + 2, nums.end());
        vector<int> sub3(nums.begin() + 3, nums.end());
        
        return max((nums[0] + rob(sub2)), (nums[1] + rob(sub3)));
    }  
};
