class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int p=0;
        for(int j:nums){p=p^j;}
        return p;
    }
};
