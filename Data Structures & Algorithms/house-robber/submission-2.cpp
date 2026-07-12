class Solution {
public:
    int money(vector<int>& nums,int endhouse,int wealth){
        int lasthouse=nums.size()-1;

        if(lasthouse<endhouse+2) return wealth;
        else if(lasthouse==endhouse+2) return wealth+nums[endhouse+2];
        
        return max( money(nums,endhouse+3,wealth+nums[endhouse+3]), money(nums,endhouse+2,wealth+nums[endhouse+2]) );
    }

    int rob(vector<int>& nums) {
        int s=nums.size();
        if(s==1) return nums[0];
        return max( money(nums,0,nums[0]) , money(nums,1,nums[1]) );
    }  
};
