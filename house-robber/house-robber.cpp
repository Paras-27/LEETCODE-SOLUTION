class Solution {
public:
    int help(vector<int>& nums,int i,vector<int> &dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int rob=help(nums,i+2,dp)+nums[i];
        int notrob=help(nums,i+1,dp);
        return dp[i]=max(rob,notrob);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return help(nums,0,dp);
    }
};