class Solution {
public:
    bool isPalindrome(string s) {
        string convert="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z' || (s[i]>='0' && s[i]<='9')){
                convert+=s[i];
            }
            else if(s[i]>='A' && s[i]<='Z'){
                convert+=s[i]+32;
            }
        }
        string rev=convert;
        reverse(convert.begin(),convert.end());
        if(convert==rev){
            return true;
        }
        return false;
    }
};