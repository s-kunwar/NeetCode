class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    vector<int>ht(126,-1);
    int left=0,max_len=0;
    for(int r=0;r<s.length();r++){
        if(ht[s[r]]>=left)left = ht[s[r]]+1;
        
        ht[s[r]]=r;
        max_len=max(max_len,r-left+1);
    }
    return max_len;
    }
};
