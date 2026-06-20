class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int wxor=nums.size();
        for(int i=0;i<nums.size();i++) wxor=wxor^nums[i]^i;
        return wxor;
    }
};
