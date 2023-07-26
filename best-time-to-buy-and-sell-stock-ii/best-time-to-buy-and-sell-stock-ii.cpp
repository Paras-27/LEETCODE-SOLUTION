class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0,sell=0,curr=0,n=prices.size()-1,ans=0;
        while(curr<n){
            while(curr<n && prices[curr+1]<prices[curr]){
                curr++;
            }
            buy=prices[curr];
            
            while(curr<n && prices[curr]<=prices[curr+1]){
                curr++;
            }
            sell=prices[curr];
            
            ans+=sell-buy;
        }
        return ans;
    }
};