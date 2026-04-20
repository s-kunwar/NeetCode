#include <algorithm>
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        //first fixed value
        for(int i=0;i<=(n-4);i++){
            //second fixed value
            if (nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<=(n-3);j++){
                int l=j+1,r=n-1;
                if(nums[j]==nums[j-1]) continue;
                while(l<r){
                    int sum=nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l<r && nums[l]==nums[l+1]) l++;
                        while(l<r && nums[r]==nums[r-1]) r--;
                        l++;
                        r--;
                    }
                    else if(sum<target) l++;
                    else r--;
                }
            }
        }
        return ans;
    }
};