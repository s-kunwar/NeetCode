class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int idx=-1;
        for(int i=0;i<nums.size();i++){
            if(idx==-1 && nums[i]>0) idx=1;
            if(idx>=1){
                if(idx!=nums[i]) return idx;
                else{
                    if((i+1)<nums.size()) {
                        if(nums[i]==nums[i+1]){continue;}
                        else{idx++;continue;}
                    }
                    else{idx++;continue;}
                }
            }
        }
        if(idx==-1) return 1;
        else return idx;
    }
};