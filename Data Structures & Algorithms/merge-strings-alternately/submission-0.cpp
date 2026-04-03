class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int a=word1.size();
        int b=word2.size();
        string s="";
        s.reserve(a+b);    
        int i=0;

        while(word1[i] && word2[i]){
            s+=word1[i];
            s+=word2[i];
            i++;
        }
        if(a>b){
            while(word1[i]){
                s+=word1[i];
                i++;
            }
        }
        if(b>a){
            while(word2[i]){
                s+=word2[i];
                i++;
            }
        }
        return s;
    }
};