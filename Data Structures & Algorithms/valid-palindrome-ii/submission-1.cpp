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
    bool validPalindrome(string s){
        int l=0;
        int r=s.size()-1;
        if(vPalindrome(s,l,r,true)) return true;
        return false;
    }
    bool vPalindrome(string &s,int l,int r, bool change) {
        while(l<=r){
            if(isvalid(s[l])==false) {l++;continue;}
            if(isvalid(s[r])==false) {r--;continue;}
            if(s[l]!=s[r] && ind(s[l])!=ind(s[r])){
                if (change==true){
                    if(vPalindrome(s,l+1,r,false)) return true;
                    if(vPalindrome(s,l,r-1,false)) return true;
                    return false;
                }
                else{
                    return false;
                }
            }
            l++;
            r--;
        }
        return true;
    }
};