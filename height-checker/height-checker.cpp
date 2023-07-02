class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> cop=heights;
        sort(cop.begin(),cop.end());
        int ans=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=cop[i]){
                ans++;
            }
        }
        return ans;
    }
};