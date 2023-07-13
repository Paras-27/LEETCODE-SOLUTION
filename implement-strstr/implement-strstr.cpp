class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        int k=haystack.size();
        if(n==0 || k<n){
            return -1;
        }
        string s="";
        for(int i=0;i<n;i++){
            s+=haystack[i];
        }
        if(s==needle){
            return 0;
        }
        for(int i=n,j=0;i<k;i++,j++){
            s=s.substr(1);
            s+=haystack[i];
            if(s==needle){
                return j+1;
            }
        }
        return -1;
    }
};