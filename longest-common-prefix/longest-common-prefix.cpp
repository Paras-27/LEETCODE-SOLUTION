class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool ch=false;
        int n=strs.size();
        string ans="";
        for(int i=0;i<strs[0].size();i++){
            for(int j=0;j<n-1;j++){
                // cout<<strs[j][i]<<" "<<strs[j+1][i]<<" ";
                if(i>=strs[j+1].size() || strs[j][i]!=strs[j+1][i]){
                    ch=true;
                    break;
                }
            }
            if(ch){
                break;
            }
            else{
                ans+=strs[0][i];
            }
        }
        return ans;
    }
};