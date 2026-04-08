class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>hp(201,-404);
        int cnt=0;
        for(int i:nums){
            if(hp[i+100]==-404) {hp[i+100]=i;cnt++;}
        }
        int ind=0;
        for(int i:nums){
            if(hp[i+100]!=-404) {nums[ind++]=hp[i+100];hp[i+100]=-404;}
        }
        return cnt;
    }
};