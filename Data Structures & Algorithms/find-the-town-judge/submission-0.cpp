class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int>judge(n,1);
        for(int i=0;i<trust.size();i++){
            judge[trust[i][0]-1]=0;
        }
        for(int i=0;i<n;i++){
            if(judge[i]==1) return i+1;
        }
        return -1;
    }
};