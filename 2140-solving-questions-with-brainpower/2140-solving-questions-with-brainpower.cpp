class Solution {
public:
    long long dp(vector<vector<int>> & v,int i,vector<long long>& ch){
        if(i>=v.size()){
            return 0;
        }
        if(ch[i]!=-1){
            return ch[i];
        }
        long long take=dp(v,i+1+v[i][1],ch)+v[i][0];
        long long notake=dp(v,i+1,ch);
        return ch[i]=max(take,notake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> ch(questions.size(),-1);
        return dp(questions,0,ch);
    }
};