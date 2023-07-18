class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=nums.size()-2;i>=0;i-=2){
            ans+=nums[i];
        }
        return ans;
    }
};