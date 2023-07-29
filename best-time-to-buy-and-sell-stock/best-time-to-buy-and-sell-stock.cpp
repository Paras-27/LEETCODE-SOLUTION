class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sale=1;
        int buy=0,ans=0,curr=0;
        while(sale<prices.size()){
            if(prices[buy]>prices[sale]){
                buy=sale;
            }
            else{
                curr=prices[sale]-prices[buy];
            }
            ans=max(curr,ans);
            sale++;
        }
        return ans;
    }
};