class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string curr="";
        // cout<<s.size()<<" ";
        for(int i=0;i<s.size();i++){
            // cout<<curr<<" "<<s[i]<<" "<<"\n";
            if(s[i]==' '){
                if(!curr.empty()){
                    reverse(curr.begin(),curr.end());
                    ans+=curr;
                    curr="";
                }
                ans+=s[i];
            }
            else{
                curr+=s[i];
            }
        }
        // cout<<curr;
        if(!curr.empty()){
            reverse(curr.begin(),curr.end());
            ans+=curr;
        }
        return ans;
    }
};