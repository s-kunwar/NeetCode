class Solution {
public:
    vector<int> countBits(int n) {
    vector<int>ans(n+1);
    ans[0]=0;
    for (int i=1;i<=n;i++){
        // Right shift by 1 is the same as i/2
        // If i is odd, we add 1 for the last bit
        ans[i]=(ans[i>>1])+(i&1);
    }   
    return ans;
    }
};
