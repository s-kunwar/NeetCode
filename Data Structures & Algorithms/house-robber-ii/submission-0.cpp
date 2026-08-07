class Solution {
   private:
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; i++) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }

   public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        int robFirst = robLinear(nums, 0, nums.size() - 2);
        int robLast = robLinear(nums, 1, nums.size() - 1);

        return max(robFirst, robLast);
    }
};
