class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>trustscore(n,0);
        for(int idx=0;idx<trust.size();idx++){
            trustscore[trust[idx][0]-1]=-1;
            trustscore[trust[idx][1]-1]+=1;
        }
        for(int idx=0;idx<n;idx++){
            if(trustscore[idx]==n-1) return idx+1;
        }
        return -1;
    }

};