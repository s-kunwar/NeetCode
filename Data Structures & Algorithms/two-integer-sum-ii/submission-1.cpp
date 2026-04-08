class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i=0;i<(numbers.size()-1);i++){
            int b=target-numbers[i];
            int l=0,r=numbers.size()-1;
            vector<int>ans(2);
            while(l<=r){
                int mid=(l+r+1)/2;
                if(numbers[mid]==b){
                    ans[0]=numbers[i];
                    ans[1]=b;
                    return ans;
                }
                else if(numbers[mid]>b){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }   
            }
        }
    }
};
