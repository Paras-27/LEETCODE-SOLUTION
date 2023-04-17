#define for(i, n) for(int i=0; i<n; i++)

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi =INT_MIN;
        int n=candies.size();
        vector<bool> v(n);
        for(i,n){
            maxi=max(maxi,candies[i]);
        }
        for(i,n){
            if(maxi<=candies[i]+extraCandies){
                v[i]=true;
            }
            else{
                v[i]=false;
            }
        }
        return v;
    }
};