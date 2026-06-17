class Solution {
public:
    vector<int> countBits(int n) {
    vector<int>ans(n+1);
    for (int i=0;i<=n;i++){
        int cnt=0,j=i;
        while(j){
            j=j&(j-1);
            cnt++;
        }
        ans[i]=cnt;
    }   
    return ans;
    }
};
