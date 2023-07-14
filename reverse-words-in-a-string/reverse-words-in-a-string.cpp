class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string st="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '){
                if(!st.empty()){
                    reverse(st.begin(),st.end());
                    ans+=st+' ';
                    st="";
                }
                continue;
            }
            st+=s[i];
        }
        if(!st.empty()){
            reverse(st.begin(),st.end());
            ans+=st;
        }
        if(ans.back()==' '){
            ans=ans.substr(0,ans.size()-1);
        }
        return ans;
    }
};