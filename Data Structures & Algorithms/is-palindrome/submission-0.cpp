class Solution {
public:
    bool isvalid(char c){
        if ((c>96 && c<123)||(c>64 && c<91)||(c>47 && c<56)) return true;
        return false;
    }
    int ind(char c){
        if(c>96 && c<123) return c-96;
        else return c-64;
    }
    bool isPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<=r){
            if(isvalid(s[l])==false) {l++;continue;}
            if(isvalid(s[r])==false) {r--;continue;}
            if(s[l]!=s[r] && ind(s[l])!=ind(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
