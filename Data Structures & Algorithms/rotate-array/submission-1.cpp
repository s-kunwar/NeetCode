class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if (k>n){
            k=k%n;
        }
        vector<int>arr(n);
        int m=0;
        for (int i=n-k;i<n;i++){
            arr[m]=nums[i];
            m++;
        }
        for(int i=0;i<(n-k);i++){
            arr[m]=nums[i];
            m++;
        }
        nums=arr;
    }
};