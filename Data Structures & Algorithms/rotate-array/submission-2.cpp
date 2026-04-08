class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if (k>n){
            k=k%n;
        }
        int i=0,j=n-k,temp;

        while(j<n){
            temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j++;
        }
    }
};