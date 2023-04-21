class Solution {
public:
    const int MOD = 1e9 + 7;
    int memo[101][101][101];
    int help(int i,int n,int mini,vector<int>& group,vector<int>& profit){
        if(n<0){
            return 0;
        }
        if(i==group.size()){
            if(mini<=0)
                return 1;
            return 0;
        }
        if(memo[i][n][mini] != -1)
            return memo[i][n][mini];
        
        int take=0, notake=0;
        if(n>=group[i])
            take=help(i+1,n-group[i],max(0,mini-profit[i]),group,profit);
        
        notake=help(i+1,n,mini,group,profit);
        memo[i][n][mini] = (take + notake) % MOD;
        return memo[i][n][mini];
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int N = group.size();
        memset(memo, -1,sizeof(memo));
        return help(0,n,minProfit,group,profit);
    }
};
