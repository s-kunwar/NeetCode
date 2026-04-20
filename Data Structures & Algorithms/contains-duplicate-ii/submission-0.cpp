#include <unordered_map>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>arr;
        int ind=0;
        for(int num:nums){
            if(arr.count(num)){
                if( abs(arr[num]-ind)<=k ) return true;
            }
            else arr[num]=ind;
            ind++;
        }
        return false;
    }
};