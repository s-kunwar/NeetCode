class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0 || n == 0) return;
        
        // Make sure m <= n to avoid index out of range errors.
        if (m >= n) swap(nums1, nums2);
        
        int p = 0;
        int q = 0;
        
        // Merge smaller elements first.
        while (p < m && q < n) {
            if (nums1[p] < nums2[q]) {
                nums1[p + i] = nums1[p];
                p++;
            }
            else {
                nums1[p + i] = nums2[q];
                q++;
            }
            i++;
        }
        
        // Copy remaining elements from nums2.
        while (q < n) {
            nums1[p + i] = nums2[q];
            p++;
            q++;
        }
    }
};
