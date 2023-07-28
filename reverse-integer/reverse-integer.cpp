class Solution {
public:
    string rev(string s){
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            ans+=s[i];
        }
        return ans;
    }
    int reverse(int x) {
        string s=to_string(x);
        long long ans;
        if(s[0]=='-'){
            s=rev(s.substr(1));
            ans=stol(s);
            ans=0-ans;
        }
        else{
            s=rev(s);
            ans=stol(s);
        }
        if(ans>=INT_MAX || ans<=INT_MIN){
            return 0;
        }
        return ans;
    }
};