class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r+1)/2;
            int sum=numbers[l]+numbers[r];
            if(sum==target) return {l+1,r+1};
            else if(sum>target) r=mid-1;
            else l=mid+1;
        }
        return {r+1,l+1};
    }
};
