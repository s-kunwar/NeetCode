class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=0,r=0,p=m;
        if (n==0)return nums1;
        while(l<m || r<n){
            if(p>=nums1.size()) p=0;

            if((nums1[l]<nums2[r] && l<m && r<n) || r>=n){
                nums1[p]=nums1[l];
                l++;
                p++;
            }
            else{
                nums1[p]=nums2[r];
                r++;
                p++;
            }
        }

        l=0,r=nums1.size()-1;
        while(l<r){
            int temp=nums1[l];
            nums1[l]=nums1[r];
            nums1[r]=temp;
            l++;
            r--;
        }
        l=0,r=n-1;
        while(l<r){
            int temp=nums1[l];
            nums1[l]=nums1[r];
            nums1[r]=temp;
            l++;
            r--;
        }
        l=n,r=nums1.size()-1;
        while(l<r){
            int temp=nums1[l];
            nums1[l]=nums1[r];
            nums1[r]=temp;
            l++;
            r--;
        }
        
        
    }
};