class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int low=arr[0],n=arr.size(),max_profit=0;
        if (n==1) return 0;
        for(int i=1;i<n;i++){
            if((arr[i]-low) > max_profit) max_profit=arr[i]-low;
            if(arr[i]<low) low=arr[i];
        }
        return max_profit;
    }
};
