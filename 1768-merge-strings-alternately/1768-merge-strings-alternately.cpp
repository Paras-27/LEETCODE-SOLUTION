class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int n=word1.size();
        int m=word2.size();
        string p="";
        while(i<n && i<m){
            p+=word1[i];
            p+=word2[i];
            i++;
        }
        while(i<n){
            p+=word1[i];
            i++;
        }

        while(i<m){
            p+=word2[i];
            i++;
        }
        return p;
    }
};