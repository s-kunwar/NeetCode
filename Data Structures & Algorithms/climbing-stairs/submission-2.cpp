class Solution {
public:
    int climbStairs(int n) {
        int l=1,r=1;
        if(n<2) return 1;
        else{
            int res=0;
            for(int i=2;i<=n;i++){
                res=l+r;
                l=r;
                r=res;
            }
            return res;
        }
    }
};
